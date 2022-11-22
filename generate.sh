#!/bin/bash
rm -r ./out/*
./analisamem/bin/analisamem -i run.log -p ./out/
gnuplot ./out/*.gp