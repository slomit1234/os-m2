# Operating Systems Curse - Matala 2

submitters:
1. Shlomit Ashkenazi
2. Stav Avitan

*MAKEFILE*
our makefile support all, defualt and clean.
if you want to test the assingment parts seperatly you can also user: make parta/ partb/ partc
 ![image](https://user-images.githubusercontent.com/42152443/233832193-043135c2-c259-4509-898c-2938a27ad3d0.png)
above - example for make all
![image](https://user-images.githubusercontent.com/42152443/233832218-3a151942-67e3-4450-b231-d672637656c3.png)
above - example for make clean

Please make sure you have all the files needed for the makefile:
 for Part A - cmp.c, copy.c.
 for Part B - codecA.c, codecA.h, codecB.c, codecB.h, encode.c, decode.c.
 for Part C - stshell.c.
 for all - Makefile.

*Part A - cmp and copy*

in this part, we have been asked to build 2 programs:
1. copy.c - copy source file content into target file.
   flags (optional) - [-v] for printing user output (success or faild).
                      [-f] for forcing the copy (overwrite the target file).
   command (must) - ./copy [src file] [target file] [-v] [-f]
   
   
   example #1 - source = a.txt with content aba, target = b.txt with content ABA , -v = true, -f = false.
   
   ![image](https://user-images.githubusercontent.com/42152443/233831987-050251f3-233b-429f-84fc-c719758f6c78.png)
    above - a.txt
    
   ![image](https://user-images.githubusercontent.com/42152443/233832016-c1c425e1-7edc-4775-8960-2346a6bd112c.png)
   above - b.txt 
   
   ![image](https://user-images.githubusercontent.com/42152443/233832535-8af0072d-5ece-437a-8d60-3143321f45a5.png)   
   terminal command
   
   ![image](https://user-images.githubusercontent.com/42152443/233832505-73adb05d-f94c-43fb-9799-0fdd496e27c0.png)
   result
   
   example #2 - source = a.txt with content "aba", target = b.txt with content "aba\nABA" , -v = true, -f = true.
   
   ![image](https://user-images.githubusercontent.com/42152443/233832579-7681e4e2-6f35-4b44-86a7-def3e86a35bd.png)
   terminal command
   
   ![image](https://user-images.githubusercontent.com/42152443/233832600-7c215291-c9bf-45b7-b07f-8ba9b1241ffe.png)
   result
   
   example #3 - source = a.txt with content "aba", target = d.txt (doesnt exists) -v = true, -f = true.
   
   ![image](https://user-images.githubusercontent.com/42152443/233832697-9bb93f30-d327-4c9d-9dc7-4cfe9e946edb.png)
   termoinal command
   
   ![image](https://user-images.githubusercontent.com/42152443/233832726-bf00c81e-754e-4120-a9ec-3ef93124ee67.png)
   created the file
   
   ![image](https://user-images.githubusercontent.com/42152443/233832778-3f08cf9d-f183-446c-96cf-a794da3f383a.png)
   content of d.txt
   
2. cmp.c - compare 2 files.
   flags (optional) - [-v] for printing user output (success or faild).
                      [-i] for ignoring the case in comparing process.
   command (must) - ./cmp [src file] [target file] [-v] [-i]
   
   
   
