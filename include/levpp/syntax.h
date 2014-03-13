#ifndef __LEVPP_SYNTAX_H_
#define __LEVPP_SYNTAX_H_

extern void syntax_error(char *str);

extern int check_braces(char *buf);
extern int check_markers(char *buf);

extern int syntax_check(char *buf);

#endif
