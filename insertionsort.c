#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, j;
    int key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++){
        printf("%d ,  ", arr[i]);
    }
    printf("\n");
}

int main () {
    clock_t start_t , end_t ;
    double total_t ;
    start_t = clock () ;


    int arr[] = {324110, -442472, 626686, -157678, 508681, 123414, -77867, 155091, 129801, 287381, 604242, 686904, -247109, 77867, 982455, -210707, -922943, -738817, 85168, 855430, -365580, -174307, -28560, 888769, -887534, -563503, 752524, 777031, 385644, -768774, 211244, 792814, -475905, 968127, -504909, 570656, -458444, -957331, 259322, -648617, 451074, 858015, 849248, -361918, -683640, -449851, -363749, -425926, 418216, -609284, 460009, 331758, -600376, 325398, 279751, 592222, 309723, 52921, 600291, 799037, 836049, -190454, 13962, -714343, 696033, -403836, -712535, 604362, -847079, -30113, 823044, -574291, -72109, 719281, -963727, -769033, -600693, -247829, -781838, -313995, 911682, 347184, -212857, 63665, 261049, -445002, 486913, 372622, 980111, 982505, -951004, 954267, 915640, -547139, -885732, -774826, -227720, -893313, 795588, 971211, 791015, 394414, 164076, -859625, 537219, -892930, -845554, -565040, 892346, 102526, 910215, -830346, 774953, -293457, -572511, -159280, -139108, -97334, 506426, 642376, 629152, 372320, -517648, -229939, 428961, -793788, -16086, 766244, -54579, -319593, -946477, 392983, 435056, 875219, -634233, 556428, -590678, 112319, 992315, -337996, -936733, -804778, -812737, 444997, -321854, 260607, -995238, -200178, -529036, 682635, 211115, -577791, 920543, -80231, 916493, 182127, -531138, 453301, -373267, 61223, -321958, 39091, -996360, -782894, 417514, -621224, 522552, 277801, 462527, 13993, -571145, -676773, -995703, -243121, -79501, -823446, 3752, -707560, -678513, -393162, -935044, -276906, -838348, 835297, 560932, 772977, 540991, -658828, -886234, -870617, 932155, 379079, -787514, -29053, -337377, -151704, -253629, 116961, -281535, -804548, 537990, 429475, 224490, 885580, -420629, 109608, 980970, 642530, 606412, 351747, -224986, 138245, 890709, -545923, 835064, 101415, 684676, -68820, 759875, 919553, 624935, 434153, 528724, -275460, -419373, -643979, 787492, -319799, 927391, 884937, 505657, 731506, 34460, -35046, 312107, -571519, -128606, 133913, -656907, 603957, -927326, -469740, 273535, -337231, -457525, -504646, -646744, -968928, 738608, -854881, 732644, -82093, -856265, 44642, -862390, 957227, 113632, -308416, 41615, 527037, -713618, 899052, -117086, -416608, 43048, 365817, 588070, 700452, 129509, -268428, 688173, 673832, 480764, 237135, -347900, 523029, 533184, -255682, 711522, 19655, 866805, 317427, 415281, -28199, -111100, -171898, 426130, 410799, 451727, 117522, 660726, 555231, 791462, -865279, 774168, 967991, -18011, -832957, -796763, -324240, -783640, -211464, -492085, 186262, 660350, 474337, 588629, 317172, -633289, -36117, 507060, 541570, 795353, -596978, -898727, -841635, 853802, 54901, 361258, -987905, -946036, -58272, -381063, 715065, 375327, -835676, -992987, 365767, -268590, 843587, -646024, -388939, 555361, -362188, -292056, 565601, -47693, 612036, -980069, -419480, -889860, -129634, 167493, 144380, -782888, 809497, 462622, 302939, 3713, 111411, -936854, -99730, 207982, -334505, 294760, -327691, 757517, 495093, 791226, -235083, 268094, 460776, -426822, -397962, 577958, -977640, -288684, 195591, -531517, -336007, 57722, -32795, 466030, -278615, -320623, -57055, -323521, 297510, 90864, -214291, 973069, -287099, -841365, 545938, -460220, 508901, -362886, -760131, -233322, 407003, 697277, 405503, 800247, -175302, 521278, 640041, -329103, 557979, 62036, -211495, -148533, 62953, 404633, 931814, 344681, -596255, 816725, 613568, 954160, 381175, -461917, 848349, -737258, 616425, 634774, -629685, 23476, 436204, -168651, 309422, 162829, 290661, 134845, 23600, 402262, 132590, 277263, 168729, -376511, 696201, -471425, 254285, 534350, 936035, -729767, 911027, 936398, 21331, 869514, 888131, -48071, 228453, 857928, -599335, 937300, 833713, 192333, 864355, 491077, 681232, 465256, -716939, -40371, 485202, 331339, 595432, 149488, -876765, 129696, -859289, -425124, -812820, -292618, -930317, -499507, -119878, -212959, -994740, -716238, -17003, 872209, 548234, -922602, 61542, -353374, 327228, -177725, -655935, -900680, -792106, 642240, 772772, -804914, -995066, -753357, -383827, -189595, 581514, -247009, 727345, 867724, -425815, 461296, -957420, 126403, -852597, -456706, -762747, 926542, -839699, -646113, -409543, 332271, -80657, 128780, 57270, 584000, 294023, -798573, -692763, -455503, 388789, 554045, 59963, 911562, 192881, -488395, 433430, 370450, -329206, 694324, -782042, -427901, 609580, -36651, 998473, -151404, 205241, -974048, 870014, -84797, 848956, 610693, 126179, 458679, -135078, 679658, -252520, -525516, -944917, 14012, -223666, -509104, 822059, 690752, -262316, -594101, -629916, -537314, 149020, -436848, 24792, -139712, -139176, 906191, -933803, -46738, 478221, -424557, 635225, -858766, -563074, -849510, 252687, -912832, -558731, -109559, 280581, 963744, -80572, -211861, -740864, -447956, -89299, 29332, 469027, 413574, -628054, -464183, -703305, -649243, -724916, -328020, 21738, -322299, 64798, 907006, 498846, 442156, -944626, 250472, -127244, -328763, 167838, -383120, -56748, 957635, 43367, 925113, -911790, -740346, -983833, -298332, 756239, 657567, -311188, -768080, 456458, 990436, -74716, -108444, -98513, -208341, 961734, -809296, 500720, 748165, -967768, -723803, 754493, 27309, 416553, 162767, -734249, -752843, -860684, 801881, -935652, 610017, -315464, 247311, -269875, -224334, 36942, -360570, -595578, -580087, -878838, 505594, -804297, -894253, -717857, -38107, -286508, -911536, 834955, 801917, -494182, 982827, -90639, 171085, 28894, 839425, 824349, 550487, -556223, 109057, 50036, -887957, 13249, -781897, 449152, 157230, -836793, -965512, -62421, 314459, 376329, -627027, -36842, -554384, -998166, 870161, 274276, -199842, -206363, -946257, -665512, -144455, -469754, -762852, 436698, -504329, -576758, -10101, 80208, -295622, 187200, -634375, -503829, 788979, -377552, -186188, 341795, 299160, 353040, 758024, -469125, -730521, -34140, 192459, -71993, -810902, -787207, 330345, -793873, 190249, 166391, -668168, 551724, -652633, -739504, -554333, 99424, 691654, 799, -481921, 987322, -428705, 796319, 753946, 746786, -674624, 841298, 859462, -624859, -110004, -731945, -747859, -113011, -82083, -105195, 893174, -600389, 268512, -191476, 478744, 880226, -687353, 751400, 221096, -432403, -602473, -179527, -743232, -222225, -970557, 343548, 838535, -686477, 857710, 960511, 899267, 19224, -618988, 917652, 320032, 157851, 447761, 373669, -708568, -766164, -915079, 119494, -473727, 645453, 965213, -469880, 763345, 122580, -89569, 795133, -3804, 290466, -770946, -484360, -832555, -102563, 399179, 608824, -311674, 254169, 633233, 127369, 74759, -745498, -801226, 79503, 235431, 982460, -979884, 626428, 503981, 357470, -951626, 137429, -623468, -470509, 162945, 498960, -902553, -191940, 955297, 802520, 730353, -205982, -353629, -922841, 158067, -920065, 601743, -914042, -425739, -604961, 434126, -628156, -538714, -607305, -479330, 716626, -207239, -586727, -87121, -31858, 256135, 502483, 79912, 793931, -340389, -274955, 701364, -664149, 369421, -614205, -186429, 968590, 617616, -844854, 13820, -593972, -172856, -706976, -860224, -747081, -279833, 175220, 866819, -234617, 907170, 148332, -996154, -937783, 898582, 374249, 918540, 320032, -962741, -227609, -514064, 588778, 719321, -572308, -770447, 780168, -547520, -95438, 912225, 110116, 795126, 791849, -265833, -182776, -973906, -498923, -491303, -667047, -485843, -149999, 711423, -754924, -812044, 285786, 136603, -625465, 251183, 736897, 44775, -923132, 344513, 30024, -851367, 482843, -275108, 568155, 559533, -191003, 714442, -461824, 904890, -902746, 665382, 301119, 227126, 783842, 994005, -184519, -12288, 351224, -544108, -46241, 525250, -17212, 766177, 394661, -345589, 618544, -87160, 408165, 742963, -898893, -932391, 297920, -433014, -795259, 868234, 525192, 519784, 256271, 27498, -389121, 337879, 785184, -281493, 796831, -592129, -818759, 992407, 145021, 930836, 691455, 603847, -737143, 746326, 254306, -948879, 165187, -544075, -352451, 382087, -81671, -363300, -782961, 373581, 658712, 397791, -942537, 61204, 338489, -691244, -68085, -722026, -877264, -183806, 445749, -145489, -252366, 665551, 31175, 440030, -653723, 557902, -847432, 522581, -741474, 296906, 808478, 158597, 163608, 19000, 884840, 165980, 508884, 750319, -795078, -908450, 655522, -503323, 225022, 132875, -578453, -651611, 240984, -623898, -224982, 669548, 699096, 205562, 314844, 341808, 745942};

    printf("Tableau non trie: \n");
    printArray(arr, 1000);

    insertionSort(arr, 1000);
    printf("Tableau trie avec Bubble Sort: \n");
    printArray(arr, 1000);




    end_t = clock () ;

    total_t = ( double ) ( end_t - start_t ) / CLOCKS_PER_SEC ;
    printf (" Total time taken by CPU: %f\n", total_t ) ;
    return (0) ;
}