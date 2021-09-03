# Dose-Planning-Model
### This is a dose planning project for ITCS 8224 

The simulator could be constructed with both cassifier and simulator, the desired work flow should be:
```
input->classification->simulation->result
```

Desired outputs:

```
./test
img size: 28 rows x 28 cols
input image:
   0    0    0    0    0    0    0    0    0    0    1    0    0   13    0    0    0    0    0    3    9    0    3    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    4    4    0    4    0    2   11    0    1   11    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    8    0    1    5    0    2    9    0   21    0    0   16    6    3    0   10    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    1    9    0    9    0   17    0    0    4    3    0    1    7    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0   18    2    6   17    0   78  190   85   95   70   73   21    5    8    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    1    1  255  255  244  255  254  255  138   13    0   11    0    0    0    0 
   0    0    0    0    0    0    0    0    0   16   69   64    0   13  255  228  252  250  246  255  254  230   65    1    0    0    0    0 
   0    0    0    0    0    0    0    0    9  130  254  242   75   11  145  255  255  245  255  249  255  255   50    1    0    0    0    0 
   0    7    0    2    1    0    0   12  142  255  245  248  154    0   72  204  251  253  250  255  251  233  227    0    0    0    0    0 
   6    0    0   11    4    0    3  143  244  255  251  255  184   30    0   11  173  241  145  184  255  255  236   79    0    0    6    0 
   0   10    4    7    0   21  122  255  255  254  255  255  255   68    3    0    7   63    8   21  196  246  255  148    3    0    8    0 
   8   15    0    0    9   79  255  248  241  255  244  253  203   32    7    7    0    3    0   10   43  248  254  194   33    1    0    0 
   0    0    3    0    0   79  255  246  255  255  247  242   39    5    0    0    8    0    0    3   39  242  255  255   74    7    0    0 
  20   12    0    0   31  234  252  255  255  250  255  148    0   10    3    5    0    0    1    2  209  249  252  236   89   12    0    6 
   0    0    0    0    0  255  239  255  247  240  175   29    8    0    0    6    1    6    0   15  187  251  255  255   58    2    0    8 
   7    0    8   10    0  251  255  254  254  214    7    0    0    0   12    0    0   37  238  233  255  255  239  158   16    0    4    5 
   7    0    8    0    1  246  251  255  252  210    0   11    0   12    3   96  143  211  255  253  255  243  249   51    0    0    0    0 
   0    5    0    0    7  255  253  247  255  221   57   32   62  185  224  245  251  255  238  234  255  255   58   27    0    0    0    0 
   0    0    0   19    4  153  242  255  249  248  247  255  251  253  251  245  255  228  253  255  247  191   36    0    0    0    0    0 
   3    6    2    0    0   78  255  233  255  255  255  254  245  248  252  249  255  249  255  243  194   20    3    0    0    0    0    0 
   0    0    5    0    8   30  219  255  245  244  248  249  255  255  252  255  239  255  210   77    0    1    9    2    0    0    0    0 
   2    0    4    9   14    0   35  224  255  255  246  255  255  251  245  255  246  249   52   14   18    0    0   14    0    0    0    0 
   7    5    0    0    0   16    0   56  203  242  255  253  242  254  255  180  111    0   16    0    0   34    0    0    0    0    0    0 
   0    0    0    6    5    0   10    0   42  120  240  255  172   71   90   24    1    1    0   13    6    0    6    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
classification result:
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0  100    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0  200  200  200  200  200  200  100    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0  200  200  200  200  200  200  200  200    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0  100  200  200    0    0  100  200  200  200  200  200  200  200    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0  100  200  200  200  100    0    0  200  200  200  200  200  200  200  200    0    0    0    0    0 
   0    0    0    0    0    0    0  100  200  200  200  200  100    0    0    0  100  200  100  100  200  200  200    0    0    0    0    0 
   0    0    0    0    0    0  100  200  200  200  200  200  200    0    0    0    0    0    0    0  100  200  200  100    0    0    0    0 
   0    0    0    0    0    0  200  200  200  200  200  200  200    0    0    0    0    0    0    0    0  200  200  100    0    0    0    0 
   0    0    0    0    0    0  200  200  200  200  200  200    0    0    0    0    0    0    0    0    0  200  200  200    0    0    0    0 
   0    0    0    0    0  200  200  200  200  200  200  100    0    0    0    0    0    0    0    0  200  200  200  200    0    0    0    0 
   0    0    0    0    0  200  200  200  200  200  100    0    0    0    0    0    0    0    0    0  100  200  200  200    0    0    0    0 
   0    0    0    0    0  200  200  200  200  200    0    0    0    0    0    0    0    0  200  200  200  200  200  100    0    0    0    0 
   0    0    0    0    0  200  200  200  200  200    0    0    0    0    0    0  100  200  200  200  200  200  200    0    0    0    0    0 
   0    0    0    0    0  200  200  200  200  200    0    0    0  100  200  200  200  200  200  200  200  200    0    0    0    0    0    0 
   0    0    0    0    0  100  200  200  200  200  200  200  200  200  200  200  200  200  200  200  200  100    0    0    0    0    0    0 
   0    0    0    0    0    0  200  200  200  200  200  200  200  200  200  200  200  200  200  200  100    0    0    0    0    0    0    0 
   0    0    0    0    0    0  200  200  200  200  200  200  200  200  200  200  200  200  200    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0  200  200  200  200  200  200  200  200  200  200  200    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0  200  200  200  200  200  200  200  100  100    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0  100  200  200  100    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
pred image:
 255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  255    0  255    0  255    0  255    0   55    0   55    0   55    0   55    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  255    0  155    0   55    0  155    0  255    0   55    0   55    0   55    0   55    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  155    0   55    0   55    0   55    0  255    0  255    0  255    0  155    0   55    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0   55    0   55    0   55    0  255    0  255    0  255    0  255    0  255    0   55    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0   55    0   55    0  155    0  255    0  255    0  255    0  255    0  155    0   55    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0   55    0   55    0  255    0  255    0  255    0  155    0   55    0   55    0   55    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0   55    0   55    0   55    0   55    0   55    0   55    0   55    0   55    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0   55    0   55    0   55    0   55    0   55    0   55    0   55    0  255    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  255    0   55    0   55    0   55    0   55    0  155    0  255    0  255    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
 255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0  255    0 
   0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0 
```
