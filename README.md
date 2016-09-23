# sortChrPos
This program is used to sort lines according to chromosome and position in a file like bed file in sequencing data analysis.

## usage
First download the sorce code and and compile with g++. The similest way to compile is

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
