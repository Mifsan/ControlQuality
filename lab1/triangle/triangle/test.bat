set PROGRAM="%~1"

rem test with an empty list of arguments
%PROGRAM%
if %ERRORLEVEL% EQU '0' goto err

rem test with a lot of arguments
%PROGRAM% 6 7 8 9 10 3
if %ERRORLEVEL% EQU '0' goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1