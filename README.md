# sortChrPos
This program is used to sort lines according to chromosome and position in a file like bed file in DNA sequencing data analysis. The position will be decide by chromsome first, position (second column) secondly and all other columns (combined as a string) last. So "chr1 1 1111" will be placed before "chr 1 2". I sort the file in this order in case you input a vcf file. If you want to sort the bed file according to chromosome, start and end position, you can use [combineRegion](https://github.com/peng-gang/combineRegion). 

## usage
First download the source code and and compile with g++. The simplest way to compile is

g++ *.cpp -o sortChrPos

After compiling, you can type the following command to sort the file

sortChrPos inputfile outputfile

## Example file
Before sorting:

chr1	100	200  
chr20	200	300  
chr1	500	600  
chr1	300	600  
chrX	200	500  
chr20	50	500  
MT	150	300  
chr1	700	1000  
chr1	60	900  
chrX	100	1000  
MT	100	130

After sorting:

chr1	60	900  
chr1	100	200  
chr1	300	600  
chr1	500	600  
chr1	700	1000  
chr20	50	500  
chr20	200	300  
chrX	100	1000  
chrX	200	500  
MT	100	130  
MT	150	300


If you have any questions, please email me: michael dot gang dot peng AT gmail dot com
