#include <iostream>
#include <fstream>
#include <cstring>

extern "C"
{
#include <memlog.h>
#include <sys/time.h>
#include <sys/resource.h>
}

int main()
{
    // configuração do memlog
    std::string logdir = "run.log";
    std::ofstream logfile(logdir);
    logfile.close();

    char *logdir_name = new char[logdir.length() + 1];
    std::strcpy(logdir_name, logdir.c_str());

    iniciaMemLog(logdir_name);
    ativaMemLog();

    // declarações da coisa do tempo
    struct rusage usage;
    struct timeval start_user, end_user, start_system, end_system;

    // start reading u_time
    getrusage(RUSAGE_SELF, &usage);
    start_user = usage.ru_utime;
    start_system = usage.ru_stime;

    // ---------------------------------------------------------------------


    int n = 1000; 
    int arr[n];
    for (int i = 0; i < n / 2; i++)
    {
        arr[i] = i;
        escreveMemLog((long int)arr[i], sizeof(long int), 0);   // registra no gráfico '0' que algo no arr[] foi escrito 

        arr[n - i] = arr[i];
        // leMemLog((long int)(&(arr[i])), sizeof(long int), 0);   // registra no gráfico '0' que arr[i] foi acessado
    }



    // ---------------------------------------------------------------------

    // end reading u_time
    getrusage(RUSAGE_SELF, &usage);
    end_user = usage.ru_utime;
    end_system = usage.ru_stime;

    // tv_sec: seconds; tv_usec: microseconds
    // ru_utime: total amount of time spent executing in usermode,
    // expressed in a timeval structure (seconds plus microseconds)
    float utime = (end_user.tv_sec - start_user.tv_sec) + 1e-6 * (end_user.tv_usec - start_user.tv_usec);
    float stime = (end_system.tv_sec - start_system.tv_sec) + 1e-6 * (end_system.tv_usec - start_system.tv_usec);
    
    std::cout << std::fixed << "tempo total: " << utime + stime << std::endl;
}
