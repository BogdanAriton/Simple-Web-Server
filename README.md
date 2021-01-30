# Simple-Web-Server

Simple Server
=============

This is a simple implemenation of a web-server, using https://think-async.com/Asio/, that starts on a desierd port and accepts a directory that will exposed on that port.
To start the server simply type: 

simple_server.exe address port doc_root

The server will start and wait for requests.
  
Simple Client
=============

This is just tester client that performs a GET opearion on the server opend at port 8080 and will list the content of the index.html returned by the server.
