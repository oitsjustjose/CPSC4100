#ifndef __GROUP_PROJ_HPP
#define __GROUP_PROJ_HPP

using namespace __shedskin__;
namespace __group_proj__ {

extern str *const_0, *const_1, *const_10, *const_11, *const_12, *const_13, *const_14, *const_15, *const_16, *const_17, *const_18, *const_19, *const_2, *const_3, *const_4, *const_5, *const_6, *const_7, *const_8, *const_9;



extern list<list<str *> *> *grid;
extern str *__name__;


void *print_err(str *cmd);
void *print_grid();
void *draw_filled_box(__ss_int x, __ss_int y, __ss_int w, __ss_int h);
void *draw_empty_box(__ss_int x, __ss_int y, __ss_int w, __ss_int h);
void *draw_diagonal(__ss_int x, __ss_int y, __ss_int size, str *dir);
void *draw_vertical(__ss_int x, __ss_int y, __ss_int size);
void *draw_horizontal(__ss_int x, __ss_int y, __ss_int size);
void *fill(__ss_int x, __ss_int y, str *__ss_char);
void *__ss_main();

} // module namespace
#endif
