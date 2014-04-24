Assignment-2-
=============

This project has client server program using RPC (SUN RPC using C).



The server supports FileWrite and FileRead in chunks of 64KB.


On a FileWrite() call, the server first creates a directory with the name of the file at a specified location.


This location will be passed as a parameter to the server.


For each chunk, the server creates a file with name chunk<chunkNum> in the above directory and writes


the 64KB data in this particular file. Once done, the server completes the call to FileWrite.


On a FileRead() call, the server determines the chunk number. Reads the appropriate chunk file and


returns the data to the client.


To run the Program


    bash Client/run.sh <Filename> <IP of server> <Port of rmiregistry>


    bash Server/run.sh  <Port of rmiregistry>


