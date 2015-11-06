@echo off
call vcvarsall

cd src
midl /app_config Hello.idl

pause