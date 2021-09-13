
REM
echo "Running \m"
g++ -c -o main.o test.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"
cls
echo "Compiling Graphic"
g++ -o main.exe  main.o -L\"C:\mingw64\x86_64-w64-mingw32\lib -lopengl32 -lglu32 -lfreeglut
cls
echo "App Running"
main