#include "builtin.hpp"
#include "os/__init__.hpp"
#include "sys.hpp"
#include "os/path.hpp"
#include "stat.hpp"
#include "group_proj.hpp"

namespace __group_proj__ {

str *const_0, *const_1, *const_10, *const_11, *const_12, *const_13, *const_14, *const_15, *const_16, *const_17, *const_18, *const_19, *const_2, *const_3, *const_4, *const_5, *const_6, *const_7, *const_8, *const_9;


list<list<str *> *> *grid;
str *__name__;


static inline list<str *> *list_comp_0();
static inline list<list<str *> *> *list_comp_1();

static inline list<str *> *list_comp_0() {
    __ss_int __5, __6, x;

    list<str *> *__ss_result = new list<str *>();

    FAST_FOR(x,0,32,1,5,6)
        __ss_result->append(const_0);
    END_FOR

    return __ss_result;
}

static inline list<list<str *> *> *list_comp_1() {
    __ss_int __3, __4, y;

    list<list<str *> *> *__ss_result = new list<list<str *> *>();

    FAST_FOR(y,0,32,1,3,4)
        __ss_result->append(list_comp_0());
    END_FOR

    return __ss_result;
}

void *print_err(str *cmd) {
    
    print2(NULL,0,1, __add_strs(3, const_1, cmd, const_2));
    return NULL;
}

void *print_grid() {
    list<str *> *__11, *row;
    list<list<str *> *>::for_in_loop __10;
    list<str *>::for_in_loop __14;
    str *col, *s;
    __iter<list<str *> *> *__8;
    __iter<str *> *__12;
    list<list<str *> *> *__7;
    __ss_int __13, __9;


    FOR_IN(row,grid,7,9,10)
        s = const_3;

        FOR_IN(col,row,11,13,14)
            s = (s)->__iadd__(col);
        END_FOR

        print2(NULL,0,1, s);
    END_FOR

    return NULL;
}

void *draw_filled_box(__ss_int x, __ss_int y, __ss_int w, __ss_int h) {
    list<str *> *__27;
    __ss_bool __15, __16, __17, __18, __19, __20, __21, __22;
    __ss_int __23, __24, __25, __26, i, j, tally;

    if (((x<0) or (y<0) or (w<1) or (h<1))) {
        return NULL;
    }
    if (((y>len(grid)) or (x>len(grid->__getfast__(0))) or ((y+w)>len(grid)) or ((x+h)>len(grid->__getfast__(0))))) {
        return NULL;
    }
    tally = 0;

    FAST_FOR(i,0,h,1,23,24)

        FAST_FOR(j,0,w,1,25,26)
            grid->__getfast__((y+j))->__setitem__((x+i), const_4);
        END_FOR

    END_FOR

    return 0;
}

void *draw_empty_box(__ss_int x, __ss_int y, __ss_int w, __ss_int h) {
    list<str *> *__42, *__45;
    __ss_bool __28, __29, __30, __31, __32, __33, __34, __35, __40, __41, __43, __44;
    __ss_int __36, __37, __38, __39, i, j;

    if (((x<0) or (y<0) or (w<1) or (h<1))) {
        return NULL;
    }
    if (((y>len(grid)) or (x>len(grid->__getfast__(0))) or ((y+w)>len(grid)) or ((x+h)>len(grid->__getfast__(0))))) {
        return NULL;
    }

    FAST_FOR(i,0,h,1,36,37)

        FAST_FOR(j,0,w,1,38,39)
            if (((i==0) or (i==(h-1)))) {
                grid->__getfast__((y+j))->__setitem__((x+i), const_4);
            }
            else if (((j==0) or (j==(w-1)))) {
                grid->__getfast__((y+j))->__setitem__((x+i), const_4);
            }
        END_FOR

        print2(NULL,0,1, const_3);
    END_FOR

    return 0;
}

void *draw_diagonal(__ss_int x, __ss_int y, __ss_int size, str *dir) {
    list<str *> *__51, *__56;
    __ss_bool __46, __47, __48, __49, __50;
    __ss_int __52, __53, __54, __55, i, j;

    if (((x<1) or (y<1) or (size<1) or ((y+size)>len(grid)) or ((x+size)>len(grid->__getfast__(0))))) {
        return NULL;
    }
    if ((dir)->__contains__(const_5)) {
        i = 0;

        while ((i<size)) {
            j = size;

            while ((j>=0)) {
                if ((i==j)) {
                    grid->__getfast__((y+j))->__setitem__((x-i), const_6);
                }
                j = (j-1);
            }
            i = (i+1);
        }
    }
    else {

        FAST_FOR(i,0,size,1,52,53)

            FAST_FOR(j,0,size,1,54,55)
                if ((i==j)) {
                    grid->__getfast__((y+j))->__setitem__((x+i), const_7);
                }
            END_FOR

        END_FOR

    }
    return 0;
}

void *draw_vertical(__ss_int x, __ss_int y, __ss_int size) {
    __ss_int __61, __62, i;
    list<str *> *__63;
    __ss_bool __57, __58, __59, __60;

    if (((x<1) or (y<1) or (size<1) or ((y+size)>len(grid)))) {
        return NULL;
    }

    FAST_FOR(i,0,size,1,61,62)
        grid->__getfast__((y+i))->__setitem__(x, const_8);
    END_FOR

    return 0;
}

void *draw_horizontal(__ss_int x, __ss_int y, __ss_int size) {
    list<str *> *__70;
    __ss_bool __64, __65, __66, __67;
    __ss_int __68, __69, i;

    if (((x<1) or (y<1) or (size<1) or ((x+size)>len(grid->__getfast__(0))))) {
        return NULL;
    }

    FAST_FOR(i,0,size,1,68,69)
        grid->__getfast__(y)->__setitem__((x+i), const_9);
    END_FOR

    return 0;
}

void *fill(__ss_int x, __ss_int y, str *__ss_char) {
    list<str *> *__73;
    __ss_bool __71, __72;

    if (((x<1) or (y<1))) {
        return NULL;
    }
    if (__eq((grid->__getfast__(y))->__getfast__(x), const_0)) {
        grid->__getfast__(y)->__setitem__(x, __ss_char);
    }
    try {
        if (__eq((grid->__getfast__((y-1)))->__getfast__(x), const_0)) {
            fill(x, (y-1), __ss_char);
        }
    } catch (IndexError *) {
    }
    try {
        if (__eq((grid->__getfast__((y+1)))->__getfast__(x), const_0)) {
            fill(x, (y+1), __ss_char);
        }
    } catch (IndexError *) {
    }
    try {
        if (__eq((grid->__getfast__(y))->__getfast__((x-1)), const_0)) {
            fill((x-1), y, __ss_char);
        }
    } catch (IndexError *) {
    }
    try {
        if (__eq((grid->__getfast__(y))->__getfast__((x+1)), const_0)) {
            fill((x+1), y, __ss_char);
        }
    } catch (IndexError *) {
    }
    return 0;
}

void *__ss_main() {
    list<str *> *__78, *parts;
    list<str *>::for_in_loop __81;
    __ss_bool __84, __85, __86, __87, __88, __89, __90, __91, __92, __93, __94, __95;
    str *cmd;
    file *__83, *_file;
    __iter<str *> *__79;
    __ss_int __80;
    void *__82;

    _file = open(const_10, const_11);

    FOR_IN(cmd,_file->readlines(),78,80,81)
        parts = ((cmd->lower())->replace(const_0, const_3))->split(const_12);
        if (((parts->__getfast__(0))->__contains__(const_13) and (len(parts)==4))) {
            draw_horizontal(__int(parts->__getfast__(1)), __int(parts->__getfast__(2)), __int(parts->__getfast__(3)));
        }
        else if (((parts->__getfast__(0))->__contains__(const_14) and (len(parts)==4))) {
            draw_vertical(__int(parts->__getfast__(1)), __int(parts->__getfast__(2)), __int(parts->__getfast__(3)));
        }
        else if (((parts->__getfast__(0))->__contains__(const_15) and (len(parts)==5))) {
            draw_diagonal(__int(parts->__getfast__(1)), __int(parts->__getfast__(2)), __int(parts->__getfast__(3)), parts->__getfast__(4));
        }
        else if (((parts->__getfast__(0))->__contains__(const_16) and (len(parts)==5))) {
            draw_empty_box(__int(parts->__getfast__(1)), __int(parts->__getfast__(2)), __int(parts->__getfast__(3)), __int(parts->__getfast__(4)));
        }
        else if (((parts->__getfast__(0))->__contains__(const_17) and (len(parts)==5))) {
            draw_filled_box(__int(parts->__getfast__(1)), __int(parts->__getfast__(2)), __int(parts->__getfast__(3)), __int(parts->__getfast__(4)));
        }
        else if (((parts->__getfast__(0))->__contains__(const_18) and (len(parts)==4))) {
            fill(__int(parts->__getfast__(1)), __int(parts->__getfast__(2)), (parts->__getfast__(3))->__getfast__(0));
        }
        else {
            print_err(cmd);
        }
    END_FOR

    print_grid();
    return NULL;
}

void __init() {
    const_0 = __char_cache[32];;
    const_1 = new str("Command: ");
    const_2 = new str(" not found");
    const_3 = new str("");
    const_4 = __char_cache[35];;
    const_5 = new str("right");
    const_6 = __char_cache[47];;
    const_7 = __char_cache[92];;
    const_8 = __char_cache[124];;
    const_9 = __char_cache[45];;
    const_10 = new str("../instructions.txt");
    const_11 = __char_cache[114];;
    const_12 = __char_cache[44];;
    const_13 = new str("draw_horizontal_line");
    const_14 = new str("draw_vertical_line");
    const_15 = new str("draw_diagonal_line");
    const_16 = new str("draw_empty_box");
    const_17 = new str("draw_filled_box");
    const_18 = new str("fill");
    const_19 = new str("__main__");

    __name__ = new str("__main__");

    grid = list_comp_1();
    if (__eq(__name__, const_19)) {
        __ss_main();
    }
}

} // module namespace

int main(int __ss_argc, char **__ss_argv) {
    __shedskin__::__init();
    __stat__::__init();
    __os__::__path__::__init();
    __os__::__init();
    __sys__::__init(__ss_argc, __ss_argv);
    __shedskin__::__start(__group_proj__::__init);
}
