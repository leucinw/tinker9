namespace commit_350df099 {
const char* amber99sb_prm = R"**(
      ##############################
      ##                          ##
      ##  Force Field Definition  ##
      ##                          ##
      ##############################


forcefield              AMBER-FF99SB

vdwtype                 LENNARD-JONES
radiusrule              ARITHMETIC
radiustype              R-MIN
radiussize              RADIUS
epsilonrule             GEOMETRIC
vdw-14-scale            2.0
chg-14-scale            1.2
electric                332.0522173
dielectric              1.0


      #############################
      ##                         ##
      ##  Literature References  ##
      ##                         ##
      #############################


V. Hornak, R. Abel, A. Okur, B. Strockbine, A. Roitberg and C. Simmerling,
Comparison of Multiple Amber Force Fields and Development of Improved
Protein Backbone Parameters, PROTEINS, 65, 712-725 (2006)  [PARM99SB]

J. Wang, P. Cieplak and P. A. Kollman, "How Well Does a Restrained
Electrostatic Potential (RESP) Model Perform in Calcluating Conformational
Energies of Organic and Biological Molecules?", J. Comput. Chem., 21,
1049-1074 (2000)  [PARM99]

W. D. Cornell, P. Cieplak, C. I. Bayly, I. R. Gould, K. M. Merz, Jr.,
D. M. Ferguson, D. C. Spellmeyer, T. Fox, J. W. Caldwell and P. A. Kollman,
"A Second Generation Force Field for the Simulation of Proteins, Nucleic
Acids, and Organic Molecules", J. Am. Chem. Soc., 117, 5179-5197 (1995)
[PARM94]

G. Moyna, H. J. Williams, R. J. Nachman and A. I. Scott, "Conformation in
Solution and Dynamics of a Structurally Constrained Linear Insect Kinin
Pentapeptide Analogue", Biopolymers, 49, 403-413 (1999)  [AIB charges]

W. S. Ross and C. C. Hardin, "Ion-Induced Stabilization of the G-DNA
Quadruplex: Free Energy Perturbation Studies", J. Am. Chem. Soc.,
116, 6070-6080 (1994)  [Alkali Metal Ions]

J. Aqvist, "Ion-Water Interaction Potentials Derived from Free Energy
Perturbation Simulations", J. Phys. Chem., 94, 8021-8024 (1990)
[Alkaline Earth Ions, radii adapted for Amber combining rule]

Current parameter values are available from the Amber site, located
at http://ambermd.org/


      #############################
      ##                         ##
      ##  Atom Type Definitions  ##
      ##                         ##
      #############################


   #####################################################
   ##                                                 ##
   ##  Tinker Atom Class Numbers to Amber Atom Types  ##
   ##                                                 ##
   ##    1  CT      11  CN      21  OW      31  HO    ##
   ##    2  C       12  CK      22  OH      32  HS    ##
   ##    3  CA      13  CQ      23  OS      33  HA    ##
   ##    4  CM      14  N       24  O       34  HC    ##
   ##    5  CC      15  NA      25  O2      35  H1    ##
   ##    6  CV      16  NB      26  S       36  H2    ##
   ##    7  CW      17  NC      27  SH      37  H3    ##
   ##    8  CR      18  N*      28  P       38  HP    ##
   ##    9  CB      19  N2      29  H       39  H4    ##
   ##   10  C*      20  N3      30  HW      40  H5    ##
   ##                                                 ##
   #####################################################


atom          1   14    N     "Glycine N"                    7    14.010    3
atom          2    1    CT    "Glycine CA"                   6    12.010    4
atom          3    2    C     "Glycine C"                    6    12.010    3
atom          4   29    H     "Glycine HN"                   1     1.008    1
atom          5   24    O     "Glycine O"                    8    16.000    1
atom          6   35    H1    "Glycine HA"                   1     1.008    1
atom          7   14    N     "Alanine N"                    7    14.010    3
atom          8    1    CT    "Alanine CA"                   6    12.010    4
atom          9    2    C     "Alanine C"                    6    12.010    3
atom         10   29    H     "Alanine HN"                   1     1.008    1
atom         11   24    O     "Alanine O"                    8    16.000    1
atom         12   35    H1    "Alanine HA"                   1     1.008    1
atom         13    1    CT    "Alanine CB"                   6    12.010    4
atom         14   34    HC    "Alanine HB"                   1     1.008    1
atom         15   14    N     "Valine N"                     7    14.010    3
atom         16    1    CT    "Valine CA"                    6    12.010    4
atom         17    2    C     "Valine C"                     6    12.010    3
atom         18   29    H     "Valine HN"                    1     1.008    1
atom         19   24    O     "Valine O"                     8    16.000    1
atom         20   35    H1    "Valine HA"                    1     1.008    1
atom         21    1    CT    "Valine CB"                    6    12.010    4
atom         22   34    HC    "Valine HB"                    1     1.008    1
atom         23    1    CT    "Valine CG1"                   6    12.010    4
atom         24   34    HC    "Valine HG1"                   1     1.008    1
atom         25    1    CT    "Valine CG2"                   6    12.010    4
atom         26   34    HC    "Valine HG2"                   1     1.008    1
atom         27   14    N     "Leucine N"                    7    14.010    3
atom         28    1    CT    "Leucine CA"                   6    12.010    4
atom         29    2    C     "Leucine C"                    6    12.010    3
atom         30   29    H     "Leucine HN"                   1     1.008    1
atom         31   24    O     "Leucine O"                    8    16.000    1
atom         32   35    H1    "Leucine HA"                   1     1.008    1
atom         33    1    CT    "Leucine CB"                   6    12.010    4
atom         34   34    HC    "Leucine HB"                   1     1.008    1
atom         35    1    CT    "Leucine CG"                   6    12.010    4
atom         36   34    HC    "Leucine HG"                   1     1.008    1
atom         37    1    CT    "Leucine CD1"                  6    12.010    4
atom         38   34    HC    "Leucine HD1"                  1     1.008    1
atom         39    1    CT    "Leucine CD2"                  6    12.010    4
atom         40   34    HC    "Leucine HD2"                  1     1.008    1
atom         41   14    N     "Isoleucine N"                 7    14.010    3
atom         42    1    CT    "Isoleucine CA"                6    12.010    4
atom         43    2    C     "Isoleucine C"                 6    12.010    3
atom         44   29    H     "Isoleucine HN"                1     1.008    1
atom         45   24    O     "Isoleucine O"                 8    16.000    1
atom         46   35    H1    "Isoleucine HA"                1     1.008    1
atom         47    1    CT    "Isoleucine CB"                6    12.010    4
atom         48   34    HC    "Isoleucine HB"                1     1.008    1
atom         49    1    CT    "Isoleucine CG1"               6    12.010    4
atom         50   34    HC    "Isoleucine HG1"               1     1.008    1
atom         51    1    CT    "Isoleucine CG2"               6    12.010    4
atom         52   34    HC    "Isoleucine HG2"               1     1.008    1
atom         53    1    CT    "Isoleucine CD"                6    12.010    4
atom         54   34    HC    "Isoleucine HD"                1     1.008    1
atom         55   14    N     "Serine N"                     7    14.010    3
atom         56    1    CT    "Serine CA"                    6    12.010    4
atom         57    2    C     "Serine C"                     6    12.010    3
atom         58   29    H     "Serine HN"                    1     1.008    1
atom         59   24    O     "Serine O"                     8    16.000    1
atom         60   35    H1    "Serine HA"                    1     1.008    1
atom         61    1    CT    "Serine CB"                    6    12.010    4
atom         62   35    H1    "Serine HB"                    1     1.008    1
atom         63   22    OH    "Serine OG"                    8    16.000    2
atom         64   31    HO    "Serine HG"                    1     1.008    1
atom         65   14    N     "Threonine N"                  7    14.010    3
atom         66    1    CT    "Threonine CA"                 6    12.010    4
atom         67    2    C     "Threonine C"                  6    12.010    3
atom         68   29    H     "Threonine HN"                 1     1.008    1
atom         69   24    O     "Threonine O"                  8    16.000    1
atom         70   35    H1    "Threonine HA"                 1     1.008    1
atom         71    1    CT    "Threonine CB"                 6    12.010    4
atom         72   35    H1    "Threonine HB"                 1     1.008    1
atom         73   22    OH    "Threonine OG1"                8    16.000    2
atom         74   31    HO    "Threonine HG1"                1     1.008    1
atom         75    1    CT    "Threonine CG2"                6    12.010    4
atom         76   34    HC    "Threonine HG2"                1     1.008    1
atom         77   14    N     "Cysteine (-SH) N"             7    14.010    3
atom         78    1    CT    "Cysteine (-SH) CA"            6    12.010    4
atom         79    2    C     "Cysteine (-SH) C"             6    12.010    3
atom         80   29    H     "Cysteine (-SH) HN"            1     1.008    1
atom         81   24    O     "Cysteine (-SH) O"             8    16.000    1
atom         82   35    H1    "Cysteine (-SH) HA"            1     1.008    1
atom         83    1    CT    "Cysteine (-SH) CB"            6    12.010    4
atom         84   35    H1    "Cysteine (-SH) HB"            1     1.008    1
atom         85   27    SH    "Cysteine (-SH) SG"           16    32.060    2
atom         86   32    HS    "Cysteine (-SH) HG"            1     1.008    1
atom         87   14    N     "Cystine (-SS-) N"             7    14.010    3
atom         88    1    CT    "Cystine (-SS-) CA"            6    12.010    4
atom         89    2    C     "Cystine (-SS-) C"             6    12.010    3
atom         90   29    H     "Cystine (-SS-) HN"            1     1.008    1
atom         91   24    O     "Cystine (-SS-) O"             8    16.000    1
atom         92   35    H1    "Cystine (-SS-) HA"            1     1.008    1
atom         93    1    CT    "Cystine (-SS-) CB"            6    12.010    4
atom         94   35    H1    "Cystine (-SS-) HB"            1     1.008    1
atom         95   26    S     "Cystine (-SS-) SG"           16    32.060    2
atom         96   14    N     "Proline N"                    7    14.010    3
atom         97    1    CT    "Proline CA"                   6    12.010    4
atom         98    2    C     "Proline C"                    6    12.010    3
atom         99   24    O     "Proline O"                    8    16.000    1
atom        100   35    H1    "Proline HA"                   1     1.008    1
atom        101    1    CT    "Proline CB"                   6    12.010    4
atom        102   34    HC    "Proline HB"                   1     1.008    1
atom        103    1    CT    "Proline CG"                   6    12.010    4
atom        104   34    HC    "Proline HG"                   1     1.008    1
atom        105    1    CT    "Proline CD"                   6    12.010    4
atom        106   35    H1    "Proline HD"                   1     1.008    1
atom        107   14    N     "Phenylalanine N"              7    14.010    3
atom        108    1    CT    "Phenylalanine CA"             6    12.010    4
atom        109    2    C     "Phenylalanine C"              6    12.010    3
atom        110   29    H     "Phenylalanine HN"             1     1.008    1
atom        111   24    O     "Phenylalanine O"              8    16.000    1
atom        112   35    H1    "Phenylalanine HA"             1     1.008    1
atom        113    1    CT    "Phenylalanine CB"             6    12.010    4
atom        114   34    HC    "Phenylalanine HB"             1     1.008    1
atom        115    3    CA    "Phenylalanine CG"             6    12.010    3
atom        116    3    CA    "Phenylalanine CD"             6    12.010    3
atom        117   33    HA    "Phenylalanine HD"             1     1.008    1
atom        118    3    CA    "Phenylalanine CE"             6    12.010    3
atom        119   33    HA    "Phenylalanine HE"             1     1.008    1
atom        120    3    CA    "Phenylalanine CZ"             6    12.010    3
atom        121   33    HA    "Phenylalanine HZ"             1     1.008    1
atom        122   14    N     "Tyrosine N"                   7    14.010    3
atom        123    1    CT    "Tyrosine CA"                  6    12.010    4
atom        124    2    C     "Tyrosine C"                   6    12.010    3
atom        125   29    H     "Tyrosine HN"                  1     1.008    1
atom        126   24    O     "Tyrosine O"                   8    16.000    1
atom        127   35    H1    "Tyrosine HA"                  1     1.008    1
atom        128    1    CT    "Tyrosine CB"                  6    12.010    4
atom        129   34    HC    "Tyrosine HB"                  1     1.008    1
atom        130    3    CA    "Tyrosine CG"                  6    12.010    3
atom        131    3    CA    "Tyrosine CD"                  6    12.010    3
atom        132   33    HA    "Tyrosine HD"                  1     1.008    1
atom        133    3    CA    "Tyrosine CE"                  6    12.010    3
atom        134   33    HA    "Tyrosine HE"                  1     1.008    1
atom        135    3    CA    "Tyrosine CZ"                  6    12.010    3
atom        136   22    OH    "Tyrosine OH"                  8    16.000    2
atom        137   31    HO    "Tyrosine HH"                  1     1.008    1
atom        138   14    N     "Tryptophan N"                 7    14.010    3
atom        139    1    CT    "Tryptophan CA"                6    12.010    4
atom        140    2    C     "Tryptophan C"                 6    12.010    3
atom        141   29    H     "Tryptophan HN"                1     1.008    1
atom        142   24    O     "Tryptophan O"                 8    16.000    1
atom        143   35    H1    "Tryptophan HA"                1     1.008    1
atom        144    1    CT    "Tryptophan CB"                6    12.010    4
atom        145   34    HC    "Tryptophan HB"                1     1.008    1
atom        146   10    C*    "Tryptophan CG"                6    12.010    3
atom        147    7    CW    "Tryptophan CD1"               6    12.010    3
atom        148   39    H4    "Tryptophan HD1"               1     1.008    1
atom        149    9    CB    "Tryptophan CD2"               6    12.010    3
atom        150   15    NA    "Tryptophan NE1"               7    14.010    3
atom        151   29    H     "Tryptophan HE1"               1     1.008    1
atom        152   11    CN    "Tryptophan CE2"               6    12.010    3
atom        153    3    CA    "Tryptophan CE3"               6    12.010    3
atom        154   33    HA    "Tryptophan HE3"               1     1.008    1
atom        155    3    CA    "Tryptophan CZ2"               6    12.010    3
atom        156   33    HA    "Tryptophan HZ2"               1     1.008    1
atom        157    3    CA    "Tryptophan CZ3"               6    12.010    3
atom        158   33    HA    "Tryptophan HZ3"               1     1.008    1
atom        159    3    CA    "Tryptophan CH2"               6    12.010    3
atom        160   33    HA    "Tryptophan HH2"               1     1.008    1
atom        161   14    N     "Histidine (+) N"              7    14.010    3
atom        162    1    CT    "Histidine (+) CA"             6    12.010    4
atom        163    2    C     "Histidine (+) C"              6    12.010    3
atom        164   29    H     "Histidine (+) HN"             1     1.008    1
atom        165   24    O     "Histidine (+) O"              8    16.000    1
atom        166   35    H1    "Histidine (+) HA"             1     1.008    1
atom        167    1    CT    "Histidine (+) CB"             6    12.010    4
atom        168   34    HC    "Histidine (+) HB"             1     1.008    1
atom        169    5    CC    "Histidine (+) CG"             6    12.010    3
atom        170   15    NA    "Histidine (+) ND1"            7    14.010    3
atom        171   29    H     "Histidine (+) HD1"            1     1.008    1
atom        172    7    CW    "Histidine (+) CD2"            6    12.010    3
atom        173   39    H4    "Histidine (+) HD2"            1     1.008    1
atom        174    8    CR    "Histidine (+) CE1"            6    12.010    3
atom        175   40    H5    "Histidine (+) HE1"            1     1.008    1
atom        176   15    NA    "Histidine (+) NE2"            7    14.010    3
atom        177   29    H     "Histidine (+) HE2"            1     1.008    1
atom        178   14    N     "Histidine (HD) N"             7    14.010    3
atom        179    1    CT    "Histidine (HD) CA"            6    12.010    4
atom        180    2    C     "Histidine (HD) C"             6    12.010    3
atom        181   29    H     "Histidine (HD) HN"            1     1.008    1
atom        182   24    O     "Histidine (HD) O"             8    16.000    1
atom        183   35    H1    "Histidine (HD) HA"            1     1.008    1
atom        184    1    CT    "Histidine (HD) CB"            6    12.010    4
atom        185   34    HC    "Histidine (HD) HB"            1     1.008    1
atom        186    5    CC    "Histidine (HD) CG"            6    12.010    3
atom        187   15    NA    "Histidine (HD) ND1"           7    14.010    3
atom        188   29    H     "Histidine (HD) HD1"           1     1.008    1
atom        189    6    CV    "Histidine (HD) CD2"           6    12.010    3
atom        190   39    H4    "Histidine (HD) HD2"           1     1.008    1
atom        191    8    CR    "Histidine (HD) CE1"           6    12.010    3
atom        192   40    H5    "Histidine (HD) HE1"           1     1.008    1
atom        193   16    NB    "Histidine (HD) NE2"           7    14.010    2
atom        194   14    N     "Histidine (HE) N"             7    14.010    3
atom        195    1    CT    "Histidine (HE) CA"            6    12.010    4
atom        196    2    C     "Histidine (HE) C"             6    12.010    3
atom        197   29    H     "Histidine (HE) HN"            1     1.008    1
atom        198   24    O     "Histidine (HE) O"             8    16.000    1
atom        199   35    H1    "Histidine (HE) HA"            1     1.008    1
atom        200    1    CT    "Histidine (HE) CB"            6    12.010    4
atom        201   34    HC    "Histidine (HE) HB"            1     1.008    1
atom        202    5    CC    "Histidine (HE) CG"            6    12.010    3
atom        203   16    NB    "Histidine (HE) ND1"           7    14.010    2
atom        204    7    CW    "Histidine (HE) CD2"           6    12.010    3
atom        205   39    H4    "Histidine (HE) HD2"           1     1.008    1
atom        206    8    CR    "Histidine (HE) CE1"           6    12.010    3
atom        207   40    H5    "Histidine (HE) HE1"           1     1.008    1
atom        208   15    NA    "Histidine (HE) NE2"           7    14.010    3
atom        209   29    H     "Histidine (HE) HE2"           1     1.008    1
atom        210   14    N     "Aspartic Acid N"              7    14.010    3
atom        211    1    CT    "Aspartic Acid CA"             6    12.010    4
atom        212    2    C     "Aspartic Acid C"              6    12.010    3
atom        213   29    H     "Aspartic Acid HN"             1     1.008    1
atom        214   24    O     "Aspartic Acid O"              8    16.000    1
atom        215   35    H1    "Aspartic Acid HA"             1     1.008    1
atom        216    1    CT    "Aspartic Acid CB"             6    12.010    4
atom        217   34    HC    "Aspartic Acid HB"             1     1.008    1
atom        218    2    C     "Aspartic Acid CG"             6    12.010    3
atom        219   25    O2    "Aspartic Acid OD"             8    16.000    1
atom        220   14    N     "Asparagine N"                 7    14.010    3
atom        221    1    CT    "Asparagine CA"                6    12.010    4
atom        222    2    C     "Asparagine C"                 6    12.010    3
atom        223   29    H     "Asparagine HN"                1     1.008    1
atom        224   24    O     "Asparagine O"                 8    16.000    1
atom        225   35    H1    "Asparagine HA"                1     1.008    1
atom        226    1    CT    "Asparagine CB"                6    12.010    4
atom        227   34    HC    "Asparagine HB"                1     1.008    1
atom        228    2    C     "Asparagine CG"                6    12.010    3
atom        229   24    O     "Asparagine OD1"               8    16.000    1
atom        230   14    N     "Asparagine ND2"               7    14.010    3
atom        231   29    H     "Asparagine HD2"               1     1.008    1
atom        232   14    N     "Glutamic Acid N"              7    14.010    3
atom        233    1    CT    "Glutamic Acid CA"             6    12.010    4
atom        234    2    C     "Glutamic Acid C"              6    12.010    3
atom        235   29    H     "Glutamic Acid HN"             1     1.008    1
atom        236   24    O     "Glutamic Acid O"              8    16.000    1
atom        237   35    H1    "Glutamic Acid HA"             1     1.008    1
atom        238    1    CT    "Glutamic Acid CB"             6    12.010    4
atom        239   34    HC    "Glutamic Acid HB"             1     1.008    1
atom        240    1    CT    "Glutamic Acid CG"             6    12.010    4
atom        241   34    HC    "Glutamic Acid HG"             1     1.008    1
atom        242    2    C     "Glutamic Acid CD"             6    12.010    3
atom        243   25    O2    "Glutamic Acid OE"             8    16.000    1
atom        244   14    N     "Glutamine N"                  7    14.010    3
atom        245    1    CT    "Glutamine CA"                 6    12.010    4
atom        246    2    C     "Glutamine C"                  6    12.010    3
atom        247   29    H     "Glutamine HN"                 1     1.008    1
atom        248   24    O     "Glutamine O"                  8    16.000    1
atom        249   35    H1    "Glutamine HA"                 1     1.008    1
atom        250    1    CT    "Glutamine CB"                 6    12.010    4
atom        251   34    HC    "Glutamine HB"                 1     1.008    1
atom        252    1    CT    "Glutamine CG"                 6    12.010    4
atom        253   34    HC    "Glutamine HG"                 1     1.008    1
atom        254    2    C     "Glutamine CD"                 6    12.010    3
atom        255   24    O     "Glutamine OE1"                8    16.000    1
atom        256   14    N     "Glutamine NE2"                7    14.010    3
atom        257   29    H     "Glutamine HE2"                1     1.008    1
atom        258   14    N     "Methionine N"                 7    14.010    3
atom        259    1    CT    "Methionine CA"                6    12.010    4
atom        260    2    C     "Methionine C"                 6    12.010    3
atom        261   29    H     "Methionine HN"                1     1.008    1
atom        262   24    O     "Methionine O"                 8    16.000    1
atom        263   35    H1    "Methionine HA"                1     1.008    1
atom        264    1    CT    "Methionine CB"                6    12.010    4
atom        265   34    HC    "Methionine HB"                1     1.008    1
atom        266    1    CT    "Methionine CG"                6    12.010    4
atom        267   35    H1    "Methionine HG"                1     1.008    1
atom        268   26    S     "Methionine SD"               16    32.060    2
atom        269    1    CT    "Methionine CE"                6    12.010    4
atom        270   35    H1    "Methionine HE"                1     1.008    1
atom        271   14    N     "Lysine N"                     7    14.010    3
atom        272    1    CT    "Lysine CA"                    6    12.010    4
atom        273    2    C     "Lysine C"                     6    12.010    3
atom        274   29    H     "Lysine HN"                    1     1.008    1
atom        275   24    O     "Lysine O"                     8    16.000    1
atom        276   35    H1    "Lysine HA"                    1     1.008    1
atom        277    1    CT    "Lysine CB"                    6    12.010    4
atom        278   34    HC    "Lysine HB"                    1     1.008    1
atom        279    1    CT    "Lysine CG"                    6    12.010    4
atom        280   34    HC    "Lysine HG"                    1     1.008    1
atom        281    1    CT    "Lysine CD"                    6    12.010    4
atom        282   34    HC    "Lysine HD"                    1     1.008    1
atom        283    1    CT    "Lysine CE"                    6    12.010    4
atom        284   38    HP    "Lysine HE"                    1     1.008    1
atom        285   20    N3    "Lysine NZ"                    7    14.010    4
atom        286   29    H     "Lysine HZ"                    1     1.008    1
atom        287   14    N     "Arginine N"                   7    14.010    3
atom        288    1    CT    "Arginine CA"                  6    12.010    4
atom        289    2    C     "Arginine C"                   6    12.010    3
atom        290   29    H     "Arginine HN"                  1     1.008    1
atom        291   24    O     "Arginine O"                   8    16.000    1
atom        292   35    H1    "Arginine HA"                  1     1.008    1
atom        293    1    CT    "Arginine CB"                  6    12.010    4
atom        294   34    HC    "Arginine HB"                  1     1.008    1
atom        295    1    CT    "Arginine CG"                  6    12.010    4
atom        296   34    HC    "Arginine HG"                  1     1.008    1
atom        297    1    CT    "Arginine CD"                  6    12.010    4
atom        298   35    H1    "Arginine HD"                  1     1.008    1
atom        299   19    N2    "Arginine NE"                  7    14.010    3
atom        300   29    H     "Arginine HE"                  1     1.008    1
atom        301    3    CA    "Arginine CZ"                  6    12.010    3
atom        302   19    N2    "Arginine NH"                  7    14.010    3
atom        303   29    H     "Arginine HH"                  1     1.008    1
atom        304   14    N     "Ornithine N"                  7    14.010    3
atom        305    1    CT    "Ornithine CA"                 6    12.010    4
atom        306    2    C     "Ornithine C"                  6    12.010    3
atom        307   29    H     "Ornithine HN"                 1     1.008    1
atom        308   24    O     "Ornithine O"                  8    16.000    1
atom        309   35    H1    "Ornithine HA"                 1     1.008    1
atom        310    1    CT    "Ornithine CB"                 6    12.010    4
atom        311   34    HC    "Ornithine HB"                 1     1.008    1
atom        312    1    CT    "Ornithine CG"                 6    12.010    4
atom        313   34    HC    "Ornithine HG"                 1     1.008    1
atom        314    1    CT    "Ornithine CD"                 6    12.010    4
atom        315   38    HP    "Ornithine HD"                 1     1.008    1
atom        316   20    N3    "Ornithine NE"                 7    14.010    4
atom        317   29    H     "Ornithine HE"                 1     1.008    1
atom        318   14    N     "MethylAlanine N"              7    14.010    3
atom        319    1    CT    "MethylAlanine CA"             6    12.010    4
atom        320    2    C     "MethylAlanine C"              6    12.010    3
atom        321   29    H     "MethylAlanine HN"             1     1.008    1
atom        322   24    O     "MethylAlanine O"              8    16.000    1
atom        323    1    CT    "MethylAlanine CB"             6    12.010    4
atom        324   34    HC    "MethylAlanine HB"             1     1.008    1
atom        325   14    N     "Pyroglutamate N"              7    14.010    3
atom        326    1    CT    "Pyroglutamate CA"             6    12.010    4
atom        327    2    C     "Pyroglutamate C"              6    12.010    3
atom        328   29    H     "Pyroglutamate HN"             1     1.008    1
atom        329   24    O     "Pyroglutamate O"              8    16.000    1
atom        330   35    H1    "Pyroglutamate HA"             1     1.008    1
atom        331    1    CT    "Pyroglutamate CB"             6    12.010    4
atom        332   34    HC    "Pyroglutamate HB"             1     1.008    1
atom        333    1    CT    "Pyroglutamate CG"             6    12.010    4
atom        334   34    HC    "Pyroglutamate HG"             1     1.008    1
atom        335    2    C     "Pyroglutamate CD"             6    12.010    3
atom        336   24    O     "Pyroglutamate OE"             8    16.000    1
atom        337    2    C     "Formyl C"                     6    12.010    3
atom        338    0    H     "Formyl H"                     1     1.008    1
atom        339   24    O     "Formyl O"                     8    16.000    1
atom        340    1    CT    "Acetyl CA"                    6    12.010    4
atom        341   34    HC    "Acetyl HA"                    1     1.008    1
atom        342    2    C     "Acetyl C"                     6    12.010    3
atom        343   24    O     "Acetyl O"                     8    16.000    1
atom        344   14    N     "C-Term Amide N"               7    14.010    3
atom        345   29    H     "C-Term Amide HN"              1     1.008    1
atom        346   14    N     "N-MeAmide N"                  7    14.010    3
atom        347   29    H     "N-MeAmide HN"                 1     1.008    1
atom        348    1    CT    "N-MeAmide C"                  6    12.010    4
atom        349   35    H1    "N-MeAmide HC"                 1     1.008    1
atom        350   20    N3    "N-Term GLY N"                 7    14.010    4
atom        351    1    CT    "N-Term GLY CA"                6    12.010    4
atom        352    2    C     "N-Term GLY C"                 6    12.010    3
atom        353   29    H     "N-Term GLY HN"                1     1.008    1
atom        354   24    O     "N-Term GLY O"                 8    16.000    1
atom        355   35    H1    "N-Term GLY HA"                1     1.008    1
atom        356   20    N3    "N-Term ALA N"                 7    14.010    4
atom        357    1    CT    "N-Term ALA CA"                6    12.010    4
atom        358    2    C     "N-Term ALA C"                 6    12.010    3
atom        359   29    H     "N-Term ALA HN"                1     1.008    1
atom        360   24    O     "N-Term ALA O"                 8    16.000    1
atom        361   35    H1    "N-Term ALA HA"                1     1.008    1
atom        362   20    N3    "N-Term VAL N"                 7    14.010    4
atom        363    1    CT    "N-Term VAL CA"                6    12.010    4
atom        364    2    C     "N-Term VAL C"                 6    12.010    3
atom        365   29    H     "N-Term VAL HN"                1     1.008    1
atom        366   24    O     "N-Term VAL O"                 8    16.000    1
atom        367   35    H1    "N-Term VAL HA"                1     1.008    1
atom        368   20    N3    "N-Term LEU N"                 7    14.010    4
atom        369    1    CT    "N-Term LEU CA"                6    12.010    4
atom        370    2    C     "N-Term LEU C"                 6    12.010    3
atom        371   29    H     "N-Term LEU HN"                1     1.008    1
atom        372   24    O     "N-Term LEU O"                 8    16.000    1
atom        373   35    H1    "N-Term LEU HA"                1     1.008    1
atom        374   20    N3    "N-Term ILE N"                 7    14.010    4
atom        375    1    CT    "N-Term ILE CA"                6    12.010    4
atom        376    2    C     "N-Term ILE C"                 6    12.010    3
atom        377   29    H     "N-Term ILE HN"                1     1.008    1
atom        378   24    O     "N-Term ILE O"                 8    16.000    1
atom        379   35    H1    "N-Term ILE HA"                1     1.008    1
atom        380   20    N3    "N-Term SER N"                 7    14.010    4
atom        381    1    CT    "N-Term SER CA"                6    12.010    4
atom        382    2    C     "N-Term SER C"                 6    12.010    3
atom        383   29    H     "N-Term SER HN"                1     1.008    1
atom        384   24    O     "N-Term SER O"                 8    16.000    1
atom        385   35    H1    "N-Term SER HA"                1     1.008    1
atom        386   20    N3    "N-Term THR N"                 7    14.010    4
atom        387    1    CT    "N-Term THR CA"                6    12.010    4
atom        388    2    C     "N-Term THR C"                 6    12.010    3
atom        389   29    H     "N-Term THR HN"                1     1.008    1
atom        390   24    O     "N-Term THR O"                 8    16.000    1
atom        391   35    H1    "N-Term THR HA"                1     1.008    1
atom        392   20    N3    "N-Term CYS (-SH) N"           7    14.010    4
atom        393    1    CT    "N-Term CYS (-SH) CA"          6    12.010    4
atom        394    2    C     "N-Term CYS (-SH) C"           6    12.010    3
atom        395   29    H     "N-Term CYS (-SH) HN"          1     1.008    1
atom        396   24    O     "N-Term CYS (-SH) O"           8    16.000    1
atom        397   35    H1    "N-Term CYS (-SH) HA"          1     1.008    1
atom        398   20    N3    "N-Term CYS (-SS-) N"          7    14.010    4
atom        399    1    CT    "N-Term CYS (-SS-) CA"         6    12.010    4
atom        400    2    C     "N-Term CYS (-SS-) C"          6    12.010    3
atom        401   29    H     "N-Term CYS (-SS-) HN"         1     1.008    1
atom        402   24    O     "N-Term CYS (-SS-) O"          8    16.000    1
atom        403   35    H1    "N-Term CYS (-SS-) HA"         1     1.008    1
atom        404   20    N3    "N-Term PRO N"                 7    14.010    4
atom        405    1    CT    "N-Term PRO CA"                6    12.010    4
atom        406    2    C     "N-Term PRO C"                 6    12.010    3
atom        407   29    H     "N-Term PRO HN"                1     1.008    1
atom        408   24    O     "N-Term PRO O"                 8    16.000    1
atom        409   35    H1    "N-Term PRO HA"                1     1.008    1
atom        410    1    CT    "N-Term PRO CD"                6    12.010    4
atom        411   38    HP    "N-Term PRO HD"                1     1.008    1
atom        412   20    N3    "N-Term PHE N"                 7    14.010    4
atom        413    1    CT    "N-Term PHE CA"                6    12.010    4
atom        414    2    C     "N-Term PHE C"                 6    12.010    3
atom        415   29    H     "N-Term PHE HN"                1     1.008    1
atom        416   24    O     "N-Term PHE O"                 8    16.000    1
atom        417   35    H1    "N-Term PHE HA"                1     1.008    1
atom        418   20    N3    "N-Term TYR N"                 7    14.010    4
atom        419    1    CT    "N-Term TYR CA"                6    12.010    4
atom        420    2    C     "N-Term TYR C"                 6    12.010    3
atom        421   29    H     "N-Term TYR HN"                1     1.008    1
atom        422   24    O     "N-Term TYR O"                 8    16.000    1
atom        423   35    H1    "N-Term TYR HA"                1     1.008    1
atom        424   20    N3    "N-Term TRP N"                 7    14.010    4
atom        425    1    CT    "N-Term TRP CA"                6    12.010    4
atom        426    2    C     "N-Term TRP C"                 6    12.010    3
atom        427   29    H     "N-Term TRP HN"                1     1.008    1
atom        428   24    O     "N-Term TRP O"                 8    16.000    1
atom        429   35    H1    "N-Term TRP HA"                1     1.008    1
atom        430   20    N3    "N-Term HIS (+) N"             7    14.010    4
atom        431    1    CT    "N-Term HIS (+) CA"            6    12.010    4
atom        432    2    C     "N-Term HIS (+) C"             6    12.010    3
atom        433   29    H     "N-Term HIS (+) HN"            1     1.008    1
atom        434   24    O     "N-Term HIS (+) O"             8    16.000    1
atom        435   35    H1    "N-Term HIS (+) HA"            1     1.008    1
atom        436   20    N3    "N-Term HIS (HD) N"            7    14.010    4
atom        437    1    CT    "N-Term HIS (HD) CA"           6    12.010    4
atom        438    2    C     "N-Term HIS (HD) C"            6    12.010    3
atom        439   29    H     "N-Term HIS (HD) HN"           1     1.008    1
atom        440   24    O     "N-Term HIS (HD) O"            8    16.000    1
atom        441   35    H1    "N-Term HIS (HD) HA"           1     1.008    1
atom        442   20    N3    "N-Term HIS (HE) N"            7    14.010    4
atom        443    1    CT    "N-Term HIS (HE) CA"           6    12.010    4
atom        444    2    C     "N-Term HIS (HE) C"            6    12.010    3
atom        445   29    H     "N-Term HIS (HE) HN"           1     1.008    1
atom        446   24    O     "N-Term HIS (HE) O"            8    16.000    1
atom        447   35    H1    "N-Term HIS (HE) HA"           1     1.008    1
atom        448   20    N3    "N-Term ASP N"                 7    14.010    4
atom        449    1    CT    "N-Term ASP CA"                6    12.010    4
atom        450    2    C     "N-Term ASP C"                 6    12.010    3
atom        451   29    H     "N-Term ASP HN"                1     1.008    1
atom        452   24    O     "N-Term ASP O"                 8    16.000    1
atom        453   35    H1    "N-Term ASP HA"                1     1.008    1
atom        454   20    N3    "N-Term ASN N"                 7    14.010    4
atom        455    1    CT    "N-Term ASN CA"                6    12.010    4
atom        456    2    C     "N-Term ASN C"                 6    12.010    3
atom        457   29    H     "N-Term ASN HN"                1     1.008    1
atom        458   24    O     "N-Term ASN O"                 8    16.000    1
atom        459   35    H1    "N-Term ASN HA"                1     1.008    1
atom        460   20    N3    "N-Term GLU N"                 7    14.010    4
atom        461    1    CT    "N-Term GLU CA"                6    12.010    4
atom        462    2    C     "N-Term GLU C"                 6    12.010    3
atom        463   29    H     "N-Term GLU HN"                1     1.008    1
atom        464   24    O     "N-Term GLU O"                 8    16.000    1
atom        465   35    H1    "N-Term GLU HA"                1     1.008    1
atom        466   20    N3    "N-Term GLN N"                 7    14.010    4
atom        467    1    CT    "N-Term GLN CA"                6    12.010    4
atom        468    2    C     "N-Term GLN C"                 6    12.010    3
atom        469   29    H     "N-Term GLN HN"                1     1.008    1
atom        470   24    O     "N-Term GLN O"                 8    16.000    1
atom        471   35    H1    "N-Term GLN HA"                1     1.008    1
atom        472   20    N3    "N-Term MET N"                 7    14.010    4
atom        473    1    CT    "N-Term MET CA"                6    12.010    4
atom        474    2    C     "N-Term MET C"                 6    12.010    3
atom        475   29    H     "N-Term MET HN"                1     1.008    1
atom        476   24    O     "N-Term MET O"                 8    16.000    1
atom        477   35    H1    "N-Term MET HA"                1     1.008    1
atom        478   20    N3    "N-Term LYS N"                 7    14.010    4
atom        479    1    CT    "N-Term LYS CA"                6    12.010    4
atom        480    2    C     "N-Term LYS C"                 6    12.010    3
atom        481   29    H     "N-Term LYS HN"                1     1.008    1
atom        482   24    O     "N-Term LYS O"                 8    16.000    1
atom        483   35    H1    "N-Term LYS HA"                1     1.008    1
atom        484   20    N3    "N-Term ARG N"                 7    14.010    4
atom        485    1    CT    "N-Term ARG CA"                6    12.010    4
atom        486    2    C     "N-Term ARG C"                 6    12.010    3
atom        487   29    H     "N-Term ARG HN"                1     1.008    1
atom        488   24    O     "N-Term ARG O"                 8    16.000    1
atom        489   35    H1    "N-Term ARG HA"                1     1.008    1
atom        490   20    N3    "N-Term ORN N"                 7    14.010    4
atom        491    1    CT    "N-Term ORN CA"                6    12.010    4
atom        492    2    C     "N-Term ORN C"                 6    12.010    3
atom        493   29    H     "N-Term ORN HN"                1     1.008    1
atom        494   24    O     "N-Term ORN O"                 8    16.000    1
atom        495   35    H1    "N-Term ORN HA"                1     1.008    1
atom        496   20    N3    "N-Term AIB N"                 7    14.010    4
atom        497    1    CT    "N-Term AIB CA"                6    12.010    4
atom        498    2    C     "N-Term AIB C"                 6    12.010    3
atom        499   29    H     "N-Term AIB HN"                1     1.008    1
atom        500   24    O     "N-Term AIB O"                 8    16.000    1
atom        501   14    N     "C-Term GLY N"                 7    14.010    3
atom        502    1    CT    "C-Term GLY CA"                6    12.010    4
atom        503    2    C     "C-Term GLY C"                 6    12.010    3
atom        504   29    H     "C-Term GLY HN"                1     1.008    1
atom        505   25    O2    "C-Term GLY OXT"               8    16.000    1
atom        506   35    H1    "C-Term GLY HA"                1     1.008    1
atom        507   14    N     "C-Term ALA N"                 7    14.010    3
atom        508    1    CT    "C-Term ALA CA"                6    12.010    4
atom        509    2    C     "C-Term ALA C"                 6    12.010    3
atom        510   29    H     "C-Term ALA HN"                1     1.008    1
atom        511   25    O2    "C-Term ALA OXT"               8    16.000    1
atom        512   35    H1    "C-Term ALA HA"                1     1.008    1
atom        513   14    N     "C-Term VAL N"                 7    14.010    3
atom        514    1    CT    "C-Term VAL CA"                6    12.010    4
atom        515    2    C     "C-Term VAL C"                 6    12.010    3
atom        516   29    H     "C-Term VAL HN"                1     1.008    1
atom        517   25    O2    "C-Term VAL OXT"               8    16.000    1
atom        518   35    H1    "C-Term VAL HA"                1     1.008    1
atom        519   14    N     "C-Term LEU N"                 7    14.010    3
atom        520    1    CT    "C-Term LEU CA"                6    12.010    4
atom        521    2    C     "C-Term LEU C"                 6    12.010    3
atom        522   29    H     "C-Term LEU HN"                1     1.008    1
atom        523   25    O2    "C-Term LEU OXT"               8    16.000    1
atom        524   35    H1    "C-Term LEU HA"                1     1.008    1
atom        525   14    N     "C-Term ILE N"                 7    14.010    3
atom        526    1    CT    "C-Term ILE CA"                6    12.010    4
atom        527    2    C     "C-Term ILE C"                 6    12.010    3
atom        528   29    H     "C-Term ILE HN"                1     1.008    1
atom        529   25    O2    "C-Term ILE OXT"               8    16.000    1
atom        530   35    H1    "C-Term ILE HA"                1     1.008    1
atom        531   14    N     "C-Term SER N"                 7    14.010    3
atom        532    1    CT    "C-Term SER CA"                6    12.010    4
atom        533    2    C     "C-Term SER C"                 6    12.010    3
atom        534   29    H     "C-Term SER HN"                1     1.008    1
atom        535   25    O2    "C-Term SER OXT"               8    16.000    1
atom        536   35    H1    "C-Term SER HA"                1     1.008    1
atom        537   14    N     "C-Term THR N"                 7    14.010    3
atom        538    1    CT    "C-Term THR CA"                6    12.010    4
atom        539    2    C     "C-Term THR C"                 6    12.010    3
atom        540   29    H     "C-Term THR HN"                1     1.008    1
atom        541   25    O2    "C-Term THR OXT"               8    16.000    1
atom        542   35    H1    "C-Term THR HA"                1     1.008    1
atom        543   14    N     "C-Term CYS (-SH) N"           7    14.010    3
atom        544    1    CT    "C-Term CYS (-SH) CA"          6    12.010    4
atom        545    2    C     "C-Term CYS (-SH) C"           6    12.010    3
atom        546   29    H     "C-Term CYS (-SH) HN"          1     1.008    1
atom        547   25    O2    "C-Term CYS (-SH) OXT"         8    16.000    1
atom        548   35    H1    "C-Term CYS (-SH) HA"          1     1.008    1
atom        549   14    N     "C-Term CYS (-SS-) N"          7    14.010    3
atom        550    1    CT    "C-Term CYS (-SS-) CA"         6    12.010    4
atom        551    2    C     "C-Term CYS (-SS-) C"          6    12.010    3
atom        552   29    H     "C-Term CYS (-SS-) HN"         1     1.008    1
atom        553   25    O2    "C-Term CYS (-SS-) OXT"        8    16.000    1
atom        554   35    H1    "C-Term CYS (-SS-) HA"         1     1.008    1
atom        555   14    N     "C-Term PRO N"                 7    14.010    3
atom        556    1    CT    "C-Term PRO CA"                6    12.010    4
atom        557    2    C     "C-Term PRO C"                 6    12.010    3
atom        558   25    O2    "C-Term PRO OXT"               8    16.000    1
atom        559   35    H1    "C-Term PRO HA"                1     1.008    1
atom        560   14    N     "C-Term PHE N"                 7    14.010    3
atom        561    1    CT    "C-Term PHE CA"                6    12.010    4
atom        562    2    C     "C-Term PHE C"                 6    12.010    3
atom        563   29    H     "C-Term PHE HN"                1     1.008    1
atom        564   25    O2    "C-Term PHE OXT"               8    16.000    1
atom        565   35    H1    "C-Term PHE HA"                1     1.008    1
atom        566   14    N     "C-Term TYR N"                 7    14.010    3
atom        567    1    CT    "C-Term TYR CA"                6    12.010    4
atom        568    2    C     "C-Term TYR C"                 6    12.010    3
atom        569   29    H     "C-Term TYR HN"                1     1.008    1
atom        570   25    O2    "C-Term TYR OXT"               8    16.000    1
atom        571   35    H1    "C-Term TYR HA"                1     1.008    1
atom        572   14    N     "C-Term TRP N"                 7    14.010    3
atom        573    1    CT    "C-Term TRP CA"                6    12.010    4
atom        574    2    C     "C-Term TRP C"                 6    12.010    3
atom        575   29    H     "C-Term TRP HN"                1     1.008    1
atom        576   25    O2    "C-Term TRP OXT"               8    16.000    1
atom        577   35    H1    "C-Term TRP HA"                1     1.008    1
atom        578   14    N     "C-Term HIS (+) N"             7    14.010    3
atom        579    1    CT    "C-Term HIS (+) CA"            6    12.010    4
atom        580    2    C     "C-Term HIS (+) C"             6    12.010    3
atom        581   29    H     "C-Term HIS (+) HN"            1     1.008    1
atom        582   25    O2    "C-Term HIS (+) OXT"           8    16.000    1
atom        583   35    H1    "C-Term HIS (+) HA"            1     1.008    1
atom        584   14    N     "C-Term HIS (HD) N"            7    14.010    3
atom        585    1    CT    "C-Term HIS (HD) CA"           6    12.010    4
atom        586    2    C     "C-Term HIS (HD) C"            6    12.010    3
atom        587   29    H     "C-Term HIS (HD) HN"           1     1.008    1
atom        588   25    O2    "C-Term HIS (HD) OXT"          8    16.000    1
atom        589   35    H1    "C-Term HIS (HD) HA"           1     1.008    1
atom        590   14    N     "C-Term HIS (HE) N"            7    14.010    3
atom        591    1    CT    "C-Term HIS (HE) CA"           6    12.010    4
atom        592    2    C     "C-Term HIS (HE) C"            6    12.010    3
atom        593   29    H     "C-Term HIS (HE) HN"           1     1.008    1
atom        594   25    O2    "C-Term HIS (HE) OXT"          8    16.000    1
atom        595   35    H1    "C-Term HIS (HE) HA"           1     1.008    1
atom        596   14    N     "C-Term ASP N"                 7    14.010    3
atom        597    1    CT    "C-Term ASP CA"                6    12.010    4
atom        598    2    C     "C-Term ASP C"                 6    12.010    3
atom        599   29    H     "C-Term ASP HN"                1     1.008    1
atom        600   25    O2    "C-Term ASP OXT"               8    16.000    1
atom        601   35    H1    "C-Term ASP HA"                1     1.008    1
atom        602   14    N     "C-Term ASN N"                 7    14.010    3
atom        603    1    CT    "C-Term ASN CA"                6    12.010    4
atom        604    2    C     "C-Term ASN C"                 6    12.010    3
atom        605   29    H     "C-Term ASN HN"                1     1.008    1
atom        606   25    O2    "C-Term ASN OXT"               8    16.000    1
atom        607   35    H1    "C-Term ASN HA"                1     1.008    1
atom        608   14    N     "C-Term GLU N"                 7    14.010    3
atom        609    1    CT    "C-Term GLU CA"                6    12.010    4
atom        610    2    C     "C-Term GLU C"                 6    12.010    3
atom        611   29    H     "C-Term GLU HN"                1     1.008    1
atom        612   25    O2    "C-Term GLU OXT"               8    16.000    1
atom        613   35    H1    "C-Term GLU HA"                1     1.008    1
atom        614   14    N     "C-Term GLN N"                 7    14.010    3
atom        615    1    CT    "C-Term GLN CA"                6    12.010    4
atom        616    2    C     "C-Term GLN C"                 6    12.010    3
atom        617   29    H     "C-Term GLN HN"                1     1.008    1
atom        618   25    O2    "C-Term GLN OXT"               8    16.000    1
atom        619   35    H1    "C-Term GLN HA"                1     1.008    1
atom        620   14    N     "C-Term MET N"                 7    14.010    3
atom        621    1    CT    "C-Term MET CA"                6    12.010    4
atom        622    2    C     "C-Term MET C"                 6    12.010    3
atom        623   29    H     "C-Term MET HN"                1     1.008    1
atom        624   25    O2    "C-Term MET OXT"               8    16.000    1
atom        625   35    H1    "C-Term MET HA"                1     1.008    1
atom        626   14    N     "C-Term LYS N"                 7    14.010    3
atom        627    1    CT    "C-Term LYS CA"                6    12.010    4
atom        628    2    C     "C-Term LYS C"                 6    12.010    3
atom        629   29    H     "C-Term LYS HN"                1     1.008    1
atom        630   25    O2    "C-Term LYS OXT"               8    16.000    1
atom        631   35    H1    "C-Term LYS HA"                1     1.008    1
atom        632   14    N     "C-Term ARG N"                 7    14.010    3
atom        633    1    CT    "C-Term ARG CA"                6    12.010    4
atom        634    2    C     "C-Term ARG C"                 6    12.010    3
atom        635   29    H     "C-Term ARG HN"                1     1.008    1
atom        636   25    O2    "C-Term ARG OXT"               8    16.000    1
atom        637   35    H1    "C-Term ARG HA"                1     1.008    1
atom        638   14    N     "C-Term ORN N"                 7    14.010    3
atom        639    1    CT    "C-Term ORN CA"                6    12.010    4
atom        640    2    C     "C-Term ORN C"                 6    12.010    3
atom        641   29    H     "C-Term ORN HN"                1     1.008    1
atom        642   25    O2    "C-Term ORN OXT"               8    16.000    1
atom        643   35    H1    "C-Term ORN HA"                1     1.008    1
atom        644   14    N     "C-Term AIB N"                 7    14.010    3
atom        645    1    CT    "C-Term AIB CA"                6    12.010    4
atom        646    2    C     "C-Term AIB C"                 6    12.010    3
atom        647   29    H     "C-Term AIB HN"                1     1.008    1
atom        648   25    O2    "C-Term AIB OXT"               8    16.000    1
atom       1001   23    OS    "R-Adenosine O5'"              8    16.000    2
atom       1002    1    CT    "R-Adenosine C5'"              6    12.010    4
atom       1003   35    H1    "R-Adenosine H5'1"             1     1.008    1
atom       1004   35    H1    "R-Adenosine H5'2"             1     1.008    1
atom       1005    1    CT    "R-Adenosine C4'"              6    12.010    4
atom       1006   35    H1    "R-Adenosine H4'"              1     1.008    1
atom       1007   23    OS    "R-Adenosine O4'"              8    16.000    2
atom       1008    1    CT    "R-Adenosine C1'"              6    12.010    4
atom       1009   36    H2    "R-Adenosine H1'"              1     1.008    1
atom       1010    1    CT    "R-Adenosine C3'"              6    12.010    4
atom       1011   35    H1    "R-Adenosine H3'"              1     1.008    1
atom       1012    1    CT    "R-Adenosine C2'"              6    12.010    4
atom       1013   35    H1    "R-Adenosine H2'1"             1     1.008    1
atom       1014   22    OH    "R-Adenosine O2'"              8    16.000    2
atom       1015   31    HO    "R-Adenosine HO'2"             1     1.008    1
atom       1016   23    OS    "R-Adenosine O3'"              8    16.000    2
atom       1017   18    N*    "R-Adenosine N9"               7    14.010    3
atom       1018    9    CB    "R-Adenosine C4"               6    12.010    3
atom       1019    9    CB    "R-Adenosine C5"               6    12.010    3
atom       1020   16    NB    "R-Adenosine N7"               7    14.010    2
atom       1021   12    CK    "R-Adenosine C8"               6    12.010    3
atom       1022   17    NC    "R-Adenosine N3"               7    14.010    2
atom       1023   13    CQ    "R-Adenosine C2"               6    12.010    3
atom       1024   17    NC    "R-Adenosine N1"               7    14.010    2
atom       1025    3    CA    "R-Adenosine C6"               6    12.010    3
atom       1026   40    H5    "R-Adenosine H2"               1     1.008    1
atom       1027   19    N2    "R-Adenosine N6"               7    14.010    3
atom       1028   29    H     "R-Adenosine H61"              1     1.008    1
atom       1029   29    H     "R-Adenosine H62"              1     1.008    1
atom       1030   40    H5    "R-Adenosine H8"               1     1.008    1
atom       1031   23    OS    "R-Guanosine O5'"              8    16.000    2
atom       1032    1    CT    "R-Guanosine C5'"              6    12.010    4
atom       1033   35    H1    "R-Guanosine H5'1"             1     1.008    1
atom       1034   35    H1    "R-Guanosine H5'2"             1     1.008    1
atom       1035    1    CT    "R-Guanosine C4'"              6    12.010    4
atom       1036   35    H1    "R-Guanosine H4'"              1     1.008    1
atom       1037   23    OS    "R-Guanosine O4'"              8    16.000    2
atom       1038    1    CT    "R-Guanosine C1'"              6    12.010    4
atom       1039   36    H2    "R-Guanosine H1'"              1     1.008    1
atom       1040    1    CT    "R-Guanosine C3'"              6    12.010    4
atom       1041   35    H1    "R-Guanosine H3'"              1     1.008    1
atom       1042    1    CT    "R-Guanosine C2'"              6    12.010    4
atom       1043   35    H1    "R-Guanosine H2'1"             1     1.008    1
atom       1044   22    OH    "R-Guanosine O2'"              8    16.000    2
atom       1045   31    HO    "R-Guanosine HO'2"             1     1.008    1
atom       1046   23    OS    "R-Guanosine O3'"              8    16.000    2
atom       1047   18    N*    "R-Guanosine N9"               7    14.010    3
atom       1048    9    CB    "R-Guanosine C4"               6    12.010    3
atom       1049    9    CB    "R-Guanosine C5"               6    12.010    3
atom       1050   16    NB    "R-Guanosine N7"               7    14.010    2
atom       1051   12    CK    "R-Guanosine C8"               6    12.010    3
atom       1052   17    NC    "R-Guanosine N3"               7    14.010    2
atom       1053    3    CA    "R-Guanosine C2"               6    12.010    3
atom       1054   15    NA    "R-Guanosine N1"               7    14.010    3
atom       1055    2    C     "R-Guanosine C6"               6    12.010    3
atom       1056   29    H     "R-Guanosine H1"               1     1.008    1
atom       1057   19    N2    "R-Guanosine N2"               7    14.010    3
atom       1058   29    H     "R-Guanosine H21"              1     1.008    1
atom       1059   29    H     "R-Guanosine H22"              1     1.008    1
atom       1060   24    O     "R-Guanosine O6"               8    16.000    1
atom       1061   40    H5    "R-Guanosine H8"               1     1.008    1
atom       1062   23    OS    "R-Cytosine O5'"               8    16.000    2
atom       1063    1    CT    "R-Cytosine C5'"               6    12.010    4
atom       1064   35    H1    "R-Cytosine H5'1"              1     1.008    1
atom       1065   35    H1    "R-Cytosine H5'2"              1     1.008    1
atom       1066    1    CT    "R-Cytosine C4'"               6    12.010    4
atom       1067   35    H1    "R-Cytosine H4'"               1     1.008    1
atom       1068   23    OS    "R-Cytosine O4'"               8    16.000    2
atom       1069    1    CT    "R-Cytosine C1'"               6    12.010    4
atom       1070   36    H2    "R-Cytosine H1'"               1     1.008    1
atom       1071    1    CT    "R-Cytosine C3'"               6    12.010    4
atom       1072   35    H1    "R-Cytosine H3'"               1     1.008    1
atom       1073    1    CT    "R-Cytosine C2'"               6    12.010    4
atom       1074   35    H1    "R-Cytosine H2'1"              1     1.008    1
atom       1075   22    OH    "R-Cytosine O2'"               8    16.000    2
atom       1076   31    HO    "R-Cytosine HO'2"              1     1.008    1
atom       1077   23    OS    "R-Cytosine O3'"               8    16.000    2
atom       1078   18    N*    "R-Cytosine N1"                7    14.010    3
atom       1079    2    C     "R-Cytosine C2"                6    12.010    3
atom       1080   17    NC    "R-Cytosine N3"                7    14.010    2
atom       1081    3    CA    "R-Cytosine C4"                6    12.010    3
atom       1082    4    CM    "R-Cytosine C5"                6    12.010    3
atom       1083    4    CM    "R-Cytosine C6"                6    12.010    3
atom       1084   24    O     "R-Cytosine O2"                8    16.000    1
atom       1085   19    N2    "R-Cytosine N4"                7    14.010    3
atom       1086   29    H     "R-Cytosine H41"               1     1.008    1
atom       1087   29    H     "R-Cytosine H42"               1     1.008    1
atom       1088   33    HA    "R-Cytosine H5"                1     1.008    1
atom       1089   39    H4    "R-Cytosine H6"                1     1.008    1
atom       1090   23    OS    "R-Uracil O5'"                 8    16.000    2
atom       1091    1    CT    "R-Uracil C5'"                 6    12.010    4
atom       1092   35    H1    "R-Uracil H5'1"                1     1.008    1
atom       1093   35    H1    "R-Uracil H5'2"                1     1.008    1
atom       1094    1    CT    "R-Uracil C4'"                 6    12.010    4
atom       1095   35    H1    "R-Uracil H4'"                 1     1.008    1
atom       1096   23    OS    "R-Uracil O4'"                 8    16.000    2
atom       1097    1    CT    "R-Uracil C1'"                 6    12.010    4
atom       1098   36    H2    "R-Uracil H1'"                 1     1.008    1
atom       1099    1    CT    "R-Uracil C3'"                 6    12.010    4
atom       1100   35    H1    "R-Uracil H3'"                 1     1.008    1
atom       1101    1    CT    "R-Uracil C2'"                 6    12.010    4
atom       1102   35    H1    "R-Uracil H2'1"                1     1.008    1
atom       1103   22    OH    "R-Uracil O2'"                 8    16.000    2
atom       1104   31    HO    "R-Uracil HO'2"                1     1.008    1
atom       1105   23    OS    "R-Uracil O3'"                 8    16.000    2
atom       1106   18    N*    "R-Uracil N1"                  7    14.010    3
atom       1107    2    C     "R-Uracil C2"                  6    12.010    3
atom       1108   15    NA    "R-Uracil N3"                  7    14.010    3
atom       1109    2    C     "R-Uracil C4"                  6    12.010    3
atom       1110    4    CM    "R-Uracil C5"                  6    12.010    3
atom       1111    4    CM    "R-Uracil C6"                  6    12.010    3
atom       1112   24    O     "R-Uracil O2"                  8    16.000    1
atom       1113   29    H     "R-Uracil H3"                  1     1.008    1
atom       1114   24    O     "R-Uracil O4"                  8    16.000    1
atom       1115   33    HA    "R-Uracil H5"                  1     1.008    1
atom       1116   39    H4    "R-Uracil H6"                  1     1.008    1
atom       1117   23    OS    "D-Adenosine O5'"              8    16.000    2
atom       1118    1    CT    "D-Adenosine C5'"              6    12.010    4
atom       1119   35    H1    "D-Adenosine H5'1"             1     1.008    1
atom       1120   35    H1    "D-Adenosine H5'2"             1     1.008    1
atom       1121    1    CT    "D-Adenosine C4'"              6    12.010    4
atom       1122   35    H1    "D-Adenosine H4'"              1     1.008    1
atom       1123   23    OS    "D-Adenosine O4'"              8    16.000    2
atom       1124    1    CT    "D-Adenosine C1'"              6    12.010    4
atom       1125   36    H2    "D-Adenosine H1'"              1     1.008    1
atom       1126    1    CT    "D-Adenosine C3'"              6    12.010    4
atom       1127   35    H1    "D-Adenosine H3'"              1     1.008    1
atom       1128    1    CT    "D-Adenosine C2'"              6    12.010    4
atom       1129   34    HC    "D-Adenosine H2'1"             1     1.008    1
atom       1130   34    HC    "D-Adenosine H2'2"             1     1.008    1
atom       1131   23    OS    "D-Adenosine O3'"              8    16.000    2
atom       1132   18    N*    "D-Adenosine N9"               7    14.010    3
atom       1133    9    CB    "D-Adenosine C4"               6    12.010    3
atom       1134    9    CB    "D-Adenosine C5"               6    12.010    3
atom       1135   16    NB    "D-Adenosine N7"               7    14.010    2
atom       1136   12    CK    "D-Adenosine C8"               6    12.010    3
atom       1137   17    NC    "D-Adenosine N3"               7    14.010    2
atom       1138   13    CQ    "D-Adenosine C2"               6    12.010    3
atom       1139   17    NC    "D-Adenosine N1"               7    14.010    2
atom       1140    3    CA    "D-Adenosine C6"               6    12.000    3
atom       1141   40    H5    "D-Adenosine H2"               1     1.008    1
atom       1142   19    N2    "D-Adenosine N6"               7    14.010    3
atom       1143   29    H     "D-Adenosine H61"              1     1.008    1
atom       1144   29    H     "D-Adenosine H62"              1     1.008    1
atom       1145   40    H5    "D-Adenosine H8"               1     1.008    1
atom       1146   23    OS    "D-Guanosine O5'"              8    16.000    2
atom       1147    1    CT    "D-Guanosine C5'"              6    12.010    4
atom       1148   35    H1    "D-Guanosine H5'1"             1     1.008    1
atom       1149   35    H1    "D-Guanosine H5'2"             1     1.008    1
atom       1150    1    CT    "D-Guanosine C4'"              6    12.010    4
atom       1151   35    H1    "D-Guanosine H4'"              1     1.008    1
atom       1152   23    OS    "D-Guanosine O4'"              8    16.000    2
atom       1153    1    CT    "D-Guanosine C1'"              6    12.010    4
atom       1154   36    H2    "D-Guanosine H1'"              1     1.008    1
atom       1155    1    CT    "D-Guanosine C3'"              6    12.010    4
atom       1156   35    H1    "D-Guanosine H3'"              1     1.008    1
atom       1157    1    CT    "D-Guanosine C2'"              6    12.010    4
atom       1158   34    HC    "D-Guanosine H2'1"             1     1.008    1
atom       1159   34    HC    "D-Guanosine H2'2"             1     1.008    1
atom       1160   23    OS    "D-Guanosine O3'"              8    16.000    2
atom       1161   18    N*    "D-Guanosine N9"               7    14.010    3
atom       1162    9    CB    "D-Guanosine C4"               6    12.010    3
atom       1163    9    CB    "D-Guanosine C5"               6    12.010    3
atom       1164   16    NB    "D-Guanosine N7"               7    14.010    2
atom       1165   12    CK    "D-Guanosine C8"               6    12.010    3
atom       1166   17    NC    "D-Guanosine N3"               7    14.010    2
atom       1167    3    CA    "D-Guanosine C2"               6    12.010    3
atom       1168   15    NA    "D-Guanosine N1"               7    14.010    3
atom       1169    2    C     "D-Guanosine C6"               6    12.010    3
atom       1170   29    H     "D-Guanosine H1"               1     1.008    1
atom       1171   19    N2    "D-Guanosine N2"               7    14.010    3
atom       1172   29    H     "D-Guanosine H21"              1     1.008    1
atom       1173   29    H     "D-Guanosine H22"              1     1.008    1
atom       1174   24    O     "D-Guanosine O6"               8    16.000    1
atom       1175   40    H5    "D-Guanosine H8"               1     1.008    1
atom       1176   23    OS    "D-Cytosine O5'"               8    16.000    2
atom       1177    1    CT    "D-Cytosine C5'"               6    12.010    4
atom       1178   35    H1    "D-Cytosine H5'1"              1     1.008    1
atom       1179   35    H1    "D-Cytosine H5'2"              1     1.008    1
atom       1180    1    CT    "D-Cytosine C4'"               6    12.010    4
atom       1181   35    H1    "D-Cytosine H4'"               1     1.008    1
atom       1182   23    OS    "D-Cytosine O4'"               8    16.000    2
atom       1183    1    CT    "D-Cytosine C1'"               6    12.010    4
atom       1184   36    H2    "D-Cytosine H1'"               1     1.008    1
atom       1185    1    CT    "D-Cytosine C3'"               6    12.010    4
atom       1186   35    H1    "D-Cytosine H3'"               1     1.008    1
atom       1187    1    CT    "D-Cytosine C2'"               6    12.010    4
atom       1188   34    HC    "D-Cytosine H2'1"              1     1.008    1
atom       1189   34    HC    "D-Cytosine H2'2"              1     1.008    1
atom       1190   23    OS    "D-Cytosine O3'"               8    16.000    2
atom       1191   18    N*    "D-Cytosine N1"                7    14.010    3
atom       1192    2    C     "D-Cytosine C2"                6    12.010    3
atom       1193   17    NC    "D-Cytosine N3"                7    14.010    2
atom       1194    3    CA    "D-Cytosine C4"                6    12.010    3
atom       1195    4    CM    "D-Cytosine C5"                6    12.010    3
atom       1196    4    CM    "D-Cytosine C6"                6    12.010    3
atom       1197   24    O     "D-Cytosine O2"                8    16.000    1
atom       1198   19    N2    "D-Cytosine N4"                7    14.010    3
atom       1199   29    H     "D-Cytosine H41"               1     1.008    1
atom       1200   29    H     "D-Cytosine H42"               1     1.008    1
atom       1201   33    HA    "D-Cytosine H5"                1     1.008    1
atom       1202   39    H4    "D-Cytosine H6"                1     1.008    1
atom       1203   23    OS    "D-Thymine O5'"                8    16.000    2
atom       1204    1    CT    "D-Thymine C5'"                6    12.010    4
atom       1205   35    H1    "D-Thymine H5'1"               1     1.008    1
atom       1206   35    H1    "D-Thymine H5'2"               1     1.008    1
atom       1207    1    CT    "D-Thymine C4'"                6    12.010    4
atom       1208   35    H1    "D-Thymine H4'"                1     1.008    1
atom       1209   23    OS    "D-Thymine O4'"                8    16.000    2
atom       1210    1    CT    "D-Thymine C1'"                6    12.010    4
atom       1211   36    H2    "D-Thymine H1'"                1     1.008    1
atom       1212    1    CT    "D-Thymine C3'"                6    12.010    4
atom       1213   35    H1    "D-Thymine H3'"                1     1.008    1
atom       1214    1    CT    "D-Thymine C2'"                6    12.010    4
atom       1215   34    HC    "D-Thymine H2'1"               1     1.008    1
atom       1216   34    HC    "D-Thymine H2'2"               1     1.008    1
atom       1217   23    OS    "D-Thymine O3'"                8    16.000    2
atom       1218   18    N*    "D-Thymine N1"                 7    14.010    3
atom       1219    2    C     "D-Thymine C2"                 6    12.010    3
atom       1220   15    NA    "D-Thymine N3"                 7    14.010    3
atom       1221    2    C     "D-Thymine C4"                 6    12.010    3
atom       1222    4    CM    "D-Thymine C5"                 6    12.010    3
atom       1223    4    CM    "D-Thymine C6"                 6    12.010    3
atom       1224   24    O     "D-Thymine O2"                 8    16.000    1
atom       1225   29    H     "D-Thymine H3"                 1     1.008    1
atom       1226   24    O     "D-Thymine O4"                 8    16.000    1
atom       1227    1    CT    "D-Thymine C7"                 6    12.010    4
atom       1228   34    HC    "D-Thymine H7"                 1     1.008    1
atom       1229   39    H4    "D-Thymine H6"                 1     1.008    1
atom       1230   28    P     "R-Phosphodiester P"          15    30.970    4
atom       1231   25    O2    "R-Phosphodiester OP"          8    16.000    1
atom       1232   22    OH    "R-5'-Hydroxyl O5'"            8    16.000    2
atom       1233   31    HO    "R-5'-Hydroxyl H5T"            1     1.008    1
atom       1234   23    OS    "R-5'-Phosphate O5'"           8    16.000    2
atom       1235   28    P     "R-5'-Phosphate P"            15    30.970    4
atom       1236   25    O2    "R-5'-Phosphate OP"            8    16.000    1
atom       1237   22    OH    "R-3'-Hydroxyl O3'"            8    16.000    2
atom       1238   31    HO    "R-3'-Hydroxyl H3T"            1     1.008    1
atom       1239   23    OS    "R-3'-Phosphate O3'"           8    16.000    2
atom       1240   28    P     "R-3'-Phosphate P"            15    30.970    4
atom       1241   25    O2    "R-3'-Phosphate OP"            8    16.000    1
atom       1242   28    P     "D-Phosphodiester P"          15    30.970    4
atom       1243   25    O2    "D-Phosphodiester OP"          8    16.000    1
atom       1244   22    OH    "D-5'-Hydroxyl O5'"            8    16.000    2
atom       1245   31    HO    "D-5'-Hydroxyl H5T"            1     1.008    1
atom       1246   23    OS    "D-5'-Phosphate O5'"           8    16.000    2
atom       1247   28    P     "D-5'-Phosphate P"            15    30.970    4
atom       1248   25    O2    "D-5'-Phosphate OP"            8    16.000    1
atom       1249   22    OH    "D-3'-Hydroxyl O3'"            8    16.000    2
atom       1250   31    HO    "D-3'-Hydroxyl H3T"            1     1.008    1
atom       1251   23    OS    "D-3'-Phosphate O3'"           8    16.000    2
atom       1252   28    P     "D-3'-Phosphate P"            15    30.970    4
atom       1253   25    O2    "D-3'-Phosphate OP"            8    16.000    1
atom       2001   21    OW    "TIP3P Oxygen"                 8    16.000    2
atom       2002   30    HW    "TIP3P Hydrogen"               1     1.008    1
atom       2003   41    Li+   "Li+ Lithium Ion"              3     6.940    0
atom       2004   42    Na+   "Na+ Sodium Ion"              11    22.990    0
atom       2005   43    K+    "K+ Potassium Ion"            19    39.100    0
atom       2006   44    Rb+   "Rb+ Rubidium Ion"            37    85.470    0
atom       2007   45    Cs+   "Cs+ Cesium Ion"              55   132.910    0
atom       2008   46    Mg+   "Mg+2 Magnesium Ion"          12    24.305    0
atom       2009   47    Ca+   "Ca+2 Calcium Ion"            20    40.080    0
atom       2010   48    Zn+   "Zn+2 Zinc Ion"               30    65.400    0
atom       2011   49    Ba+   "Ba+2 Barium Ion"             56   137.330    0
atom       2012   50    Cl-   "Cl- Chloride Ion"            17    35.450    0


      ################################
      ##                            ##
      ##  Van der Waals Parameters  ##
      ##                            ##
      ################################


vdw           1               1.9080     0.1094
vdw           2               1.9080     0.0860
vdw           3               1.9080     0.0860
vdw           4               1.9080     0.0860
vdw           5               1.9080     0.0860
vdw           6               1.9080     0.0860
vdw           7               1.9080     0.0860
vdw           8               1.9080     0.0860
vdw           9               1.9080     0.0860
vdw          10               1.9080     0.0860
vdw          11               1.9080     0.0860
vdw          12               1.9080     0.0860
vdw          13               1.9080     0.0860
vdw          14               1.8240     0.1700
vdw          15               1.8240     0.1700
vdw          16               1.8240     0.1700
vdw          17               1.8240     0.1700
vdw          18               1.8240     0.1700
vdw          19               1.8240     0.1700
vdw          20               1.8750     0.1700
vdw          21               1.7683     0.1520
vdw          22               1.7210     0.2104
vdw          23               1.6837     0.1700
vdw          24               1.6612     0.2100
vdw          25               1.6612     0.2100
vdw          26               2.0000     0.2500
vdw          27               2.0000     0.2500
vdw          28               2.1000     0.2000
vdw          29               0.6000     0.0157
vdw          30               0.0000     0.0000
vdw          31               0.0000     0.0000
vdw          32               0.6000     0.0157
vdw          33               1.4590     0.0150
vdw          34               1.4870     0.0157
vdw          35               1.3870     0.0157
vdw          36               1.2870     0.0157
vdw          37               1.1870     0.0157
vdw          38               1.1000     0.0157
vdw          39               1.4090     0.0150
vdw          40               1.3590     0.0150
vdw          41               1.1370     0.0183
vdw          42               1.8680     0.00277
vdw          43               2.6580     0.000328
vdw          44               2.9560     0.00017
vdw          45               3.3950     0.0000806
vdw          46               0.7926     0.8947
vdw          47               1.7131     0.459789
vdw          48               1.1000     0.0125
vdw          49               2.1241     0.047096
vdw          50               2.4700     0.1000


      ##################################
      ##                              ##
      ##  Bond Stretching Parameters  ##
      ##                              ##
      ##################################


bond          1    1          310.00     1.5260
bond          1    2          317.00     1.5220
bond          1    3          317.00     1.5100
bond          1    4          317.00     1.5100
bond          1    5          317.00     1.5040
bond          1   10          317.00     1.4950
bond          1   14          337.00     1.4490
bond          1   18          337.00     1.4750
bond          1   19          337.00     1.4630
bond          1   20          367.00     1.4710
bond          1   22          320.00     1.4100
bond          1   23          320.00     1.4100
bond          1   26          227.00     1.8100
bond          1   27          237.00     1.8100
bond          1   34          340.00     1.0900
bond          1   35          340.00     1.0900
bond          1   36          340.00     1.0900
bond          1   37          340.00     1.0900
bond          1   38          340.00     1.0900
bond          2    3          469.00     1.4090
bond          2    4          410.00     1.4440
bond          2    9          447.00     1.4190
bond          2   14          490.00     1.3350
bond          2   15          418.00     1.3880
bond          2   17          457.00     1.3580
bond          2   18          424.00     1.3830
bond          2   24          570.00     1.2290
bond          2   25          656.00     1.2500
bond          3    3          469.00     1.4000
bond          3    4          427.00     1.4330
bond          3    9          469.00     1.4040
bond          3   11          469.00     1.4000
bond          3   15          427.00     1.3810
bond          3   17          483.00     1.3390
bond          3   19          481.00     1.3400
bond          3   22          450.00     1.3640
bond          3   33          367.00     1.0800
bond          3   39          367.00     1.0800
bond          4    4          549.00     1.3500
bond          4   18          448.00     1.3650
bond          4   33          367.00     1.0800
bond          4   39          367.00     1.0800
bond          4   40          367.00     1.0800
bond          5    6          512.00     1.3750
bond          5    7          518.00     1.3710
bond          5   15          422.00     1.3850
bond          5   16          410.00     1.3940
bond          6   16          410.00     1.3940
bond          6   39          367.00     1.0800
bond          7   10          546.00     1.3520
bond          7   15          427.00     1.3810
bond          7   39          367.00     1.0800
bond          8   15          477.00     1.3430
bond          8   16          488.00     1.3350
bond          8   40          367.00     1.0800
bond          9    9          520.00     1.3700
bond          9   10          388.00     1.4590
bond          9   11          447.00     1.4190
bond          9   16          414.00     1.3910
bond          9   17          461.00     1.3540
bond          9   18          436.00     1.3740
bond         10   34          367.00     1.0800
bond         11   15          428.00     1.3800
bond         12   16          529.00     1.3040
bond         12   18          440.00     1.3710
bond         12   40          367.00     1.0800
bond         13   17          502.00     1.3240
bond         13   40          367.00     1.0800
bond         14   29          434.00     1.0100
bond         15   29          434.00     1.0100
bond         18   29          434.00     1.0100
bond         19   29          434.00     1.0100
bond         20   29          434.00     1.0100
bond         21   30          553.00     0.9572
bond         22   28          230.00     1.6100
bond         22   31          553.00     0.9600
bond         23   28          230.00     1.6100
bond         23   31          553.00     0.9600
bond         25   28          525.00     1.4800
bond         26   26          166.00     2.0380
bond         27   32          274.00     1.3360
bond         30   30          553.00     1.5136


      ################################
      ##                            ##
      ##  Angle Bending Parameters  ##
      ##                            ##
      ################################


angle         1    1    1      40.00     109.50
angle         1    1    2      63.00     111.10
angle         1    1    3      63.00     114.00
angle         1    1    5      63.00     113.10
angle         1    1   10      63.00     115.60
angle         1    1   14      80.00     109.70
angle         1    1   18      50.00     109.50
angle         1    1   19      80.00     111.20
angle         1    1   20      80.00     111.20
angle         1    1   22      50.00     109.50
angle         1    1   23      50.00     109.50
angle         1    1   26      50.00     114.70
angle         1    1   27      50.00     108.60
angle         1    1   34      50.00     109.50
angle         1    1   35      50.00     109.50
angle         1    1   36      50.00     109.50
angle         1    1   38      50.00     109.50
angle         2    1   14      63.00     110.10
angle         2    1   20      80.00     111.20
angle         2    1   34      50.00     109.50
angle         2    1   35      50.00     109.50
angle         2    1   38      50.00     109.50
angle         3    1   34      50.00     109.50
angle         4    1   34      50.00     109.50
angle         5    1   34      50.00     109.50
angle        10    1   34      50.00     109.50
angle        14    1   35      50.00     109.50
angle        18    1   23      50.00     109.50
angle        18    1   35      50.00     109.50
angle        18    1   36      50.00     109.50
angle        19    1   35      50.00     109.50
angle        20    1   35      50.00     109.50
angle        20    1   38      50.00     109.50
angle        22    1   35      50.00     109.50
angle        23    1   35      50.00     109.50
angle        23    1   36      50.00     109.50
angle        26    1   35      50.00     109.50
angle        27    1   35      50.00     109.50
angle        34    1   34      35.00     109.50
angle        35    1   35      35.00     109.50
angle        36    1   36      35.00     109.50
angle        38    1   38      35.00     109.50
angle         1    2   14      70.00     116.60
angle         1    2   24      80.00     120.40
angle         1    2   25      70.00     117.00
angle         3    2    3      63.00     120.00
angle         4    2   15      70.00     114.10
angle         4    2   24      80.00     125.30
angle         9    2   15      70.00     111.30
angle         9    2   24      80.00     128.80
angle        14    2   24      80.00     122.90
angle        15    2   18      70.00     115.40
angle        15    2   24      80.00     120.60
angle        17    2   18      70.00     118.60
angle        17    2   24      80.00     122.50
angle        18    2   24      80.00     120.90
angle        24    2   24      80.00     126.00
angle        25    2   25      80.00     126.00
angle         1    3    3      70.00     120.00
angle         2    3    3      63.00     120.00
angle         2    3   33      50.00     120.00
angle         3    3    3      63.00     120.00
angle         3    3    9      63.00     120.00
angle         3    3   11      63.00     120.00
angle         3    3   22      70.00     120.00
angle         3    3   33      50.00     120.00
angle         3    3   39      50.00     120.00
angle         4    3   17      70.00     121.50
angle         4    3   19      70.00     120.10
angle         9    3   17      70.00     117.30
angle         9    3   19      70.00     123.50
angle         9    3   33      50.00     120.00
angle         9    3   39      50.00     120.00
angle        11    3   33      50.00     120.00
angle        15    3   17      70.00     123.30
angle        15    3   19      70.00     116.00
angle        17    3   19      70.00     119.30
angle        19    3   19      70.00     120.00
angle         1    4    2      70.00     119.70
angle         1    4    4      70.00     119.70
angle         2    4    4      63.00     120.70
angle         2    4   33      50.00     119.70
angle         2    4   39      50.00     119.70
angle         3    4    4      63.00     117.00
angle         3    4   33      50.00     123.30
angle         3    4   39      50.00     123.30
angle         4    4   18      70.00     121.20
angle         4    4   33      50.00     119.70
angle         4    4   39      50.00     119.70
angle        18    4   39      50.00     119.10
angle         1    5    6      70.00     120.00
angle         1    5    7      70.00     120.00
angle         1    5   15      70.00     120.00
angle         1    5   16      70.00     120.00
angle         6    5   15      70.00     120.00
angle         7    5   15      70.00     120.00
angle         7    5   16      70.00     120.00
angle         5    6   16      70.00     120.00
angle         5    6   39      50.00     120.00
angle        16    6   39      50.00     120.00
angle         5    7   15      70.00     120.00
angle         5    7   39      50.00     120.00
angle        10    7   15      70.00     108.70
angle        10    7   39      50.00     120.00
angle        15    7   39      50.00     120.00
angle        15    8   15      70.00     120.00
angle        15    8   16      70.00     120.00
angle        15    8   40      50.00     120.00
angle        16    8   40      50.00     120.00
angle         2    9    9      63.00     119.20
angle         2    9   16      70.00     130.00
angle         3    9    9      63.00     117.30
angle         3    9   10      63.00     134.90
angle         3    9   11      63.00     116.20
angle         3    9   16      70.00     132.40
angle         9    9   16      70.00     110.40
angle         9    9   17      70.00     127.70
angle         9    9   18      70.00     106.20
angle        10    9   11      63.00     108.80
angle        17    9   18      70.00     126.20
angle         1   10    7      70.00     125.00
angle         1   10    9      70.00     128.60
angle         7   10    9      63.00     106.40
angle         3   11    9      63.00     122.70
angle         3   11   15      70.00     132.80
angle         9   11   15      70.00     104.40
angle        16   12   18      70.00     113.90
angle        16   12   40      50.00     123.05
angle        18   12   40      50.00     123.05
angle        17   13   17      70.00     129.10
angle        17   13   40      50.00     115.45
angle         1   14    1      50.00     118.00
angle         1   14    2      50.00     121.90
angle         1   14   29      50.00     118.04
angle         2   14   29      50.00     120.00
angle        29   14   29      35.00     120.00
angle         2   15    2      70.00     126.40
angle         2   15    3      70.00     125.20
angle         2   15   29      50.00     116.80
angle         3   15   29      50.00     118.00
angle         5   15    8      70.00     120.00
angle         5   15   29      50.00     120.00
angle         7   15    8      70.00     120.00
angle         7   15   11      70.00     111.60
angle         7   15   29      50.00     120.00
angle         8   15   29      50.00     120.00
angle        11   15   29      50.00     123.10
angle         5   16    8      70.00     117.00
angle         6   16    8      70.00     117.00
angle         9   16   12      70.00     103.80
angle         2   17    3      70.00     120.50
angle         3   17    9      70.00     112.20
angle         3   17   13      70.00     118.60
angle         9   17   13      70.00     111.00
angle         1   18    2      70.00     117.60
angle         1   18    4      70.00     121.20
angle         1   18    9      70.00     125.80
angle         1   18   12      70.00     128.80
angle         2   18    4      70.00     121.60
angle         2   18   29      50.00     119.20
angle         4   18   29      50.00     121.20
angle         9   18   12      70.00     105.40
angle         9   18   29      50.00     125.80
angle        12   18   29      50.00     128.80
angle         1   19    3      50.00     123.20
angle         1   19   29      50.00     118.40
angle         3   19   29      50.00     120.00
angle        29   19   29      35.00     120.00
angle         1   20    1      50.00     109.50
angle         1   20   29      50.00     109.50
angle        29   20   29      35.00     109.50
angle        30   21   30     100.00     104.52
angle         1   22   31      55.00     108.50
angle         3   22   31      50.00     113.00
angle        28   22   31      45.00     108.50
angle         1   23    1      60.00     109.50
angle         1   23   28     100.00     120.50
angle        28   23   28     100.00     120.50
angle         1   26    1      62.00      98.90
angle         1   26   26      68.00     103.70
angle         1   27   32      43.00      96.00
angle        32   27   32      35.00      92.07
angle        22   28   23      45.00     102.60
angle        22   28   25      45.00     108.23
angle        23   28   23      45.00     102.60
angle        23   28   25     100.00     108.23
angle        25   28   25     140.00     119.90
angle        21   30   30       0.00     127.74


      #####################################
      ##                                 ##
      ##  Improper Torsional Parameters  ##
      ##                                 ##
      #####################################


imptors       1   14    2   24           10.500  180.0  2
imptors       4   15    2   24           10.500  180.0  2
imptors       9   15    2   24           10.500  180.0  2
imptors      18   15    2   24           10.500  180.0  2
imptors       1   25    2   25           10.500  180.0  2
imptors       3    3    3    1            1.100  180.0  2
imptors       3    3    3   22            1.100  180.0  2
imptors       3    3    3   33            1.100  180.0  2
imptors      11    3    3   33            1.100  180.0  2
imptors      17    4    3   19            1.100  180.0  2
imptors       3    9    3   33            1.100  180.0  2
imptors       9   17    3   19            1.100  180.0  2
imptors      15   17    3   19            1.100  180.0  2
imptors      19   19    3   19           10.500  180.0  2
imptors       4    3    4   33            1.100  180.0  2
imptors       2    4    4    1            1.100  180.0  2
imptors       2    4    4   33            1.100  180.0  2
imptors      18    4    4   39            1.100  180.0  2
imptors      15    6    5    1            1.100  180.0  2
imptors      15    7    5    1            1.100  180.0  2
imptors      16    7    5    1            1.100  180.0  2
imptors       5   16    6   39            1.100  180.0  2
imptors       5   15    7   39            1.100  180.0  2
imptors      10   15    7   39            1.100  180.0  2
imptors      15   15    8   40            1.100  180.0  2
imptors      16   15    8   40            1.100  180.0  2
imptors      15   16    8   40            1.100  180.0  2
imptors       7    9   10    1            1.100  180.0  2
imptors      16   18   12   40            1.100  180.0  2
imptors      17   17   13   40            1.100  180.0  2
imptors       2    1   14    1            1.000  180.0  2
imptors       2    1   14   29            1.000  180.0  2
imptors       2   29   14   29            1.000  180.0  2
imptors       2    2   15   29            1.000  180.0  2
imptors       2    3   15   29            1.000  180.0  2
imptors       8    7   15   29            1.000  180.0  2
imptors       5    8   15   29            1.000  180.0  2
imptors       7   11   15   29            1.000  180.0  2
imptors       4    2   18    1            1.000  180.0  2
imptors      12    9   18    1            1.000  180.0  2
imptors       1    3   19   29            1.000  180.0  2
imptors       3   29   19   29            1.000  180.0  2


      ############################
      ##                        ##
      ##  Torsional Parameters  ##
      ##                        ##
      ############################


torsion       1    1    1    1       0.200 180.0 1  0.250 180.0 2  0.180 0.0 3
torsion       1    1    1    2            0.156    0.0  3
torsion       1    1    1   14            0.156    0.0  3
torsion       1    1    1   18            0.156    0.0  3
torsion       1    1    1   19            0.156    0.0  3
torsion       1    1    1   20            0.156    0.0  3
torsion       1    1    1   22            0.156    0.0  3
torsion       1    1    1   23            0.156    0.0  3
torsion       1    1    1   26            0.156    0.0  3
torsion       1    1    1   34            0.160    0.0  3
torsion       1    1    1   35            0.156    0.0  3
torsion       1    1    1   36            0.156    0.0  3
torsion       1    1    1   38            0.156    0.0  3
torsion       2    1    1    2            0.156    0.0  3
torsion       2    1    1    3            0.156    0.0  3
torsion       2    1    1    5            0.156    0.0  3
torsion       2    1    1   10            0.156    0.0  3
torsion       2    1    1   14            0.156    0.0  3
torsion       2    1    1   20            0.156    0.0  3
torsion       2    1    1   22            0.156    0.0  3
torsion       2    1    1   26            0.156    0.0  3
torsion       2    1    1   27            0.156    0.0  3
torsion       2    1    1   34            0.156    0.0  3
torsion       2    1    1   35            0.156    0.0  3
torsion       2    1    1   38            0.156    0.0  3
torsion       3    1    1   14            0.156    0.0  3
torsion       3    1    1   20            0.156    0.0  3
torsion       3    1    1   35            0.156    0.0  3
torsion       3    1    1   38            0.156    0.0  3
torsion       5    1    1   14            0.156    0.0  3
torsion       5    1    1   20            0.156    0.0  3
torsion       5    1    1   35            0.156    0.0  3
torsion       5    1    1   38            0.156    0.0  3
torsion      10    1    1   14            0.156    0.0  3
torsion      10    1    1   20            0.156    0.0  3
torsion      10    1    1   35            0.156    0.0  3
torsion      10    1    1   38            0.156    0.0  3
torsion      14    1    1   22            0.156    0.0  3
torsion      14    1    1   26            0.156    0.0  3
torsion      14    1    1   27            0.156    0.0  3
torsion      14    1    1   34            0.156    0.0  3
torsion      14    1    1   35            0.156    0.0  3
torsion      18    1    1   22            0.156    0.0  3
torsion      18    1    1   34            0.156    0.0  3
torsion      18    1    1   35            0.156    0.0  3
torsion      19    1    1   34            0.156    0.0  3
torsion      20    1    1   22            0.156    0.0  3
torsion      20    1    1   26            0.156    0.0  3
torsion      20    1    1   27            0.156    0.0  3
torsion      20    1    1   34            0.156    0.0  3
torsion      20    1    1   35            0.156    0.0  3
torsion      22    1    1   18            0.156    0.0  3
torsion      22    1    1   22            0.144    0.0  3      1.175    0.0  2
torsion      22    1    1   23            0.144    0.0  3      1.175    0.0  2
torsion      22    1    1   34            0.156    0.0  3      0.250    0.0  1
torsion      22    1    1   35            0.156    0.0  3
torsion      22    1    1   36            0.156    0.0  3
torsion      22    1    1   38            0.156    0.0  3
torsion      23    1    1   23            0.144    0.0  3      1.175    0.0  2
torsion      23    1    1   34            0.156    0.0  3      0.250    0.0  1
torsion      23    1    1   35            0.156    0.0  3
torsion      26    1    1   34            0.156    0.0  3
torsion      26    1    1   35            0.156    0.0  3
torsion      26    1    1   38            0.156    0.0  3
torsion      27    1    1   35            0.156    0.0  3
torsion      27    1    1   38            0.156    0.0  3
torsion      34    1    1   34            0.150    0.0  3
torsion      34    1    1   35            0.156    0.0  3
torsion      34    1    1   36            0.156    0.0  3
torsion      34    1    1   38            0.156    0.0  3
torsion      35    1    1   35            0.156    0.0  3
torsion      35    1    1   36            0.156    0.0  3
torsion      35    1    1   38            0.156    0.0  3
torsion       1    1    2   14         0.200 0.0 1   0.200 0.0 2   0.400 0.0 3
torsion       1    1    2   24            0.000    0.0  2
torsion       1    1    2   25            0.000    0.0  2
torsion      14    1    2   14     0.450 180.0 1  1.580 180.0 2  0.550 180.0 3
torsion      14    1    2   24            0.000    0.0  2
torsion      14    1    2   25            0.000    0.0  2
torsion      20    1    2   14            0.000    0.0  2
torsion      20    1    2   24            0.000    0.0  2
torsion      20    1    2   25            0.000    0.0  2
torsion      34    1    2   14            0.000    0.0  2
torsion      34    1    2   24            0.800    0.0  1      0.080  180.0  3
torsion      34    1    2   25            0.000    0.0  2
torsion      35    1    2   14            0.000    0.0  2
torsion      35    1    2   24            0.800    0.0  1      0.080  180.0  3
torsion      35    1    2   25            0.000    0.0  2
torsion       1    1    3    3            0.000    0.0  2
torsion      34    1    3    3            0.000    0.0  2
torsion      34    1    4    2            0.000    0.0  3
torsion      34    1    4    4            1.150    0.0  1      0.380  180.0  3
torsion       1    1    5    6            0.000    0.0  2
torsion       1    1    5    7            0.000    0.0  2
torsion       1    1    5   15            0.000    0.0  2
torsion       1    1    5   16            0.000    0.0  2
torsion      34    1    5    6            0.000    0.0  2
torsion      34    1    5    7            0.000    0.0  2
torsion      34    1    5   15            0.000    0.0  2
torsion      34    1    5   16            0.000    0.0  2
torsion       1    1   10    7            0.000    0.0  2
torsion       1    1   10    9            0.000    0.0  2
torsion      34    1   10    7            0.000    0.0  2
torsion      34    1   10    9            0.000    0.0  2
torsion       1    1   14    1            0.000    0.0  2
torsion       1    1   14    2         2.000 0.0 1   2.000 0.0 2   0.400 0.0 3
torsion       1    1   14   29            0.000    0.0  2
torsion       2    1   14    1            0.000    0.0  2
torsion       2    1   14    2            0.270    0.0  2      0.420    0.0  3
torsion       2    1   14   29            0.000    0.0  2
torsion      35    1   14    1            0.000    0.0  2
torsion      35    1   14    2            0.000    0.0  2
torsion      35    1   14   29            0.000    0.0  2
torsion       1    1   18    2            0.000    0.0  2
torsion       1    1   18    4            0.000    0.0  2
torsion       1    1   18    9            0.000    0.0  2
torsion       1    1   18   12            0.000    0.0  2
torsion      23    1   18    2            0.000    0.0  2
torsion      23    1   18    4            0.000  180.0  2      2.500    0.0  1
torsion      23    1   18    9            0.000    0.0  2
torsion      23    1   18   12            0.000  180.0  2      2.500    0.0  1
torsion      36    1   18    2            0.000    0.0  2
torsion      36    1   18    4            0.000    0.0  2
torsion      36    1   18    9            0.000    0.0  2
torsion      36    1   18   12            0.000    0.0  2
torsion       1    1   19    3            0.000    0.0  3
torsion       1    1   19   29            0.000    0.0  3
torsion      35    1   19    3            0.000    0.0  3
torsion      35    1   19   29            0.000    0.0  3
torsion       1    1   20    1            0.156    0.0  3
torsion       1    1   20   29            0.156    0.0  3
torsion       2    1   20    1            0.156    0.0  3
torsion       2    1   20   29            0.156    0.0  3
torsion      35    1   20    1            0.156    0.0  3
torsion      35    1   20   29            0.156    0.0  3
torsion      38    1   20    1            0.156    0.0  3
torsion      38    1   20   29            0.156    0.0  3
torsion       1    1   22   31            0.025    0.0  1      0.160    0.0  3
torsion      35    1   22   31            0.167    0.0  3
torsion       1    1   23    1            0.383    0.0  3      0.100  180.0  2
torsion       1    1   23    2            0.383    0.0  3      0.800  180.0  1
torsion       1    1   23   28            0.383    0.0  3
torsion      18    1   23    1            0.383    0.0  3      0.650    0.0  2
torsion      23    1   23    1       1.350 180.0 1  0.850 180.0 2  0.100 0.0 3
torsion      35    1   23    1            0.383    0.0  3
torsion      35    1   23   28            0.383    0.0  3
torsion      36    1   23    1            0.383    0.0  3
torsion       1    1   26    1            0.333    0.0  3
torsion       1    1   26   26            0.333    0.0  3
torsion      35    1   26    1            0.333    0.0  3
torsion      35    1   26   26            0.333    0.0  3
torsion       1    1   27   32            0.250    0.0  3
torsion      35    1   27   32            0.250    0.0  3
torsion      15    2    4    1            2.175  180.0  2
torsion      15    2    4    4            2.175  180.0  2
torsion      15    2    4   33            2.175  180.0  2
torsion      24    2    4    1            2.175  180.0  2
torsion      24    2    4    4            2.175  180.0  2      0.300    0.0  3
torsion      24    2    4   33            2.175  180.0  2
torsion      15    2    9    9            3.000  180.0  2
torsion      15    2    9   16            3.000  180.0  2
torsion      24    2    9    9            3.000  180.0  2
torsion      24    2    9   16            3.000  180.0  2
torsion       1    2   14    1            2.500  180.0  2
torsion       1    2   14   29            2.500  180.0  2
torsion      24    2   14    1            2.500  180.0  2
torsion      24    2   14   29            2.000    0.0  1      2.500  180.0  2
torsion       4    2   15    2            1.350  180.0  2
torsion       4    2   15   29            1.350  180.0  2
torsion       9    2   15    3            1.350  180.0  2
torsion       9    2   15   29            1.350  180.0  2
torsion      18    2   15    2            1.350  180.0  2
torsion      18    2   15   29            1.350  180.0  2
torsion      24    2   15    2            1.350  180.0  2
torsion      24    2   15    3            1.350  180.0  2
torsion      24    2   15   29            1.350  180.0  2
torsion      18    2   17    3            4.000  180.0  2
torsion      24    2   17    3            4.000  180.0  2
torsion      15    2   18    1            1.450  180.0  2
torsion      15    2   18    4            1.450  180.0  2
torsion      17    2   18    1            1.450  180.0  2
torsion      17    2   18    4            1.450  180.0  2
torsion      24    2   18    1            1.450  180.0  2
torsion      24    2   18    4            1.450  180.0  2
torsion      24    2   22   31            1.900    0.0  1      2.300  180.0  2
torsion      24    2   23    1            1.400  180.0  1      2.700  180.0  2
torsion       1    3    3    3            3.625  180.0  2
torsion       1    3    3   33            3.625  180.0  2
torsion       3    3    3    3            3.625  180.0  2
torsion       3    3    3    9            3.625  180.0  2
torsion       3    3    3   11            3.625  180.0  2
torsion       3    3    3   22            3.625  180.0  2
torsion       3    3    3   33            3.625  180.0  2
torsion       9    3    3   33            3.625  180.0  2
torsion      11    3    3   33            3.625  180.0  2
torsion      22    3    3   33            3.625  180.0  2
torsion      33    3    3   33            3.625  180.0  2
torsion      17    3    4    4            2.550  180.0  2
torsion      17    3    4   33            2.550  180.0  2
torsion      19    3    4    4            2.550  180.0  2
torsion      19    3    4   33            2.550  180.0  2
torsion       3    3    9   10            3.500  180.0  2
torsion       3    3    9   11            3.500  180.0  2
torsion      17    3    9    9            3.500  180.0  2
torsion      17    3    9   16            3.500  180.0  2
torsion      19    3    9    9            3.500  180.0  2
torsion      19    3    9   16            3.500  180.0  2
torsion      33    3    9   10            3.500  180.0  2
torsion      33    3    9   11            3.500  180.0  2
torsion       3    3   11    9            3.625  180.0  2
torsion       3    3   11   15            3.625  180.0  2
torsion      33    3   11    9            3.625  180.0  2
torsion      33    3   11   15            3.625  180.0  2
torsion      17    3   15    2            1.500  180.0  2
torsion      17    3   15   29            1.500  180.0  2
torsion      19    3   15    2            1.500  180.0  2
torsion      19    3   15   29            1.500  180.0  2
torsion       4    3   17    2            4.800  180.0  2
torsion       9    3   17   13            4.800  180.0  2
torsion      15    3   17    9            4.800  180.0  2
torsion      19    3   17    2            4.800  180.0  2
torsion      19    3   17    9            4.800  180.0  2
torsion      19    3   17   13            4.800  180.0  2
torsion       4    3   19   29            2.400  180.0  2
torsion       9    3   19   29            2.400  180.0  2
torsion      15    3   19   29            2.400  180.0  2
torsion      17    3   19   29            2.400  180.0  2
torsion      19    3   19    1            2.400  180.0  2
torsion      19    3   19   29            2.400  180.0  2
torsion       3    3   22   31            0.900  180.0  2
torsion       1    4    4    1            1.900  180.0  1      6.650  180.0  2
torsion       1    4    4   18            6.650  180.0  2
torsion       1    4    4   39            6.650  180.0  2
torsion       2    4    4   18            6.650  180.0  2
torsion       2    4    4   39            6.650  180.0  2
torsion       3    4    4   18            6.650  180.0  2
torsion       3    4    4   39            6.650  180.0  2
torsion      33    4    4   18            6.650  180.0  2
torsion      33    4    4   39            6.650  180.0  2
torsion       4    4   18    1            1.850  180.0  2
torsion       4    4   18    2            1.850  180.0  2
torsion      39    4   18    1            1.850  180.0  2
torsion      39    4   18    2            1.850  180.0  2
torsion       1    5    6   16            5.150  180.0  2
torsion       1    5    6   39            5.150  180.0  2
torsion      15    5    6   16            5.150  180.0  2
torsion      15    5    6   39            5.150  180.0  2
torsion       1    5    7   15            5.375  180.0  2
torsion       1    5    7   39            5.375  180.0  2
torsion      15    5    7   15            5.375  180.0  2
torsion      15    5    7   39            5.375  180.0  2
torsion      16    5    7   15            5.375  180.0  2
torsion      16    5    7   39            5.375  180.0  2
torsion       1    5   15    8            1.400  180.0  2
torsion       1    5   15   29            1.400  180.0  2
torsion       6    5   15    8            1.400  180.0  2
torsion       6    5   15   29            1.400  180.0  2
torsion       7    5   15    8            1.400  180.0  2
torsion       7    5   15   29            1.400  180.0  2
torsion       1    5   16    8            2.400  180.0  2
torsion       7    5   16    8            2.400  180.0  2
torsion       5    6   16    8            2.400  180.0  2
torsion      39    6   16    8            2.400  180.0  2
torsion      15    7   10    1            6.525  180.0  2
torsion      15    7   10    9            6.525  180.0  2
torsion      39    7   10    1            6.525  180.0  2
torsion      39    7   10    9            6.525  180.0  2
torsion       5    7   15    8            1.500  180.0  2
torsion       5    7   15   29            1.500  180.0  2
torsion      10    7   15   11            1.500  180.0  2
torsion      10    7   15   29            1.500  180.0  2
torsion      39    7   15    8            1.500  180.0  2
torsion      39    7   15   11            1.500  180.0  2
torsion      39    7   15   29            1.500  180.0  2
torsion      15    8   15    5            2.325  180.0  2
torsion      15    8   15    7            2.325  180.0  2
torsion      15    8   15   29            2.325  180.0  2
torsion      16    8   15    5            2.325  180.0  2
torsion      16    8   15    7            2.325  180.0  2
torsion      16    8   15   29            2.325  180.0  2
torsion      40    8   15    5            2.325  180.0  2
torsion      40    8   15    7            2.325  180.0  2
torsion      40    8   15   29            2.325  180.0  2
torsion      15    8   16    5            5.000  180.0  2
torsion      15    8   16    6            5.000  180.0  2
torsion      40    8   16    5            5.000  180.0  2
torsion      40    8   16    6            5.000  180.0  2
torsion       2    9    9   17            5.450  180.0  2
torsion       2    9    9   18            5.450  180.0  2
torsion       3    9    9   17            5.450  180.0  2
torsion       3    9    9   18            5.450  180.0  2
torsion      16    9    9   17            5.450  180.0  2
torsion      16    9    9   18            5.450  180.0  2
torsion       3    9   10    1            1.675  180.0  2
torsion       3    9   10    7            1.675  180.0  2
torsion      11    9   10    1            1.675  180.0  2
torsion      11    9   10    7            1.675  180.0  2
torsion       3    9   11    3            3.000  180.0  2
torsion       3    9   11   15            3.000  180.0  2
torsion      10    9   11    3            3.000  180.0  2
torsion      10    9   11   15            3.000  180.0  2
torsion       2    9   16   12            2.550  180.0  2
torsion       3    9   16   12            2.550  180.0  2
torsion       9    9   16   12            2.550  180.0  2
torsion       9    9   17    3            4.150  180.0  2
torsion       9    9   17   13            4.150  180.0  2
torsion      18    9   17    3            4.150  180.0  2
torsion      18    9   17   13            4.150  180.0  2
torsion       9    9   18    1            1.650  180.0  2
torsion       9    9   18   12            1.650  180.0  2
torsion      17    9   18    1            1.650  180.0  2
torsion      17    9   18   12            1.650  180.0  2
torsion       3   11   15    7            1.525  180.0  2
torsion       3   11   15   29            1.525  180.0  2
torsion       9   11   15    7            1.525  180.0  2
torsion       9   11   15   29            1.525  180.0  2
torsion      18   12   16    9           10.000  180.0  2
torsion      40   12   16    9           10.000  180.0  2
torsion      16   12   18    1            1.700  180.0  2
torsion      16   12   18    9            1.700  180.0  2
torsion      40   12   18    1            1.700  180.0  2
torsion      40   12   18    9            1.700  180.0  2
torsion      17   13   17    3            6.800  180.0  2
torsion      17   13   17    9            6.800  180.0  2
torsion      40   13   17    3            6.800  180.0  2
torsion      40   13   17    9            6.800  180.0  2
torsion      31   22   28   23            0.250    0.0  3
torsion      31   22   28   25            0.250    0.0  3
torsion       1   23   28   22            0.250    0.0  3      1.200    0.0  2
torsion       1   23   28   23            0.250    0.0  3      1.200    0.0  2
torsion       1   23   28   25            0.250    0.0  3
torsion       1   26   26    1            3.500    0.0  2      0.600    0.0  3


      ########################################
      ##                                    ##
      ##  Atomic Partial Charge Parameters  ##
      ##                                    ##
      ########################################


charge        1              -0.4157
charge        2              -0.0252
charge        3               0.5973
charge        4               0.2719
charge        5              -0.5679
charge        6               0.0698
charge        7              -0.4157
charge        8               0.0337
charge        9               0.5973
charge       10               0.2719
charge       11              -0.5679
charge       12               0.0823
charge       13              -0.1825
charge       14               0.0603
charge       15              -0.4157
charge       16              -0.0875
charge       17               0.5973
charge       18               0.2719
charge       19              -0.5679
charge       20               0.0969
charge       21               0.2985
charge       22              -0.0297
charge       23              -0.3192
charge       24               0.0791
charge       25              -0.3192
charge       26               0.0791
charge       27              -0.4157
charge       28              -0.0518
charge       29               0.5973
charge       30               0.2719
charge       31              -0.5679
charge       32               0.0922
charge       33              -0.1102
charge       34               0.0457
charge       35               0.3531
charge       36              -0.0361
charge       37              -0.4121
charge       38               0.1000
charge       39              -0.4121
charge       40               0.1000
charge       41              -0.4157
charge       42              -0.0597
charge       43               0.5973
charge       44               0.2719
charge       45              -0.5679
charge       46               0.0869
charge       47               0.1303
charge       48               0.0187
charge       49              -0.0430
charge       50               0.0236
charge       51              -0.3204
charge       52               0.0882
charge       53              -0.0660
charge       54               0.0186
charge       55              -0.4157
charge       56              -0.0249
charge       57               0.5973
charge       58               0.2719
charge       59              -0.5679
charge       60               0.0843
charge       61               0.2117
charge       62               0.0352
charge       63              -0.6546
charge       64               0.4275
charge       65              -0.4157
charge       66              -0.0389
charge       67               0.5973
charge       68               0.2719
charge       69              -0.5679
charge       70               0.1007
charge       71               0.3654
charge       72               0.0043
charge       73              -0.6761
charge       74               0.4102
charge       75              -0.2438
charge       76               0.0642
charge       77              -0.4157
charge       78               0.0213
charge       79               0.5973
charge       80               0.2719
charge       81              -0.5679
charge       82               0.1124
charge       83              -0.1231
charge       84               0.1112
charge       85              -0.3119
charge       86               0.1933
charge       87              -0.4157
charge       88               0.0429
charge       89               0.5973
charge       90               0.2719
charge       91              -0.5679
charge       92               0.0766
charge       93              -0.0790
charge       94               0.0910
charge       95              -0.1081
charge       96              -0.2548
charge       97              -0.0266
charge       98               0.5896
charge       99              -0.5748
charge      100               0.0641
charge      101              -0.0070
charge      102               0.0253
charge      103               0.0189
charge      104               0.0213
charge      105               0.0192
charge      106               0.0391
charge      107              -0.4157
charge      108              -0.0024
charge      109               0.5973
charge      110               0.2719
charge      111              -0.5679
charge      112               0.0978
charge      113              -0.0343
charge      114               0.0295
charge      115               0.0118
charge      116              -0.1256
charge      117               0.1330
charge      118              -0.1704
charge      119               0.1430
charge      120              -0.1072
charge      121               0.1297
charge      122              -0.4157
charge      123              -0.0014
charge      124               0.5973
charge      125               0.2719
charge      126              -0.5679
charge      127               0.0876
charge      128              -0.0152
charge      129               0.0295
charge      130              -0.0011
charge      131              -0.1906
charge      132               0.1699
charge      133              -0.2341
charge      134               0.1656
charge      135               0.3226
charge      136              -0.5579
charge      137               0.3992
charge      138              -0.4157
charge      139              -0.0275
charge      140               0.5973
charge      141               0.2719
charge      142              -0.5679
charge      143               0.1123
charge      144              -0.0050
charge      145               0.0339
charge      146              -0.1415
charge      147              -0.1638
charge      148               0.2062
charge      149               0.1243
charge      150              -0.3418
charge      151               0.3412
charge      152               0.1380
charge      153              -0.2387
charge      154               0.1700
charge      155              -0.2601
charge      156               0.1572
charge      157              -0.1972
charge      158               0.1447
charge      159              -0.1134
charge      160               0.1417
charge      161              -0.3479
charge      162              -0.1354
charge      163               0.7341
charge      164               0.2747
charge      165              -0.5894
charge      166               0.1212
charge      167              -0.0414
charge      168               0.0810
charge      169              -0.0012
charge      170              -0.1513
charge      171               0.3866
charge      172              -0.1141
charge      173               0.2317
charge      174              -0.0170
charge      175               0.2681
charge      176              -0.1718
charge      177               0.3911
charge      178              -0.4157
charge      179               0.0188
charge      180               0.5973
charge      181               0.2719
charge      182              -0.5679
charge      183               0.0881
charge      184              -0.0462
charge      185               0.0402
charge      186              -0.0266
charge      187              -0.3811
charge      188               0.3649
charge      189               0.1292
charge      190               0.1147
charge      191               0.2057
charge      192               0.1392
charge      193              -0.5727
charge      194              -0.4157
charge      195              -0.0581
charge      196               0.5973
charge      197               0.2719
charge      198              -0.5679
charge      199               0.1360
charge      200              -0.0074
charge      201               0.0367
charge      202               0.1868
charge      203              -0.5432
charge      204              -0.2207
charge      205               0.1862
charge      206               0.1635
charge      207               0.1435
charge      208              -0.2795
charge      209               0.3339
charge      210              -0.5163
charge      211               0.0381
charge      212               0.5366
charge      213               0.2936
charge      214              -0.5819
charge      215               0.0880
charge      216              -0.0303
charge      217              -0.0122
charge      218               0.7994
charge      219              -0.8014
charge      220              -0.4157
charge      221               0.0143
charge      222               0.5973
charge      223               0.2719
charge      224              -0.5679
charge      225               0.1048
charge      226              -0.2041
charge      227               0.0797
charge      228               0.7130
charge      229              -0.5931
charge      230              -0.9191
charge      231               0.4196
charge      232              -0.5163
charge      233               0.0397
charge      234               0.5366
charge      235               0.2936
charge      236              -0.5819
charge      237               0.1105
charge      238               0.0560
charge      239              -0.0173
charge      240               0.0136
charge      241              -0.0425
charge      242               0.8054
charge      243              -0.8188
charge      244              -0.4157
charge      245              -0.0031
charge      246               0.5973
charge      247               0.2719
charge      248              -0.5679
charge      249               0.0850
charge      250              -0.0036
charge      251               0.0171
charge      252              -0.0645
charge      253               0.0352
charge      254               0.6951
charge      255              -0.6086
charge      256              -0.9407
charge      257               0.4251
charge      258              -0.4157
charge      259              -0.0237
charge      260               0.5973
charge      261               0.2719
charge      262              -0.5679
charge      263               0.0880
charge      264               0.0342
charge      265               0.0241
charge      266               0.0018
charge      267               0.0440
charge      268              -0.2737
charge      269              -0.0536
charge      270               0.0684
charge      271              -0.3479
charge      272              -0.2400
charge      273               0.7341
charge      274               0.2747
charge      275              -0.5894
charge      276               0.1426
charge      277              -0.0094
charge      278               0.0362
charge      279               0.0187
charge      280               0.0103
charge      281              -0.0479
charge      282               0.0621
charge      283              -0.0143
charge      284               0.1135
charge      285              -0.3854
charge      286               0.3400
charge      287              -0.3479
charge      288              -0.2637
charge      289               0.7341
charge      290               0.2747
charge      291              -0.5894
charge      292               0.1560
charge      293              -0.0007
charge      294               0.0327
charge      295               0.0390
charge      296               0.0285
charge      297               0.0486
charge      298               0.0687
charge      299              -0.5295
charge      300               0.3456
charge      301               0.8076
charge      302              -0.8627
charge      303               0.4478
charge      304              -0.3479
charge      305              -0.2400
charge      306               0.7341
charge      307               0.2747
charge      308              -0.5894
charge      309               0.1426
charge      310               0.0099
charge      311               0.0362
charge      312              -0.0279
charge      313               0.0621
charge      314              -0.0143
charge      315               0.1135
charge      316              -0.3854
charge      317               0.3400
charge      318              -0.4157
charge      319               0.1032
charge      320               0.5973
charge      321               0.2719
charge      322              -0.5679
charge      323              -0.2503
charge      324               0.0853
charge      325              -0.4157      !! Tinker
charge      326              -0.0371      !! Tinker
charge      327               0.5973      !! Tinker
charge      328               0.2719      !! Tinker
charge      329              -0.5679      !! Tinker
charge      330               0.0850      !! Tinker
charge      331              -0.0036      !! Tinker
charge      332               0.0171      !! Tinker
charge      333              -0.0645      !! Tinker
charge      334               0.0352      !! Tinker
charge      335               0.6000      !! Tinker
charge      336              -0.5700      !! Tinker
charge      337               0.5500      !! Tinker
charge      338               0.0000      !! Tinker
charge      339              -0.5500      !! Tinker
charge      340              -0.3662
charge      341               0.1123
charge      342               0.5972
charge      343              -0.5679
charge      344              -0.8400      !! Tinker
charge      345               0.4200      !! Tinker
charge      346              -0.4157
charge      347               0.2719
charge      348              -0.1490
charge      349               0.0976
charge      350               0.2943
charge      351              -0.0100
charge      352               0.6163
charge      353               0.1642
charge      354              -0.5722
charge      355               0.0895
charge      356               0.1414
charge      357               0.1281
charge      358               0.6163
charge      359               0.1997
charge      360              -0.5722
charge      361               0.0889
charge      362               0.0577
charge      363               0.0023
charge      364               0.6163
charge      365               0.2272
charge      366              -0.5722
charge      367               0.1093
charge      368               0.1010
charge      369               0.0343
charge      370               0.6123
charge      371               0.2148
charge      372              -0.5713
charge      373               0.1053
charge      374               0.0311
charge      375               0.0389
charge      376               0.6123
charge      377               0.2329
charge      378              -0.5713
charge      379               0.1031
charge      380               0.1849
charge      381               0.0684
charge      382               0.6163
charge      383               0.1898
charge      384              -0.5722
charge      385               0.0782
charge      386               0.1812
charge      387               0.0332
charge      388               0.6163
charge      389               0.1934
charge      390              -0.5722
charge      391               0.1087
charge      392               0.1325
charge      393               0.0978
charge      394               0.6123
charge      395               0.2023
charge      396              -0.5713
charge      397               0.1411
charge      398               0.2096
charge      399               0.1138
charge      400               0.6163
charge      401               0.1815
charge      402              -0.5713
charge      403               0.0922
charge      404              -0.2020
charge      405               0.1589
charge      406               0.5260
charge      407               0.3120
charge      408              -0.5000
charge      409               0.1000
charge      410              -0.0120
charge      411               0.1000
charge      412               0.1737
charge      413               0.0859
charge      414               0.6123
charge      415               0.1921
charge      416              -0.5713
charge      417               0.1041
charge      418               0.1940
charge      419               0.0766
charge      420               0.6123
charge      421               0.1873
charge      422              -0.5713
charge      423               0.0983
charge      424               0.1913
charge      425               0.0555
charge      426               0.6123
charge      427               0.1888
charge      428              -0.5713
charge      429               0.1162
charge      430               0.2560
charge      431               0.0653
charge      432               0.7214
charge      433               0.1704
charge      434              -0.6013
charge      435               0.1047
charge      436               0.1542
charge      437               0.1126
charge      438               0.6123
charge      439               0.1963
charge      440              -0.5713
charge      441               0.0958
charge      442               0.1472
charge      443               0.0325
charge      444               0.6123
charge      445               0.2016
charge      446              -0.5713
charge      447               0.1380
charge      448               0.0782
charge      449               0.0326
charge      450               0.5621
charge      451               0.2200
charge      452              -0.5889
charge      453               0.1141
charge      454               0.1801
charge      455               0.0811
charge      456               0.6163
charge      457               0.1921
charge      458              -0.5722
charge      459               0.1231
charge      460               0.0017
charge      461               0.0698
charge      462               0.5621
charge      463               0.2391
charge      464              -0.5889
charge      465               0.1202
charge      466               0.1493
charge      467               0.0769
charge      468               0.6123
charge      469               0.1996
charge      470              -0.5713
charge      471               0.1015
charge      472               0.1592
charge      473               0.0429
charge      474               0.6123
charge      475               0.1984
charge      476              -0.5713
charge      477               0.1116
charge      478               0.0966
charge      479              -0.0101
charge      480               0.7214
charge      481               0.2165
charge      482              -0.6013
charge      483               0.1180
charge      484               0.1305
charge      485              -0.0359
charge      486               0.7214
charge      487               0.2083
charge      488              -0.6013
charge      489               0.1242
charge      490               0.0966
charge      491              -0.0101
charge      492               0.7214
charge      493               0.2165
charge      494              -0.6013
charge      495               0.1180
charge      496               0.1000      !! Tinker
charge      497               0.2447      !! Tinker
charge      498               0.6163      !! Tinker
charge      499               0.2000      !! Tinker
charge      500              -0.5722      !! Tinker
charge      501              -0.3821
charge      502              -0.2493
charge      503               0.7231
charge      504               0.2681
charge      505              -0.7855
charge      506               0.1056
charge      507              -0.3821
charge      508              -0.1532
charge      509               0.7731
charge      510               0.2681
charge      511              -0.8055
charge      512               0.1067
charge      513              -0.3821
charge      514              -0.3352
charge      515               0.8350
charge      516               0.2681
charge      517              -0.8173
charge      518               0.1438
charge      519              -0.3821
charge      520              -0.2874
charge      521               0.8326
charge      522               0.2681
charge      523              -0.8199
charge      524               0.1346
charge      525              -0.3821
charge      526              -0.3070
charge      527               0.8343
charge      528               0.2681
charge      529              -0.8190
charge      530               0.1375
charge      531              -0.3821
charge      532              -0.2563
charge      533               0.8113
charge      534               0.2681
charge      535              -0.8132
charge      536               0.1304
charge      537              -0.3821
charge      538              -0.2315
charge      539               0.7810
charge      540               0.2681
charge      541              -0.8044
charge      542               0.1207
charge      543              -0.3821
charge      544              -0.1598
charge      545               0.7497
charge      546               0.2681
charge      547              -0.7981
charge      548               0.1396
charge      549              -0.3821
charge      550              -0.1283
charge      551               0.7618
charge      552               0.2681
charge      553              -0.8041
charge      554               0.0938
charge      555              -0.2802
charge      556              -0.1236
charge      557               0.6631
charge      558              -0.7697
charge      559               0.0776
charge      560              -0.3821
charge      561              -0.1756
charge      562               0.7660
charge      563               0.2681
charge      564              -0.8026
charge      565               0.1098
charge      566              -0.3821
charge      567              -0.1911
charge      568               0.7817
charge      569               0.2681
charge      570              -0.8070
charge      571               0.1092
charge      572              -0.3821
charge      573              -0.2064
charge      574               0.7658
charge      575               0.2681
charge      576              -0.8011
charge      577               0.1272
charge      578              -0.3481
charge      579              -0.1503
charge      580               0.8032
charge      581               0.2764
charge      582              -0.8177
charge      583               0.1115
charge      584              -0.3821
charge      585              -0.1618
charge      586               0.7615
charge      587               0.2681
charge      588              -0.8016
charge      589               0.1100
charge      590              -0.3821
charge      591              -0.2661
charge      592               0.7916
charge      593               0.2681
charge      594              -0.8065
charge      595               0.1650
charge      596              -0.5192
charge      597              -0.1810
charge      598               0.7256
charge      599               0.3055
charge      600              -0.7887
charge      601               0.1046
charge      602              -0.3821
charge      603              -0.1927
charge      604               0.8050
charge      605               0.2681
charge      606              -0.8147
charge      607               0.1358
charge      608              -0.5192
charge      609              -0.2000
charge      610               0.7420
charge      611               0.3055
charge      612              -0.7930
charge      613               0.1399
charge      614              -0.3821
charge      615              -0.2108
charge      616               0.7775
charge      617               0.2681
charge      618              -0.8042
charge      619               0.1232
charge      620              -0.3821
charge      621              -0.2441
charge      622               0.8013
charge      623               0.2681
charge      624              -0.8105
charge      625               0.1277
charge      626              -0.3481
charge      627              -0.2964
charge      628               0.8488
charge      629               0.2764
charge      630              -0.8252
charge      631               0.1438
charge      632              -0.3481
charge      633              -0.3117
charge      634               0.8557
charge      635               0.2764
charge      636              -0.8266
charge      637               0.1447
charge      638              -0.3481
charge      639              -0.2964
charge      640               0.8488
charge      641               0.2764
charge      642              -0.8252
charge      643               0.1438
charge      644              -0.3821      !! Tinker
charge      645              -0.0572      !! Tinker
charge      646               0.8000      !! Tinker
charge      647               0.2681      !! Tinker
charge      648              -0.8200      !! Tinker
charge     1001              -0.4989
charge     1002               0.0558
charge     1003               0.0679
charge     1004               0.0679
charge     1005               0.1065
charge     1006               0.1174
charge     1007              -0.3548
charge     1008               0.0394
charge     1009               0.2007
charge     1010               0.2022
charge     1011               0.0615
charge     1012               0.0670
charge     1013               0.0972
charge     1014              -0.6139
charge     1015               0.4186
charge     1016              -0.5246
charge     1017              -0.0251
charge     1018               0.3053
charge     1019               0.0515
charge     1020              -0.6073
charge     1021               0.2006
charge     1022              -0.6997
charge     1023               0.5875
charge     1024              -0.7615
charge     1025               0.7009
charge     1026               0.0473
charge     1027              -0.9019
charge     1028               0.4115
charge     1029               0.4115
charge     1030               0.1553
charge     1031              -0.4989
charge     1032               0.0558
charge     1033               0.0679
charge     1034               0.0679
charge     1035               0.1065
charge     1036               0.1174
charge     1037              -0.3548
charge     1038               0.0191
charge     1039               0.2006
charge     1040               0.2022
charge     1041               0.0615
charge     1042               0.0670
charge     1043               0.0972
charge     1044              -0.6139
charge     1045               0.4186
charge     1046              -0.5246
charge     1047               0.0492
charge     1048               0.1222
charge     1049               0.1744
charge     1050              -0.5709
charge     1051               0.1374
charge     1052              -0.6323
charge     1053               0.7657
charge     1054              -0.4787
charge     1055               0.4770
charge     1056               0.3424
charge     1057              -0.9672
charge     1058               0.4364
charge     1059               0.4364
charge     1060              -0.5597
charge     1061               0.1640
charge     1062              -0.4989
charge     1063               0.0558
charge     1064               0.0679
charge     1065               0.0679
charge     1066               0.1065
charge     1067               0.1174
charge     1068              -0.3548
charge     1069               0.0066
charge     1070               0.2029
charge     1071               0.2022
charge     1072               0.0615
charge     1073               0.0670
charge     1074               0.0972
charge     1075              -0.6139
charge     1076               0.4186
charge     1077              -0.5246
charge     1078              -0.0484
charge     1079               0.7538
charge     1080              -0.7584
charge     1081               0.8185
charge     1082              -0.5215
charge     1083               0.0053
charge     1084              -0.6252
charge     1085              -0.9530
charge     1086               0.4234
charge     1087               0.4234
charge     1088               0.1928
charge     1089               0.1958
charge     1090              -0.4989
charge     1091               0.0558
charge     1092               0.0679
charge     1093               0.0679
charge     1094               0.1065
charge     1095               0.1174
charge     1096              -0.3548
charge     1097               0.0674
charge     1098               0.1824
charge     1099               0.2022
charge     1100               0.0615
charge     1101               0.0670
charge     1102               0.0972
charge     1103              -0.6139
charge     1104               0.4186
charge     1105              -0.5246
charge     1106               0.0418
charge     1107               0.4687
charge     1108              -0.3549
charge     1109               0.5952
charge     1110              -0.3635
charge     1111              -0.1126
charge     1112              -0.5477
charge     1113               0.3154
charge     1114              -0.5761
charge     1115               0.1811
charge     1116               0.2188
charge     1117              -0.4954
charge     1118              -0.0069
charge     1119               0.0754
charge     1120               0.0754
charge     1121               0.1629
charge     1122               0.1176
charge     1123              -0.3691
charge     1124               0.0431
charge     1125               0.1838
charge     1126               0.0713
charge     1127               0.0985
charge     1128              -0.0854
charge     1129               0.0718
charge     1130               0.0718
charge     1131              -0.5232
charge     1132              -0.0268
charge     1133               0.3800
charge     1134               0.0725
charge     1135              -0.6175
charge     1136               0.1607
charge     1137              -0.7417
charge     1138               0.5716
charge     1139              -0.7624
charge     1140               0.6897
charge     1141               0.0598
charge     1142              -0.9123
charge     1143               0.4167
charge     1144               0.4167
charge     1145               0.1877
charge     1146              -0.4954
charge     1147              -0.0069
charge     1148               0.0754
charge     1149               0.0754
charge     1150               0.1629
charge     1151               0.1176
charge     1152              -0.3691
charge     1153               0.0358
charge     1154               0.1746
charge     1155               0.0713
charge     1156               0.0985
charge     1157              -0.0854
charge     1158               0.0718
charge     1159               0.0718
charge     1160              -0.5232
charge     1161               0.0577
charge     1162               0.1814
charge     1163               0.1991
charge     1164              -0.5725
charge     1165               0.0736
charge     1166              -0.6636
charge     1167               0.7432
charge     1168              -0.5053
charge     1169               0.4918
charge     1170               0.3520
charge     1171              -0.9230
charge     1172               0.4235
charge     1173               0.4235
charge     1174              -0.5699
charge     1175               0.1997
charge     1176              -0.4954
charge     1177              -0.0069
charge     1178               0.0754
charge     1179               0.0754
charge     1180               0.1629
charge     1181               0.1176
charge     1182              -0.3691
charge     1183              -0.0116
charge     1184               0.1963
charge     1185               0.0713
charge     1186               0.0985
charge     1187              -0.0854
charge     1188               0.0718
charge     1189               0.0718
charge     1190              -0.5232
charge     1191              -0.0339
charge     1192               0.7959
charge     1193              -0.7748
charge     1194               0.8439
charge     1195              -0.5222
charge     1196              -0.0183
charge     1197              -0.6548
charge     1198              -0.9773
charge     1199               0.4314
charge     1200               0.4314
charge     1201               0.1863
charge     1202               0.2293
charge     1203              -0.4954
charge     1204              -0.0069
charge     1205               0.0754
charge     1206               0.0754
charge     1207               0.1629
charge     1208               0.1176
charge     1209              -0.3691
charge     1210               0.0680
charge     1211               0.1804
charge     1212               0.0713
charge     1213               0.0985
charge     1214              -0.0854
charge     1215               0.0718
charge     1216               0.0718
charge     1217              -0.5232
charge     1218              -0.0239
charge     1219               0.5677
charge     1220              -0.4340
charge     1221               0.5194
charge     1222               0.0025
charge     1223              -0.2209
charge     1224              -0.5881
charge     1225               0.3420
charge     1226              -0.5563
charge     1227              -0.2269
charge     1228               0.0770
charge     1229               0.2607
charge     1230               1.1662
charge     1231              -0.7760
charge     1232              -0.6223
charge     1233               0.4295
charge     1234              -0.6328      !! Tinker
charge     1235               0.9000      !! Tinker
charge     1236              -0.8200      !! Tinker
charge     1237              -0.6541
charge     1238               0.4376
charge     1239              -0.6565      !! Tinker
charge     1240               0.9000      !! Tinker
charge     1241              -0.8200      !! Tinker
charge     1242               1.1659
charge     1243              -0.7761
charge     1244              -0.6318
charge     1245               0.4422
charge     1246              -0.6296      !! Tinker
charge     1247               0.9000      !! Tinker
charge     1248              -0.8200      !! Tinker
charge     1249              -0.6549
charge     1250               0.4396
charge     1251              -0.6553      !! Tinker
charge     1252               0.9000      !! Tinker
charge     1253              -0.8200      !! Tinker
charge     2001              -0.8340
charge     2002               0.4170
charge     2003               1.0000
charge     2004               1.0000
charge     2005               1.0000
charge     2006               1.0000
charge     2007               1.0000
charge     2008               2.0000
charge     2009               2.0000
charge     2010               2.0000
charge     2011               2.0000
charge     2012              -1.0000


      ########################################
      ##                                    ##
      ##  Biopolymer Atom Type Conversions  ##
      ##                                    ##
      ########################################


biotype       1    N       "Glycine"                           1
biotype       2    CA      "Glycine"                           2
biotype       3    C       "Glycine"                           3
biotype       4    HN      "Glycine"                           4
biotype       5    O       "Glycine"                           5
biotype       6    HA      "Glycine"                           6
biotype       7    N       "Alanine"                           7
biotype       8    CA      "Alanine"                           8
biotype       9    C       "Alanine"                           9
biotype      10    HN      "Alanine"                          10
biotype      11    O       "Alanine"                          11
biotype      12    HA      "Alanine"                          12
biotype      13    CB      "Alanine"                          13
biotype      14    HB      "Alanine"                          14
biotype      15    N       "Valine"                           15
biotype      16    CA      "Valine"                           16
biotype      17    C       "Valine"                           17
biotype      18    HN      "Valine"                           18
biotype      19    O       "Valine"                           19
biotype      20    HA      "Valine"                           20
biotype      21    CB      "Valine"                           21
biotype      22    HB      "Valine"                           22
biotype      23    CG1     "Valine"                           23
biotype      24    HG1     "Valine"                           24
biotype      25    CG2     "Valine"                           25
biotype      26    HG2     "Valine"                           26
biotype      27    N       "Leucine"                          27
biotype      28    CA      "Leucine"                          28
biotype      29    C       "Leucine"                          29
biotype      30    HN      "Leucine"                          30
biotype      31    O       "Leucine"                          31
biotype      32    HA      "Leucine"                          32
biotype      33    CB      "Leucine"                          33
biotype      34    HB      "Leucine"                          34
biotype      35    CG      "Leucine"                          35
biotype      36    HG      "Leucine"                          36
biotype      37    CD1     "Leucine"                          37
biotype      38    HD1     "Leucine"                          38
biotype      39    CD2     "Leucine"                          39
biotype      40    HD2     "Leucine"                          40
biotype      41    N       "Isoleucine"                       41
biotype      42    CA      "Isoleucine"                       42
biotype      43    C       "Isoleucine"                       43
biotype      44    HN      "Isoleucine"                       44
biotype      45    O       "Isoleucine"                       45
biotype      46    HA      "Isoleucine"                       46
biotype      47    CB      "Isoleucine"                       47
biotype      48    HB      "Isoleucine"                       48
biotype      49    CG1     "Isoleucine"                       49
biotype      50    HG1     "Isoleucine"                       50
biotype      51    CG2     "Isoleucine"                       51
biotype      52    HG2     "Isoleucine"                       52
biotype      53    CD      "Isoleucine"                       53
biotype      54    HD      "Isoleucine"                       54
biotype      55    N       "Serine"                           55
biotype      56    CA      "Serine"                           56
biotype      57    C       "Serine"                           57
biotype      58    HN      "Serine"                           58
biotype      59    O       "Serine"                           59
biotype      60    HA      "Serine"                           60
biotype      61    CB      "Serine"                           61
biotype      62    HB      "Serine"                           62
biotype      63    OG      "Serine"                           63
biotype      64    HG      "Serine"                           64
biotype      65    N       "Threonine"                        65
biotype      66    CA      "Threonine"                        66
biotype      67    C       "Threonine"                        67
biotype      68    HN      "Threonine"                        68
biotype      69    O       "Threonine"                        69
biotype      70    HA      "Threonine"                        70
biotype      71    CB      "Threonine"                        71
biotype      72    HB      "Threonine"                        72
biotype      73    OG1     "Threonine"                        73
biotype      74    HG1     "Threonine"                        74
biotype      75    CG2     "Threonine"                        75
biotype      76    HG2     "Threonine"                        76
biotype      77    N       "Cysteine (SH)"                    77
biotype      78    CA      "Cysteine (SH)"                    78
biotype      79    C       "Cysteine (SH)"                    79
biotype      80    HN      "Cysteine (SH)"                    80
biotype      81    O       "Cysteine (SH)"                    81
biotype      82    HA      "Cysteine (SH)"                    82
biotype      83    CB      "Cysteine (SH)"                    83
biotype      84    HB      "Cysteine (SH)"                    84
biotype      85    SG      "Cysteine (SH)"                    85
biotype      86    HG      "Cysteine (SH)"                    86
biotype      87    N       "Cystine (SS)"                     87
biotype      88    CA      "Cystine (SS)"                     88
biotype      89    C       "Cystine (SS)"                     89
biotype      90    HN      "Cystine (SS)"                     90
biotype      91    O       "Cystine (SS)"                     91
biotype      92    HA      "Cystine (SS)"                     92
biotype      93    CB      "Cystine (SS)"                     93
biotype      94    HB      "Cystine (SS)"                     94
biotype      95    SG      "Cystine (SS)"                     95
biotype      96    N       "Cysteine (S-)"                    -1
biotype      97    CA      "Cysteine (S-)"                    -1
biotype      98    C       "Cysteine (S-)"                    -1
biotype      99    HN      "Cysteine (S-)"                    -1
biotype     100    O       "Cysteine (S-)"                    -1
biotype     101    HA      "Cysteine (S-)"                    -1
biotype     102    CB      "Cysteine (S-)"                    -1
biotype     103    HB      "Cysteine (S-)"                    -1
biotype     104    SG      "Cysteine (S-)"                    -1
biotype     105    N       "Proline"                          96
biotype     106    CA      "Proline"                          97
biotype     107    C       "Proline"                          98
biotype     108    O       "Proline"                          99
biotype     109    HA      "Proline"                         100
biotype     110    CB      "Proline"                         101
biotype     111    HB      "Proline"                         102
biotype     112    CG      "Proline"                         103
biotype     113    HG      "Proline"                         104
biotype     114    CD      "Proline"                         105
biotype     115    HD      "Proline"                         106
biotype     116    N       "Phenylalanine"                   107
biotype     117    CA      "Phenylalanine"                   108
biotype     118    C       "Phenylalanine"                   109
biotype     119    HN      "Phenylalanine"                   110
biotype     120    O       "Phenylalanine"                   111
biotype     121    HA      "Phenylalanine"                   112
biotype     122    CB      "Phenylalanine"                   113
biotype     123    HB      "Phenylalanine"                   114
biotype     124    CG      "Phenylalanine"                   115
biotype     125    CD      "Phenylalanine"                   116
biotype     126    HD      "Phenylalanine"                   117
biotype     127    CE      "Phenylalanine"                   118
biotype     128    HE      "Phenylalanine"                   119
biotype     129    CZ      "Phenylalanine"                   120
biotype     130    HZ      "Phenylalanine"                   121
biotype     131    N       "Tyrosine"                        122
biotype     132    CA      "Tyrosine"                        123
biotype     133    C       "Tyrosine"                        124
biotype     134    HN      "Tyrosine"                        125
biotype     135    O       "Tyrosine"                        126
biotype     136    HA      "Tyrosine"                        127
biotype     137    CB      "Tyrosine"                        128
biotype     138    HB      "Tyrosine"                        129
biotype     139    CG      "Tyrosine"                        130
biotype     140    CD      "Tyrosine"                        131
biotype     141    HD      "Tyrosine"                        132
biotype     142    CE      "Tyrosine"                        133
biotype     143    HE      "Tyrosine"                        134
biotype     144    CZ      "Tyrosine"                        135
biotype     145    OH      "Tyrosine"                        136
biotype     146    HH      "Tyrosine"                        137
biotype     147    N       "Tyrosine (O-)"                    -1
biotype     148    CA      "Tyrosine (O-)"                    -1
biotype     149    C       "Tyrosine (O-)"                    -1
biotype     150    HN      "Tyrosine (O-)"                    -1
biotype     151    O       "Tyrosine (O-)"                    -1
biotype     152    HA      "Tyrosine (O-)"                    -1
biotype     153    CB      "Tyrosine (O-)"                    -1
biotype     154    HB      "Tyrosine (O-)"                    -1
biotype     155    CG      "Tyrosine (O-)"                    -1
biotype     156    CD      "Tyrosine (O-)"                    -1
biotype     157    HD      "Tyrosine (O-)"                    -1
biotype     158    CE      "Tyrosine (O-)"                    -1
biotype     159    HE      "Tyrosine (O-)"                    -1
biotype     160    CZ      "Tyrosine (O-)"                    -1
biotype     161    OH      "Tyrosine (O-)"                    -1
biotype     162    N       "Tryptophan"                      138
biotype     163    CA      "Tryptophan"                      139
biotype     164    C       "Tryptophan"                      140
biotype     165    HN      "Tryptophan"                      141
biotype     166    O       "Tryptophan"                      142
biotype     167    HA      "Tryptophan"                      143
biotype     168    CB      "Tryptophan"                      144
biotype     169    HB      "Tryptophan"                      145
biotype     170    CG      "Tryptophan"                      146
biotype     171    CD1     "Tryptophan"                      147
biotype     172    HD1     "Tryptophan"                      148
biotype     173    CD2     "Tryptophan"                      149
biotype     174    NE1     "Tryptophan"                      150
biotype     175    HE1     "Tryptophan"                      151
biotype     176    CE2     "Tryptophan"                      152
biotype     177    CE3     "Tryptophan"                      153
biotype     178    HE3     "Tryptophan"                      154
biotype     179    CZ2     "Tryptophan"                      155
biotype     180    HZ2     "Tryptophan"                      156
biotype     181    CZ3     "Tryptophan"                      157
biotype     182    HZ3     "Tryptophan"                      158
biotype     183    CH2     "Tryptophan"                      159
biotype     184    HH2     "Tryptophan"                      160
biotype     185    N       "Histidine (+)"                   161
biotype     186    CA      "Histidine (+)"                   162
biotype     187    C       "Histidine (+)"                   163
biotype     188    HN      "Histidine (+)"                   164
biotype     189    O       "Histidine (+)"                   165
biotype     190    HA      "Histidine (+)"                   166
biotype     191    CB      "Histidine (+)"                   167
biotype     192    HB      "Histidine (+)"                   168
biotype     193    CG      "Histidine (+)"                   169
biotype     194    ND1     "Histidine (+)"                   170
biotype     195    HD1     "Histidine (+)"                   171
biotype     196    CD2     "Histidine (+)"                   172
biotype     197    HD2     "Histidine (+)"                   173
biotype     198    CE1     "Histidine (+)"                   174
biotype     199    HE1     "Histidine (+)"                   175
biotype     200    NE2     "Histidine (+)"                   176
biotype     201    HE2     "Histidine (+)"                   177
biotype     202    N       "Histidine (HD)"                  178
biotype     203    CA      "Histidine (HD)"                  179
biotype     204    C       "Histidine (HD)"                  180
biotype     205    HN      "Histidine (HD)"                  181
biotype     206    O       "Histidine (HD)"                  182
biotype     207    HA      "Histidine (HD)"                  183
biotype     208    CB      "Histidine (HD)"                  184
biotype     209    HB      "Histidine (HD)"                  185
biotype     210    CG      "Histidine (HD)"                  186
biotype     211    ND1     "Histidine (HD)"                  187
biotype     212    HD1     "Histidine (HD)"                  188
biotype     213    CD2     "Histidine (HD)"                  189
biotype     214    HD2     "Histidine (HD)"                  190
biotype     215    CE1     "Histidine (HD)"                  191
biotype     216    HE1     "Histidine (HD)"                  192
biotype     217    NE2     "Histidine (HD)"                  193
biotype     218    N       "Histidine (HE)"                  194
biotype     219    CA      "Histidine (HE)"                  195
biotype     220    C       "Histidine (HE)"                  196
biotype     221    HN      "Histidine (HE)"                  197
biotype     222    O       "Histidine (HE)"                  198
biotype     223    HA      "Histidine (HE)"                  199
biotype     224    CB      "Histidine (HE)"                  200
biotype     225    HB      "Histidine (HE)"                  201
biotype     226    CG      "Histidine (HE)"                  202
biotype     227    ND1     "Histidine (HE)"                  203
biotype     228    CD2     "Histidine (HE)"                  204
biotype     229    HD2     "Histidine (HE)"                  205
biotype     230    CE1     "Histidine (HE)"                  206
biotype     231    HE1     "Histidine (HE)"                  207
biotype     232    NE2     "Histidine (HE)"                  208
biotype     233    HE2     "Histidine (HE)"                  209
biotype     234    N       "Aspartic Acid"                   210
biotype     235    CA      "Aspartic Acid"                   211
biotype     236    C       "Aspartic Acid"                   212
biotype     237    HN      "Aspartic Acid"                   213
biotype     238    O       "Aspartic Acid"                   214
biotype     239    HA      "Aspartic Acid"                   215
biotype     240    CB      "Aspartic Acid"                   216
biotype     241    HB      "Aspartic Acid"                   217
biotype     242    CG      "Aspartic Acid"                   218
biotype     243    OD      "Aspartic Acid"                   219
biotype     244    N       "Aspartic Acid (COOH)"             -1
biotype     245    CA      "Aspartic Acid (COOH)"             -1
biotype     246    C       "Aspartic Acid (COOH)"             -1
biotype     247    HN      "Aspartic Acid (COOH)"             -1
biotype     248    O       "Aspartic Acid (COOH)"             -1
biotype     249    HA      "Aspartic Acid (COOH)"             -1
biotype     250    CB      "Aspartic Acid (COOH)"             -1
biotype     251    HB      "Aspartic Acid (COOH)"             -1
biotype     252    CG      "Aspartic Acid (COOH)"             -1
biotype     253    OD1     "Aspartic Acid (COOH)"             -1
biotype     254    OD2     "Aspartic Acid (COOH)"             -1
biotype     255    HD2     "Aspartic Acid (COOH)"             -1
biotype     256    N       "Asparagine"                      220
biotype     257    CA      "Asparagine"                      221
biotype     258    C       "Asparagine"                      222
biotype     259    HN      "Asparagine"                      223
biotype     260    O       "Asparagine"                      224
biotype     261    HA      "Asparagine"                      225
biotype     262    CB      "Asparagine"                      226
biotype     263    HB      "Asparagine"                      227
biotype     264    CG      "Asparagine"                      228
biotype     265    OD1     "Asparagine"                      229
biotype     266    ND2     "Asparagine"                      230
biotype     267    HD2     "Asparagine"                      231
biotype     268    N       "Glutamic Acid"                   232
biotype     269    CA      "Glutamic Acid"                   233
biotype     270    C       "Glutamic Acid"                   234
biotype     271    HN      "Glutamic Acid"                   235
biotype     272    O       "Glutamic Acid"                   236
biotype     273    HA      "Glutamic Acid"                   237
biotype     274    CB      "Glutamic Acid"                   238
biotype     275    HB      "Glutamic Acid"                   239
biotype     276    CG      "Glutamic Acid"                   240
biotype     277    HG      "Glutamic Acid"                   241
biotype     278    CD      "Glutamic Acid"                   242
biotype     279    OE      "Glutamic Acid"                   243
biotype     280    N       "Glutamic Acid (COOH)"             -1
biotype     281    CA      "Glutamic Acid (COOH)"             -1
biotype     282    C       "Glutamic Acid (COOH)"             -1
biotype     283    HN      "Glutamic Acid (COOH)"             -1
biotype     284    O       "Glutamic Acid (COOH)"             -1
biotype     285    HA      "Glutamic Acid (COOH)"             -1
biotype     286    CB      "Glutamic Acid (COOH)"             -1
biotype     287    HB      "Glutamic Acid (COOH)"             -1
biotype     288    CG      "Glutamic Acid (COOH)"             -1
biotype     289    HG      "Glutamic Acid (COOH)"             -1
biotype     290    CD      "Glutamic Acid (COOH)"             -1
biotype     291    OE1     "Glutamic Acid (COOH)"             -1
biotype     292    OE2     "Glutamic Acid (COOH)"             -1
biotype     293    HE2     "Glutamic Acid (COOH)"             -1
biotype     294    N       "Glutamine"                       244
biotype     295    CA      "Glutamine"                       245
biotype     296    C       "Glutamine"                       246
biotype     297    HN      "Glutamine"                       247
biotype     298    O       "Glutamine"                       248
biotype     299    HA      "Glutamine"                       249
biotype     300    CB      "Glutamine"                       250
biotype     301    HB      "Glutamine"                       251
biotype     302    CG      "Glutamine"                       252
biotype     303    HG      "Glutamine"                       253
biotype     304    CD      "Glutamine"                       254
biotype     305    OE1     "Glutamine"                       255
biotype     306    NE2     "Glutamine"                       256
biotype     307    HE2     "Glutamine"                       257
biotype     308    N       "Methionine"                      258
biotype     309    CA      "Methionine"                      259
biotype     310    C       "Methionine"                      260
biotype     311    HN      "Methionine"                      261
biotype     312    O       "Methionine"                      262
biotype     313    HA      "Methionine"                      263
biotype     314    CB      "Methionine"                      264
biotype     315    HB      "Methionine"                      265
biotype     316    CG      "Methionine"                      266
biotype     317    HG      "Methionine"                      267
biotype     318    SD      "Methionine"                      268
biotype     319    CE      "Methionine"                      269
biotype     320    HE      "Methionine"                      270
biotype     321    N       "Lysine"                          271
biotype     322    CA      "Lysine"                          272
biotype     323    C       "Lysine"                          273
biotype     324    HN      "Lysine"                          274
biotype     325    O       "Lysine"                          275
biotype     326    HA      "Lysine"                          276
biotype     327    CB      "Lysine"                          277
biotype     328    HB      "Lysine"                          278
biotype     329    CG      "Lysine"                          279
biotype     330    HG      "Lysine"                          280
biotype     331    CD      "Lysine"                          281
biotype     332    HD      "Lysine"                          282
biotype     333    CE      "Lysine"                          283
biotype     334    HE      "Lysine"                          284
biotype     335    NZ      "Lysine"                          285
biotype     336    HZ      "Lysine"                          286
biotype     337    N       "Lysine (NH2)"                     -1
biotype     338    CA      "Lysine (NH2)"                     -1
biotype     339    C       "Lysine (NH2)"                     -1
biotype     340    HN      "Lysine (NH2)"                     -1
biotype     341    O       "Lysine (NH2)"                     -1
biotype     342    HA      "Lysine (NH2)"                     -1
biotype     343    CB      "Lysine (NH2)"                     -1
biotype     344    HB      "Lysine (NH2)"                     -1
biotype     345    CG      "Lysine (NH2)"                     -1
biotype     346    HG      "Lysine (NH2)"                     -1
biotype     347    CD      "Lysine (NH2)"                     -1
biotype     348    HD      "Lysine (NH2)"                     -1
biotype     349    CE      "Lysine (NH2)"                     -1
biotype     350    HE      "Lysine (NH2)"                     -1
biotype     351    NZ      "Lysine (NH2)"                     -1
biotype     352    HZ      "Lysine (NH2)"                     -1
biotype     353    N       "Arginine"                        287
biotype     354    CA      "Arginine"                        288
biotype     355    C       "Arginine"                        289
biotype     356    HN      "Arginine"                        290
biotype     357    O       "Arginine"                        291
biotype     358    HA      "Arginine"                        292
biotype     359    CB      "Arginine"                        293
biotype     360    HB      "Arginine"                        294
biotype     361    CG      "Arginine"                        295
biotype     362    HG      "Arginine"                        296
biotype     363    CD      "Arginine"                        297
biotype     364    HD      "Arginine"                        298
biotype     365    NE      "Arginine"                        299
biotype     366    HE      "Arginine"                        300
biotype     367    CZ      "Arginine"                        301
biotype     368    NH      "Arginine"                        302
biotype     369    HH      "Arginine"                        303
biotype     370    N       "Ornithine"                       304
biotype     371    CA      "Ornithine"                       305
biotype     372    C       "Ornithine"                       306
biotype     373    HN      "Ornithine"                       307
biotype     374    O       "Ornithine"                       308
biotype     375    HA      "Ornithine"                       309
biotype     376    CB      "Ornithine"                       310
biotype     377    HB      "Ornithine"                       311
biotype     378    CG      "Ornithine"                       312
biotype     379    HG      "Ornithine"                       313
biotype     380    CD      "Ornithine"                       314
biotype     381    HD      "Ornithine"                       315
biotype     382    NE      "Ornithine"                       316
biotype     383    HE      "Ornithine"                       317
biotype     384    N       "MethylAlanine (AIB)"             318
biotype     385    CA      "MethylAlanine (AIB)"             319
biotype     386    C       "MethylAlanine (AIB)"             320
biotype     387    HN      "MethylAlanine (AIB)"             321
biotype     388    O       "MethylAlanine (AIB)"             322
biotype     389    CB      "MethylAlanine (AIB)"             323
biotype     390    HB      "MethylAlanine (AIB)"             324
biotype     391    N       "Pyroglutamic Acid"               325
biotype     392    CA      "Pyroglutamic Acid"               326
biotype     393    C       "Pyroglutamic Acid"               327
biotype     394    HN      "Pyroglutamic Acid"               328
biotype     395    O       "Pyroglutamic Acid"               329
biotype     396    HA      "Pyroglutamic Acid"               330
biotype     397    CB      "Pyroglutamic Acid"               331
biotype     398    HB      "Pyroglutamic Acid"               332
biotype     399    CG      "Pyroglutamic Acid"               333
biotype     400    HG      "Pyroglutamic Acid"               334
biotype     401    CD      "Pyroglutamic Acid"               335
biotype     402    OE      "Pyroglutamic Acid"               336
biotype     403    N       "N-Terminal GLY"                  350
biotype     404    CA      "N-Terminal GLY"                  351
biotype     405    C       "N-Terminal GLY"                  352
biotype     406    HN      "N-Terminal GLY"                  353
biotype     407    O       "N-Terminal GLY"                  354
biotype     408    HA      "N-Terminal GLY"                  355
biotype     409    N       "N-Terminal ALA"                  356
biotype     410    CA      "N-Terminal ALA"                  357
biotype     411    C       "N-Terminal ALA"                  358
biotype     412    HN      "N-Terminal ALA"                  359
biotype     413    O       "N-Terminal ALA"                  360
biotype     414    HA      "N-Terminal ALA"                  361
biotype     415    N       "N-Terminal VAL"                  362
biotype     416    CA      "N-Terminal VAL"                  363
biotype     417    C       "N-Terminal VAL"                  364
biotype     418    HN      "N-Terminal VAL"                  365
biotype     419    O       "N-Terminal VAL"                  366
biotype     420    HA      "N-Terminal VAL"                  367
biotype     421    N       "N-Terminal LEU"                  368
biotype     422    CA      "N-Terminal LEU"                  369
biotype     423    C       "N-Terminal LEU"                  370
biotype     424    HN      "N-Terminal LEU"                  371
biotype     425    O       "N-Terminal LEU"                  372
biotype     426    HA      "N-Terminal LEU"                  373
biotype     427    N       "N-Terminal ILE"                  374
biotype     428    CA      "N-Terminal ILE"                  375
biotype     429    C       "N-Terminal ILE"                  376
biotype     430    HN      "N-Terminal ILE"                  377
biotype     431    O       "N-Terminal ILE"                  378
biotype     432    HA      "N-Terminal ILE"                  379
biotype     433    N       "N-Terminal SER"                  380
biotype     434    CA      "N-Terminal SER"                  381
biotype     435    C       "N-Terminal SER"                  382
biotype     436    HN      "N-Terminal SER"                  383
biotype     437    O       "N-Terminal SER"                  384
biotype     438    HA      "N-Terminal SER"                  385
biotype     439    N       "N-Terminal THR"                  386
biotype     440    CA      "N-Terminal THR"                  387
biotype     441    C       "N-Terminal THR"                  388
biotype     442    HN      "N-Terminal THR"                  389
biotype     443    O       "N-Terminal THR"                  390
biotype     444    HA      "N-Terminal THR"                  391
biotype     445    N       "N-Terminal CYS (SH)"             392
biotype     446    CA      "N-Terminal CYS (SH)"             393
biotype     447    C       "N-Terminal CYS (SH)"             394
biotype     448    HN      "N-Terminal CYS (SH)"             395
biotype     449    O       "N-Terminal CYS (SH)"             396
biotype     450    HA      "N-Terminal CYS (SH)"             397
biotype     451    N       "N-Terminal CYX (SS)"             398
biotype     452    CA      "N-Terminal CYX (SS)"             399
biotype     453    C       "N-Terminal CYX (SS)"             400
biotype     454    HN      "N-Terminal CYX (SS)"             401
biotype     455    O       "N-Terminal CYX (SS)"             402
biotype     456    HA      "N-Terminal CYX (SS)"             403
biotype     457    N       "N-Terminal CYD (S-)"              -1
biotype     458    CA      "N-Terminal CYD (S-)"              -1
biotype     459    C       "N-Terminal CYD (S-)"              -1
biotype     460    HN      "N-Terminal CYD (S-)"              -1
biotype     461    O       "N-Terminal CYD (S-)"              -1
biotype     462    HA      "N-Terminal CYD (S-)"              -1
biotype     463    N       "N-Terminal PRO"                  404
biotype     464    CA      "N-Terminal PRO"                  405
biotype     465    C       "N-Terminal PRO"                  406
biotype     466    HN      "N-Terminal PRO"                  407
biotype     467    O       "N-Terminal PRO"                  408
biotype     468    HA      "N-Terminal PRO"                  409
biotype     469    CD      "N-Terminal PRO"                  410
biotype     470    HD      "N-Terminal PRO"                  411
biotype     471    N       "N-Terminal PHE"                  412
biotype     472    CA      "N-Terminal PHE"                  413
biotype     473    C       "N-Terminal PHE"                  414
biotype     474    HN      "N-Terminal PHE"                  415
biotype     475    O       "N-Terminal PHE"                  416
biotype     476    HA      "N-Terminal PHE"                  417
biotype     477    N       "N-Terminal TYR"                  418
biotype     478    CA      "N-Terminal TYR"                  419
biotype     479    C       "N-Terminal TYR"                  420
biotype     480    HN      "N-Terminal TYR"                  421
biotype     481    O       "N-Terminal TYR"                  422
biotype     482    HA      "N-Terminal TYR"                  423
biotype     483    N       "N-Terminal TYD (O-)"              -1
biotype     484    CA      "N-Terminal TYD (O-)"              -1
biotype     485    C       "N-Terminal TYD (O-)"              -1
biotype     486    HN      "N-Terminal TYD (O-)"              -1
biotype     487    O       "N-Terminal TYD (O-)"              -1
biotype     488    HA      "N-Terminal TYD (O-)"              -1
biotype     489    N       "N-Terminal TRP"                  424
biotype     490    CA      "N-Terminal TRP"                  425
biotype     491    C       "N-Terminal TRP"                  426
biotype     492    HN      "N-Terminal TRP"                  427
biotype     493    O       "N-Terminal TRP"                  428
biotype     494    HA      "N-Terminal TRP"                  429
biotype     495    N       "N-Terminal HIS (+)"              430
biotype     496    CA      "N-Terminal HIS (+)"              431
biotype     497    C       "N-Terminal HIS (+)"              432
biotype     498    HN      "N-Terminal HIS (+)"              433
biotype     499    O       "N-Terminal HIS (+)"              434
biotype     500    HA      "N-Terminal HIS (+)"              435
biotype     501    N       "N-Terminal HIS (HD)"             436
biotype     502    CA      "N-Terminal HIS (HD)"             437
biotype     503    C       "N-Terminal HIS (HD)"             438
biotype     504    HN      "N-Terminal HIS (HD)"             439
biotype     505    O       "N-Terminal HIS (HD)"             440
biotype     506    HA      "N-Terminal HIS (HD)"             441
biotype     507    N       "N-Terminal HIS (HE)"             442
biotype     508    CA      "N-Terminal HIS (HE)"             443
biotype     509    C       "N-Terminal HIS (HE)"             444
biotype     510    HN      "N-Terminal HIS (HE)"             445
biotype     511    O       "N-Terminal HIS (HE)"             446
biotype     512    HA      "N-Terminal HIS (HE)"             447
biotype     513    N       "N-Terminal ASP"                  448
biotype     514    CA      "N-Terminal ASP"                  449
biotype     515    C       "N-Terminal ASP"                  450
biotype     516    HN      "N-Terminal ASP"                  451
biotype     517    O       "N-Terminal ASP"                  452
biotype     518    HA      "N-Terminal ASP"                  453
biotype     519    N       "N-Terminal ASH (COOH)"            -1
biotype     520    CA      "N-Terminal ASH (COOH)"            -1
biotype     521    C       "N-Terminal ASH (COOH)"            -1
biotype     522    HN      "N-Terminal ASH (COOH)"            -1
biotype     523    O       "N-Terminal ASH (COOH)"            -1
biotype     524    HA      "N-Terminal ASH (COOH)"            -1
biotype     525    N       "N-Terminal ASN"                  454
biotype     526    CA      "N-Terminal ASN"                  455
biotype     527    C       "N-Terminal ASN"                  456
biotype     528    HN      "N-Terminal ASN"                  457
biotype     529    O       "N-Terminal ASN"                  458
biotype     530    HA      "N-Terminal ASN"                  459
biotype     531    N       "N-Terminal GLU"                  460
biotype     532    CA      "N-Terminal GLU"                  461
biotype     533    C       "N-Terminal GLU"                  462
biotype     534    HN      "N-Terminal GLU"                  463
biotype     535    O       "N-Terminal GLU"                  464
biotype     536    HA      "N-Terminal GLU"                  465
biotype     537    N       "N-Terminal GLH (COOH)"            -1
biotype     538    CA      "N-Terminal GLH (COOH)"            -1
biotype     539    C       "N-Terminal GLH (COOH)"            -1
biotype     540    HN      "N-Terminal GLH (COOH)"            -1
biotype     541    O       "N-Terminal GLH (COOH)"            -1
biotype     542    HA      "N-Terminal GLH (COOH)"            -1
biotype     543    N       "N-Terminal GLN"                  466
biotype     544    CA      "N-Terminal GLN"                  467
biotype     545    C       "N-Terminal GLN"                  468
biotype     546    HN      "N-Terminal GLN"                  469
biotype     547    O       "N-Terminal GLN"                  470
biotype     548    HA      "N-Terminal GLN"                  471
biotype     549    N       "N-Terminal MET"                  472
biotype     550    CA      "N-Terminal MET"                  473
biotype     551    C       "N-Terminal MET"                  474
biotype     552    HN      "N-Terminal MET"                  475
biotype     553    O       "N-Terminal MET"                  476
biotype     554    HA      "N-Terminal MET"                  477
biotype     555    N       "N-Terminal LYS"                  478
biotype     556    CA      "N-Terminal LYS"                  479
biotype     557    C       "N-Terminal LYS"                  480
biotype     558    HN      "N-Terminal LYS"                  481
biotype     559    O       "N-Terminal LYS"                  482
biotype     560    HA      "N-Terminal LYS"                  483
biotype     561    N       "N-Terminal LYD (NH2)"             -1
biotype     562    CA      "N-Terminal LYD (NH2)"             -1
biotype     563    C       "N-Terminal LYD (NH2)"             -1
biotype     564    HN      "N-Terminal LYD (NH2)"             -1
biotype     565    O       "N-Terminal LYD (NH2)"             -1
biotype     566    HA      "N-Terminal LYD (NH2)"             -1
biotype     567    N       "N-Terminal ARG"                  484
biotype     568    CA      "N-Terminal ARG"                  485
biotype     569    C       "N-Terminal ARG"                  486
biotype     570    HN      "N-Terminal ARG"                  487
biotype     571    O       "N-Terminal ARG"                  488
biotype     572    HA      "N-Terminal ARG"                  489
biotype     573    N       "N-Terminal ORN"                  490
biotype     574    CA      "N-Terminal ORN"                  491
biotype     575    C       "N-Terminal ORN"                  492
biotype     576    HN      "N-Terminal ORN"                  493
biotype     577    O       "N-Terminal ORN"                  494
biotype     578    HA      "N-Terminal ORN"                  495
biotype     579    N       "N-Terminal AIB"                  496
biotype     580    CA      "N-Terminal AIB"                  497
biotype     581    C       "N-Terminal AIB"                  498
biotype     582    HN      "N-Terminal AIB"                  499
biotype     583    O       "N-Terminal AIB"                  500
biotype     584    N       "C-Terminal GLY"                  501
biotype     585    CA      "C-Terminal GLY"                  502
biotype     586    C       "C-Terminal GLY"                  503
biotype     587    HN      "C-Terminal GLY"                  504
biotype     588    OXT     "C-Terminal GLY"                  505
biotype     589    HA      "C-Terminal GLY"                  506
biotype     590    N       "C-Terminal ALA"                  507
biotype     591    CA      "C-Terminal ALA"                  508
biotype     592    C       "C-Terminal ALA"                  509
biotype     593    HN      "C-Terminal ALA"                  510
biotype     594    OXT     "C-Terminal ALA"                  511
biotype     595    HA      "C-Terminal ALA"                  512
biotype     596    N       "C-Terminal VAL"                  513
biotype     597    CA      "C-Terminal VAL"                  514
biotype     598    C       "C-Terminal VAL"                  515
biotype     599    HN      "C-Terminal VAL"                  516
biotype     600    OXT     "C-Terminal VAL"                  517
biotype     601    HA      "C-Terminal VAL"                  518
biotype     602    N       "C-Terminal LEU"                  519
biotype     603    CA      "C-Terminal LEU"                  520
biotype     604    C       "C-Terminal LEU"                  521
biotype     605    HN      "C-Terminal LEU"                  522
biotype     606    OXT     "C-Terminal LEU"                  523
biotype     607    HA      "C-Terminal LEU"                  524
biotype     608    N       "C-Terminal ILE"                  525
biotype     609    CA      "C-Terminal ILE"                  526
biotype     610    C       "C-Terminal ILE"                  527
biotype     611    HN      "C-Terminal ILE"                  528
biotype     612    OXT     "C-Terminal ILE"                  529
biotype     613    HA      "C-Terminal ILE"                  530
biotype     614    N       "C-Terminal SER"                  531
biotype     615    CA      "C-Terminal SER"                  532
biotype     616    C       "C-Terminal SER"                  533
biotype     617    HN      "C-Terminal SER"                  534
biotype     618    OXT     "C-Terminal SER"                  535
biotype     619    HA      "C-Terminal SER"                  536
biotype     620    N       "C-Terminal THR"                  537
biotype     621    CA      "C-Terminal THR"                  538
biotype     622    C       "C-Terminal THR"                  539
biotype     623    HN      "C-Terminal THR"                  540
biotype     624    OXT     "C-Terminal THR"                  541
biotype     625    HA      "C-Terminal THR"                  542
biotype     626    N       "C-Terminal CYS (SH)"             543
biotype     627    CA      "C-Terminal CYS (SH)"             544
biotype     628    C       "C-Terminal CYS (SH)"             545
biotype     629    HN      "C-Terminal CYS (SH)"             546
biotype     630    OXT     "C-Terminal CYS (SH)"             547
biotype     631    HA      "C-Terminal CYS (SH)"             548
biotype     632    N       "C-Terminal CYX (SS)"             549
biotype     633    CA      "C-Terminal CYX (SS)"             550
biotype     634    C       "C-Terminal CYX (SS)"             551
biotype     635    HN      "C-Terminal CYX (SS)"             552
biotype     636    OXT     "C-Terminal CYX (SS)"             553
biotype     637    HA      "C-Terminal CYX (SS)"             554
biotype     638    N       "C-Terminal CYD (S-)"              -1
biotype     639    CA      "C-Terminal CYD (S-)"              -1
biotype     640    C       "C-Terminal CYD (S-)"              -1
biotype     641    HN      "C-Terminal CYD (S-)"              -1
biotype     642    OXT     "C-Terminal CYD (S-)"              -1
biotype     643    HA      "C-Terminal CYD (S-)"              -1
biotype     644    N       "C-Terminal PRO"                  555
biotype     645    CA      "C-Terminal PRO"                  556
biotype     646    C       "C-Terminal PRO"                  557
biotype     647    OXT     "C-Terminal PRO"                  558
biotype     648    HA      "C-Terminal PRO"                  559
biotype     649    N       "C-Terminal PHE"                  560
biotype     650    CA      "C-Terminal PHE"                  561
biotype     651    C       "C-Terminal PHE"                  562
biotype     652    HN      "C-Terminal PHE"                  563
biotype     653    OXT     "C-Terminal PHE"                  564
biotype     654    HA      "C-Terminal PHE"                  565
biotype     655    N       "C-Terminal TYR"                  566
biotype     656    CA      "C-Terminal TYR"                  567
biotype     657    C       "C-Terminal TYR"                  568
biotype     658    HN      "C-Terminal TYR"                  569
biotype     659    OXT     "C-Terminal TYR"                  570
biotype     660    HA      "C-Terminal TYR"                  571
biotype     661    N       "C-Terminal TYD (O-)"              -1
biotype     662    CA      "C-Terminal TYD (O-)"              -1
biotype     663    C       "C-Terminal TYD (O-)"              -1
biotype     664    HN      "C-Terminal TYD (O-)"              -1
biotype     665    OXT     "C-Terminal TYD (O-)"              -1
biotype     666    HA      "C-Terminal TYD (O-)"              -1
biotype     667    N       "C-Terminal TRP"                  572
biotype     668    CA      "C-Terminal TRP"                  573
biotype     669    C       "C-Terminal TRP"                  574
biotype     670    HN      "C-Terminal TRP"                  575
biotype     671    OXT     "C-Terminal TRP"                  576
biotype     672    HA      "C-Terminal TRP"                  577
biotype     673    N       "C-Terminal HIS (+)"              578
biotype     674    CA      "C-Terminal HIS (+)"              579
biotype     675    C       "C-Terminal HIS (+)"              580
biotype     676    HN      "C-Terminal HIS (+)"              581
biotype     677    OXT     "C-Terminal HIS (+)"              582
biotype     678    HA      "C-Terminal HIS (+)"              583
biotype     679    N       "C-Terminal HIS (HD)"             584
biotype     680    CA      "C-Terminal HIS (HD)"             585
biotype     681    C       "C-Terminal HIS (HD)"             586
biotype     682    HN      "C-Terminal HIS (HD)"             587
biotype     683    OXT     "C-Terminal HIS (HD)"             588
biotype     684    HA      "C-Terminal HIS (HD)"             589
biotype     685    N       "C-Terminal HIS (HE)"             590
biotype     686    CA      "C-Terminal HIS (HE)"             591
biotype     687    C       "C-Terminal HIS (HE)"             592
biotype     688    HN      "C-Terminal HIS (HE)"             593
biotype     689    OXT     "C-Terminal HIS (HE)"             594
biotype     690    HA      "C-Terminal HIS (HE)"             595
biotype     691    N       "C-Terminal ASP"                  596
biotype     692    CA      "C-Terminal ASP"                  597
biotype     693    C       "C-Terminal ASP"                  598
biotype     694    HN      "C-Terminal ASP"                  599
biotype     695    OXT     "C-Terminal ASP"                  600
biotype     696    HA      "C-Terminal ASP"                  601
biotype     697    N       "C-Terminal ASH (COOH)"            -1
biotype     698    CA      "C-Terminal ASH (COOH)"            -1
biotype     699    C       "C-Terminal ASH (COOH)"            -1
biotype     700    HN      "C-Terminal ASH (COOH)"            -1
biotype     701    OXT     "C-Terminal ASH (COOH)"            -1
biotype     702    HA      "C-Terminal ASH (COOH)"            -1
biotype     703    N       "C-Terminal ASN"                  602
biotype     704    CA      "C-Terminal ASN"                  603
biotype     705    C       "C-Terminal ASN"                  604
biotype     706    HN      "C-Terminal ASN"                  605
biotype     707    OXT     "C-Terminal ASN"                  606
biotype     708    HA      "C-Terminal ASN"                  607
biotype     709    N       "C-Terminal GLU"                  608
biotype     710    CA      "C-Terminal GLU"                  609
biotype     711    C       "C-Terminal GLU"                  610
biotype     712    HN      "C-Terminal GLU"                  611
biotype     713    OXT     "C-Terminal GLU"                  612
biotype     714    HA      "C-Terminal GLU"                  613
biotype     715    N       "C-Terminal GLH (COOH)"            -1
biotype     716    CA      "C-Terminal GLH (COOH)"            -1
biotype     717    C       "C-Terminal GLH (COOH)"            -1
biotype     718    HN      "C-Terminal GLH (COOH)"            -1
biotype     719    OXT     "C-Terminal GLH (COOH)"            -1
biotype     720    HA      "C-Terminal GLH (COOH)"            -1
biotype     721    N       "C-Terminal GLN"                  614
biotype     722    CA      "C-Terminal GLN"                  615
biotype     723    C       "C-Terminal GLN"                  616
biotype     724    HN      "C-Terminal GLN"                  617
biotype     725    OXT     "C-Terminal GLN"                  618
biotype     726    HA      "C-Terminal GLN"                  619
biotype     727    N       "C-Terminal MET"                  620
biotype     728    CA      "C-Terminal MET"                  621
biotype     729    C       "C-Terminal MET"                  622
biotype     730    HN      "C-Terminal MET"                  623
biotype     731    OXT     "C-Terminal MET"                  624
biotype     732    HA      "C-Terminal MET"                  625
biotype     733    N       "C-Terminal LYS"                  626
biotype     734    CA      "C-Terminal LYS"                  627
biotype     735    C       "C-Terminal LYS"                  628
biotype     736    HN      "C-Terminal LYS"                  629
biotype     737    OXT     "C-Terminal LYS"                  630
biotype     738    HA      "C-Terminal LYS"                  631
biotype     739    N       "C-Terminal LYD (NH2)"             -1
biotype     740    CA      "C-Terminal LYD (NH2)"             -1
biotype     741    C       "C-Terminal LYD (NH2)"             -1
biotype     742    HN      "C-Terminal LYD (NH2)"             -1
biotype     743    OXT     "C-Terminal LYD (NH2)"             -1
biotype     744    HA      "C-Terminal LYD (NH2)"             -1
biotype     745    N       "C-Terminal ARG"                  632
biotype     746    CA      "C-Terminal ARG"                  633
biotype     747    C       "C-Terminal ARG"                  634
biotype     748    HN      "C-Terminal ARG"                  635
biotype     749    OXT     "C-Terminal ARG"                  636
biotype     750    HA      "C-Terminal ARG"                  637
biotype     751    N       "C-Terminal ORN"                  638
biotype     752    CA      "C-Terminal ORN"                  639
biotype     753    C       "C-Terminal ORN"                  640
biotype     754    HN      "C-Terminal ORN"                  641
biotype     755    OXT     "C-Terminal ORN"                  642
biotype     756    HA      "C-Terminal ORN"                  643
biotype     757    N       "C-Terminal AIB"                  644
biotype     758    CA      "C-Terminal AIB"                  645
biotype     759    C       "C-Terminal AIB"                  646
biotype     760    HN      "C-Terminal AIB"                  647
biotype     761    OXT     "C-Terminal AIB"                  648
biotype     762    N       "Deprotonated N-Terminus"          -1
biotype     763    H       "Deprotonated N-Terminus"          -1
biotype     764    C       "Formyl N-Terminus"               337
biotype     765    H       "Formyl N-Terminus"               338
biotype     766    O       "Formyl N-Terminus"               339
biotype     767    CH3     "Acetyl N-Terminus"               340
biotype     768    H       "Acetyl N-Terminus"               341
biotype     769    C       "Acetyl N-Terminus"               342
biotype     770    O       "Acetyl N-Terminus"               343
biotype     771    C       "Protonated C-Terminus"            -1
biotype     772    O       "Protonated C-Terminus"            -1
biotype     773    OH      "Protonated C-Terminus"            -1
biotype     774    HO      "Protonated C-Terminus"            -1
biotype     775    N       "Amide C-Terminus"                344
biotype     776    HN      "Amide C-Terminus"                345
biotype     777    N       "N-MeAmide C-Terminus"            346
biotype     778    HN      "N-MeAmide C-Terminus"            347
biotype     779    CH3     "N-MeAmide C-Terminus"            348
biotype     780    H       "N-MeAmide C-Terminus"            349
biotype    1001    O5*     "Adenosine"                      1001
biotype    1002    C5*     "Adenosine"                      1002
biotype    1003    H5*1    "Adenosine"                      1003
biotype    1004    H5*2    "Adenosine"                      1004
biotype    1005    C4*     "Adenosine"                      1005
biotype    1006    H4*     "Adenosine"                      1006
biotype    1007    O4*     "Adenosine"                      1007
biotype    1008    C1*     "Adenosine"                      1008
biotype    1009    H1*     "Adenosine"                      1009
biotype    1010    C3*     "Adenosine"                      1010
biotype    1011    H3*     "Adenosine"                      1011
biotype    1012    C2*     "Adenosine"                      1012
biotype    1013    H2*     "Adenosine"                      1013
biotype    1014    O2*     "Adenosine"                      1014
biotype    1015    HO*     "Adenosine"                      1015
biotype    1016    O3*     "Adenosine"                      1016
biotype    1017    N9      "Adenosine"                      1017
biotype    1018    C4      "Adenosine"                      1018
biotype    1019    C5      "Adenosine"                      1019
biotype    1020    N7      "Adenosine"                      1020
biotype    1021    C8      "Adenosine"                      1021
biotype    1022    N3      "Adenosine"                      1022
biotype    1023    C2      "Adenosine"                      1023
biotype    1024    N1      "Adenosine"                      1024
biotype    1025    C6      "Adenosine"                      1025
biotype    1026    H2      "Adenosine"                      1026
biotype    1027    N6      "Adenosine"                      1027
biotype    1028    H61     "Adenosine"                      1028
biotype    1029    H62     "Adenosine"                      1029
biotype    1030    H8      "Adenosine"                      1030
biotype    1031    O5*     "Guanosine"                      1031
biotype    1032    C5*     "Guanosine"                      1032
biotype    1033    H5*1    "Guanosine"                      1033
biotype    1034    H5*2    "Guanosine"                      1034
biotype    1035    C4*     "Guanosine"                      1035
biotype    1036    H4*     "Guanosine"                      1036
biotype    1037    O4*     "Guanosine"                      1037
biotype    1038    C1*     "Guanosine"                      1038
biotype    1039    H1*     "Guanosine"                      1039
biotype    1040    C3*     "Guanosine"                      1040
biotype    1041    H3*     "Guanosine"                      1041
biotype    1042    C2*     "Guanosine"                      1042
biotype    1043    H2*     "Guanosine"                      1043
biotype    1044    O2*     "Guanosine"                      1044
biotype    1045    HO*     "Guanosine"                      1045
biotype    1046    O3*     "Guanosine"                      1046
biotype    1047    N9      "Guanosine"                      1047
biotype    1048    C4      "Guanosine"                      1048
biotype    1049    C5      "Guanosine"                      1049
biotype    1050    N7      "Guanosine"                      1050
biotype    1051    C8      "Guanosine"                      1051
biotype    1052    N3      "Guanosine"                      1052
biotype    1053    C2      "Guanosine"                      1053
biotype    1054    N1      "Guanosine"                      1054
biotype    1055    C6      "Guanosine"                      1055
biotype    1056    H1      "Guanosine"                      1056
biotype    1057    N2      "Guanosine"                      1057
biotype    1058    H21     "Guanosine"                      1058
biotype    1059    H22     "Guanosine"                      1059
biotype    1060    O6      "Guanosine"                      1060
biotype    1061    H8      "Guanosine"                      1061
biotype    1062    O5*     "Cytidine"                       1062
biotype    1063    C5*     "Cytidine"                       1063
biotype    1064    H5*1    "Cytidine"                       1064
biotype    1065    H5*2    "Cytidine"                       1065
biotype    1066    C4*     "Cytidine"                       1066
biotype    1067    H4*     "Cytidine"                       1067
biotype    1068    O4*     "Cytidine"                       1068
biotype    1069    C1*     "Cytidine"                       1069
biotype    1070    H1*     "Cytidine"                       1070
biotype    1071    C3*     "Cytidine"                       1071
biotype    1072    H3*     "Cytidine"                       1072
biotype    1073    C2*     "Cytidine"                       1073
biotype    1074    H2*     "Cytidine"                       1074
biotype    1075    O2*     "Cytidine"                       1075
biotype    1076    HO*     "Cytidine"                       1076
biotype    1077    O3*     "Cytidine"                       1077
biotype    1078    N1      "Cytidine"                       1078
biotype    1079    C2      "Cytidine"                       1079
biotype    1080    N3      "Cytidine"                       1080
biotype    1081    C4      "Cytidine"                       1081
biotype    1082    C5      "Cytidine"                       1082
biotype    1083    C6      "Cytidine"                       1083
biotype    1084    O2      "Cytidine"                       1084
biotype    1085    N4      "Cytidine"                       1085
biotype    1086    H41     "Cytidine"                       1086
biotype    1087    H42     "Cytidine"                       1087
biotype    1088    H5      "Cytidine"                       1088
biotype    1089    H6      "Cytidine"                       1089
biotype    1090    O5*     "Uridine"                        1090
biotype    1091    C5*     "Uridine"                        1091
biotype    1092    H5*1    "Uridine"                        1092
biotype    1093    H5*2    "Uridine"                        1093
biotype    1094    C4*     "Uridine"                        1094
biotype    1095    H4*     "Uridine"                        1095
biotype    1096    O4*     "Uridine"                        1096
biotype    1097    C1*     "Uridine"                        1097
biotype    1098    H1*     "Uridine"                        1098
biotype    1099    C3*     "Uridine"                        1099
biotype    1100    H3*     "Uridine"                        1100
biotype    1101    C2*     "Uridine"                        1101
biotype    1102    H2*     "Uridine"                        1102
biotype    1103    O2*     "Uridine"                        1103
biotype    1104    HO*     "Uridine"                        1104
biotype    1105    O3*     "Uridine"                        1105
biotype    1106    N1      "Uridine"                        1106
biotype    1107    C2      "Uridine"                        1107
biotype    1108    N3      "Uridine"                        1108
biotype    1109    C4      "Uridine"                        1109
biotype    1110    C5      "Uridine"                        1110
biotype    1111    C6      "Uridine"                        1111
biotype    1112    O2      "Uridine"                        1112
biotype    1113    H3      "Uridine"                        1113
biotype    1114    O4      "Uridine"                        1114
biotype    1115    H5      "Uridine"                        1115
biotype    1116    H6      "Uridine"                        1116
biotype    1117    O5*     "Deoxyadenosine"                 1117
biotype    1118    C5*     "Deoxyadenosine"                 1118
biotype    1119    H5*1    "Deoxyadenosine"                 1119
biotype    1120    H5*2    "Deoxyadenosine"                 1120
biotype    1121    C4*     "Deoxyadenosine"                 1121
biotype    1122    H4*     "Deoxyadenosine"                 1122
biotype    1123    O4*     "Deoxyadenosine"                 1123
biotype    1124    C1*     "Deoxyadenosine"                 1124
biotype    1125    H1*     "Deoxyadenosine"                 1125
biotype    1126    C3*     "Deoxyadenosine"                 1126
biotype    1127    H3*     "Deoxyadenosine"                 1127
biotype    1128    C2*     "Deoxyadenosine"                 1128
biotype    1129    H2*1    "Deoxyadenosine"                 1129
biotype    1130    H2*2    "Deoxyadenosine"                 1130
biotype    1131    O3*     "Deoxyadenosine"                 1131
biotype    1132    N9      "Deoxyadenosine"                 1132
biotype    1133    C4      "Deoxyadenosine"                 1133
biotype    1134    C5      "Deoxyadenosine"                 1134
biotype    1135    N7      "Deoxyadenosine"                 1135
biotype    1136    C8      "Deoxyadenosine"                 1136
biotype    1137    N3      "Deoxyadenosine"                 1137
biotype    1138    C2      "Deoxyadenosine"                 1138
biotype    1139    N1      "Deoxyadenosine"                 1139
biotype    1140    C6      "Deoxyadenosine"                 1140
biotype    1141    H2      "Deoxyadenosine"                 1141
biotype    1142    N6      "Deoxyadenosine"                 1142
biotype    1143    H61     "Deoxyadenosine"                 1143
biotype    1144    H62     "Deoxyadenosine"                 1144
biotype    1145    H8      "Deoxyadenosine"                 1145
biotype    1146    O5*     "Deoxyguanosine"                 1146
biotype    1147    C5*     "Deoxyguanosine"                 1147
biotype    1148    H5*1    "Deoxyguanosine"                 1148
biotype    1149    H5*2    "Deoxyguanosine"                 1149
biotype    1150    C4*     "Deoxyguanosine"                 1150
biotype    1151    H4*     "Deoxyguanosine"                 1151
biotype    1152    O4*     "Deoxyguanosine"                 1152
biotype    1153    C1*     "Deoxyguanosine"                 1153
biotype    1154    H1*     "Deoxyguanosine"                 1154
biotype    1155    C3*     "Deoxyguanosine"                 1155
biotype    1156    H3*     "Deoxyguanosine"                 1156
biotype    1157    C2*     "Deoxyguanosine"                 1157
biotype    1158    H2*1    "Deoxyguanosine"                 1158
biotype    1159    H2*2    "Deoxyguanosine"                 1159
biotype    1160    O3*     "Deoxyguanosine"                 1160
biotype    1161    N9      "Deoxyguanosine"                 1161
biotype    1162    C4      "Deoxyguanosine"                 1162
biotype    1163    C5      "Deoxyguanosine"                 1163
biotype    1164    N7      "Deoxyguanosine"                 1164
biotype    1165    C8      "Deoxyguanosine"                 1165
biotype    1166    N3      "Deoxyguanosine"                 1166
biotype    1167    C2      "Deoxyguanosine"                 1167
biotype    1168    N1      "Deoxyguanosine"                 1168
biotype    1169    C6      "Deoxyguanosine"                 1169
biotype    1170    H1      "Deoxyguanosine"                 1170
biotype    1171    N2      "Deoxyguanosine"                 1171
biotype    1172    H21     "Deoxyguanosine"                 1172
biotype    1173    H22     "Deoxyguanosine"                 1173
biotype    1174    O6      "Deoxyguanosine"                 1174
biotype    1175    H8      "Deoxyguanosine"                 1175
biotype    1176    O5*     "Deoxycytidine"                  1176
biotype    1177    C5*     "Deoxycytidine"                  1177
biotype    1178    H5*1    "Deoxycytidine"                  1178
biotype    1179    H5*2    "Deoxycytidine"                  1179
biotype    1180    C4*     "Deoxycytidine"                  1180
biotype    1181    H4*     "Deoxycytidine"                  1181
biotype    1182    O4*     "Deoxycytidine"                  1182
biotype    1183    C1*     "Deoxycytidine"                  1183
biotype    1184    H1*     "Deoxycytidine"                  1184
biotype    1185    C3*     "Deoxycytidine"                  1185
biotype    1186    H3*     "Deoxycytidine"                  1186
biotype    1187    C2*     "Deoxycytidine"                  1187
biotype    1188    H2*1    "Deoxycytidine"                  1188
biotype    1189    H2*2    "Deoxycytidine"                  1189
biotype    1190    O3*     "Deoxycytidine"                  1190
biotype    1191    N1      "Deoxycytidine"                  1191
biotype    1192    C2      "Deoxycytidine"                  1192
biotype    1193    N3      "Deoxycytidine"                  1193
biotype    1194    C4      "Deoxycytidine"                  1194
biotype    1195    C5      "Deoxycytidine"                  1195
biotype    1196    C6      "Deoxycytidine"                  1196
biotype    1197    O2      "Deoxycytidine"                  1197
biotype    1198    N4      "Deoxycytidine"                  1198
biotype    1199    H41     "Deoxycytidine"                  1199
biotype    1200    H42     "Deoxycytidine"                  1200
biotype    1201    H5      "Deoxycytidine"                  1201
biotype    1202    H6      "Deoxycytidine"                  1202
biotype    1203    O5*     "Deoxythymidine"                 1203
biotype    1204    C5*     "Deoxythymidine"                 1204
biotype    1205    H5*1    "Deoxythymidine"                 1205
biotype    1206    H5*2    "Deoxythymidine"                 1206
biotype    1207    C4*     "Deoxythymidine"                 1207
biotype    1208    H4*     "Deoxythymidine"                 1208
biotype    1209    O4*     "Deoxythymidine"                 1209
biotype    1210    C1*     "Deoxythymidine"                 1210
biotype    1211    H1*     "Deoxythymidine"                 1211
biotype    1212    C3*     "Deoxythymidine"                 1212
biotype    1213    H3*     "Deoxythymidine"                 1213
biotype    1214    C2*     "Deoxythymidine"                 1214
biotype    1215    H2*1    "Deoxythymidine"                 1215
biotype    1216    H2*2    "Deoxythymidine"                 1216
biotype    1217    O3*     "Deoxythymidine"                 1217
biotype    1218    N1      "Deoxythymidine"                 1218
biotype    1219    C2      "Deoxythymidine"                 1219
biotype    1220    N3      "Deoxythymidine"                 1220
biotype    1221    C4      "Deoxythymidine"                 1221
biotype    1222    C5      "Deoxythymidine"                 1222
biotype    1223    C6      "Deoxythymidine"                 1223
biotype    1224    O2      "Deoxythymidine"                 1224
biotype    1225    H3      "Deoxythymidine"                 1225
biotype    1226    O4      "Deoxythymidine"                 1226
biotype    1227    C7      "Deoxythymidine"                 1227
biotype    1228    H7      "Deoxythymidine"                 1228
biotype    1229    H6      "Deoxythymidine"                 1229
biotype    1230    P       "Phosphodiester RNA"             1230
biotype    1231    OP      "Phosphodiester RNA"             1231
biotype    1232    O5*     "5'-Hydroxyl RNA"                1232
biotype    1233    H5T     "5'-Hydroxyl RNA"                1233
biotype    1234    O5*     "5'-Monophosphate OS RNA"        1234
biotype    1235    P       "5'-Monophosphate P RNA"         1235
biotype    1236    OP      "5'-Monophosphate OP RNA"        1236
biotype    1237    O3*     "3'-Hydroxyl RNA"                1237
biotype    1238    H3T     "3'-Hydroxyl RNA"                1238
biotype    1239    O3*     "3'-Monophosphate OS RNA"        1239
biotype    1240    P       "3'-Monophosphate P RNA"         1240
biotype    1241    OP      "3'-Monophosphate OP RNA"        1241
biotype    1242    P       "Phosphodiester DNA"             1242
biotype    1243    OP      "Phosphodiester DNA"             1243
biotype    1244    O5*     "5'-Hydroxyl DNA"                1244
biotype    1245    H5T     "5'-Hydroxyl DNA"                1245
biotype    1246    O5*     "5'-Monophosphate OS DNA"        1246
biotype    1247    P       "5'-Monophosphate P DNA"         1247
biotype    1248    OP      "5'-Monophosphate OP DNA"        1248
biotype    1249    O3*     "3'-Hydroxyl DNA"                1249
biotype    1250    H3T     "3'-Hydroxyl DNA"                1250
biotype    1251    O3*     "3'-Monophosphate OS DNA"        1251
biotype    1252    P       "3'-Monophosphate P DNA"         1252
biotype    1253    OP      "3'-Monophosphate OP DNA"        1253
biotype    2001    O       "Water"                          2001
biotype    2002    H       "Water"                          2002
biotype    2003    LI      "Lithium Ion"                    2003
biotype    2004    NA      "Sodium Ion"                     2004
biotype    2005    K       "Potassium Ion"                  2005
biotype    2006    RB      "Rubidium Ion"                   2006
biotype    2007    CS      "Cesium Ion"                     2007
biotype    2008    MG      "Magnesium Ion"                  2008
biotype    2009    CA      "Calcium Ion"                    2009
biotype    2010    SR      "Strontium Ion"                  2010
biotype    2011    BA      "Barium Ion"                     2011
biotype    2013    CL      "Chloride Ion"                   2012
)**";
}
