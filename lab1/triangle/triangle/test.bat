set PROGRAM="%~1"

rem test with an empty list of arguments
%PROGRAM%
if %ERRORLEVEL% EQU '0' goto err

rem test with a text in third argument
%PROGRAM% 1 2 c
if %ERRORLEVEL% EQU '0' goto err

rem test with a text in second argument
%PROGRAM% 1 b 3
if %ERRORLEVEL% EQU '0' goto err

rem test with a text in first argument
%PROGRAM% a 2 3
if %ERRORLEVEL% EQU '0' goto err

rem test with a lot of arguments
%PROGRAM% 6 7 8 9 10 3
if %ERRORLEVEL% EQU '0' goto err

rem test with a argument that equal 0
%PROGRAM% 0 2 4
if %ERRORLEVEL% EQU '0' goto err

rem test with a first argument that less than 0
%PROGRAM% -3 5 4
if %ERRORLEVEL% EQU '0' goto err

rem test with a second argument that less than 0
%PROGRAM% 3 -5 4
if %ERRORLEVEL% EQU '0' goto err

rem test with a third argument that less than 0
%PROGRAM% 3 5 -4
if %ERRORLEVEL% EQU '0' goto err

rem test with arguments for equilateral triangle
%PROGRAM% 3 3 3 > "%TEMP%\output.txt"
if %ERRORLEVEL% EQU '1' goto err
fc.exe "%TEMP%\output.txt" equilateral_triangle.txt
if %ERRORLEVEL% EQU '1' goto err

rem test with arguments for isosceles triangle
%PROGRAM% 3 3 5 > "%TEMP%\output.txt"
if %ERRORLEVEL% EQU '1' goto err
fc.exe "%TEMP%\output.txt" isosceles_triangle.txt
if %ERRORLEVEL% EQU '1' goto err

rem test with arguments for not a triangle
%PROGRAM% 1 20 2 > "%TEMP%\output.txt"
if %ERRORLEVEL% EQU '1' goto err
fc.exe "%TEMP%\output.txt" not_a_triangle.txt
if %ERRORLEVEL% EQU '1' goto err

rem test with arguments for common triangle
%PROGRAM% 5 6 8 > "%TEMP%\output.txt"
if %ERRORLEVEL% EQU '1' goto err
fc.exe "%TEMP%\output.txt" common_triangle.txt
if %ERRORLEVEL% EQU '1' goto err

rem test with arguments for common triangle
%PROGRAM% 2,5 3 5 > "%TEMP%\output.txt"
if %ERRORLEVEL% EQU '1' goto err
fc.exe "%TEMP%\output.txt" common_triangle.txt
if %ERRORLEVEL% EQU '1' goto err

rem test with arguments that contain dot
%PROGRAM% 3.2 3.4 3.4 > "%TEMP%\output.txt"
if %ERRORLEVEL% EQU '1' goto err
fc.exe "%TEMP%\output.txt" isosceles_triangle.txt
if %ERRORLEVEL% EQU '1' goto err

rem test with arguments that contain comma
%PROGRAM% 3,2 3,4 3,4 > "%TEMP%\output.txt"
if %ERRORLEVEL% EQU '1' goto err
fc.exe "%TEMP%\output.txt" isosceles_triangle.txt
if %ERRORLEVEL% EQU '1' goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1