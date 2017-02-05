/* Generated by re2c 0.14.3 on Sat Feb  4 13:15:42 2017 */
/**

	MultiMarkdown 6 -- Lightweight markup processor to produce HTML, LaTeX, and more.

	@file lexer.re

	@brief Description of the regular expressions used to define tokens, 
	used by re2c to create a lexer/tokenizer.


	@author	Fletcher T. Penney
	@bug	

**/

/*

	Copyright © 2016 - 2017 Fletcher T. Penney.


	The `MultiMarkdown 6` project is released under the MIT License..
	
	GLibFacade.c and GLibFacade.h are from the MultiMarkdown v4 project:
	
		https://github.com/fletcher/MultiMarkdown-4/
	
	MMD 4 is released under both the MIT License and GPL.
	
	
	CuTest is released under the zlib/libpng license. See CuTest.c for the text
	of the license.
	
	
	## The MIT License ##
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.

*/

#include "lexer.h"
#include "libMultiMarkdown.h"
#include "parser.h"


// Basic scanner struct

#define YYCTYPE		char
#define YYCURSOR	s->cur
#define YYMARKER	s->ptr
#define YYCTXMARKER	s->ctx


int scan(Scanner * s, const char * stop) {

	scan:

	if (s->cur >= stop) {
		return 0;
	}

	s->start = s->cur;

	
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;

	yych = *YYCURSOR;
	switch (yych) {
	case '\t':	goto yy39;
	case '\n':	goto yy44;
	case '\r':	goto yy46;
	case ' ':	goto yy41;
	case '!':	goto yy17;
	case '"':	goto yy25;
	case '#':	goto yy42;
	case '$':	goto yy35;
	case '&':	goto yy32;
	case '\'':	goto yy27;
	case '(':	goto yy18;
	case ')':	goto yy20;
	case '*':	goto yy47;
	case '+':	goto yy4;
	case '-':	goto yy6;
	case '.':	goto yy29;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy43;
	case ':':	goto yy30;
	case '<':	goto yy8;
	case '=':	goto yy12;
	case '>':	goto yy22;
	case '[':	goto yy13;
	case '\\':	goto yy34;
	case ']':	goto yy15;
	case '^':	goto yy37;
	case '_':	goto yy49;
	case '`':	goto yy51;
	case '{':	goto yy2;
	case '|':	goto yy53;
	case '}':	goto yy24;
	case '~':	goto yy10;
	default:	goto yy55;
	}
yy2:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '+':	goto yy251;
	case '-':	goto yy250;
	case '=':	goto yy247;
	case '>':	goto yy249;
	case '{':	goto yy245;
	case '~':	goto yy248;
	default:	goto yy3;
	}
yy3:
	{ goto scan; }
yy4:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '+':	goto yy242;
	default:	goto yy5;
	}
yy5:
	{ return PLUS; }
yy6:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '-':	goto yy236;
	default:	goto yy7;
	}
yy7:
	{ return DASH_N; }
yy8:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '<':	goto yy233;
	default:	goto yy9;
	}
yy9:
	{ return ANGLE_LEFT; }
yy10:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '>':	goto yy229;
	case '~':	goto yy228;
	default:	goto yy11;
	}
yy11:
	{ return SUBSCRIPT; }
yy12:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '=':	goto yy225;
	default:	goto yy3;
	}
yy13:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '#':	goto yy221;
	case '%':	goto yy219;
	case '^':	goto yy223;
	default:	goto yy14;
	}
yy14:
	{ return BRACKET_LEFT; }
yy15:
	++YYCURSOR;
	{ return BRACKET_RIGHT; }
yy17:
	yych = *++YYCURSOR;
	switch (yych) {
	case '[':	goto yy217;
	default:	goto yy3;
	}
yy18:
	++YYCURSOR;
	{ return PAREN_LEFT; }
yy20:
	++YYCURSOR;
	{ return PAREN_RIGHT; }
yy22:
	++YYCURSOR;
	{ return ANGLE_RIGHT; }
yy24:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy215;
	default:	goto yy3;
	}
yy25:
	++YYCURSOR;
	{ return QUOTE_DOUBLE; }
yy27:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '\'':	goto yy213;
	default:	goto yy28;
	}
yy28:
	{ return QUOTE_SINGLE; }
yy29:
	YYCTXMARKER = YYCURSOR + 1;
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\t':	goto yy203;
	case '\n':	goto yy200;
	case '\r':	goto yy202;
	case ' ':	goto yy205;
	case '.':	goto yy206;
	default:	goto yy3;
	}
yy30:
	++YYCURSOR;
	{ return COLON; }
yy32:
	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'A':
	case 'a':	goto yy195;
	default:	goto yy33;
	}
yy33:
	{ return AMPERSAND; }
yy34:
	yych = *++YYCURSOR;
	switch (yych) {
	case '!':	goto yy183;
	case '"':	goto yy173;
	case '#':	goto yy153;
	case '$':	goto yy151;
	case '%':	goto yy149;
	case '&':	goto yy137;
	case '\'':	goto yy171;
	case '(':	goto yy165;
	case ')':	goto yy163;
	case '*':	goto yy129;
	case '+':	goto yy147;
	case ',':	goto yy179;
	case '-':	goto yy145;
	case '.':	goto yy185;
	case '/':	goto yy133;
	case ':':	goto yy175;
	case ';':	goto yy177;
	case '<':	goto yy141;
	case '=':	goto yy143;
	case '>':	goto yy139;
	case '?':	goto yy181;
	case '@':	goto yy135;
	case '[':	goto yy157;
	case '\\':	goto yy123;
	case ']':	goto yy155;
	case '^':	goto yy131;
	case '_':	goto yy127;
	case '`':	goto yy169;
	case '{':	goto yy161;
	case '|':	goto yy125;
	case '}':	goto yy159;
	case '~':	goto yy167;
	default:	goto yy3;
	}
yy35:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '$':	goto yy121;
	default:	goto yy36;
	}
yy36:
	{ return MATH_DOLLAR_SINGLE; }
yy37:
	++YYCURSOR;
	{ return SUPERSCRIPT; }
yy39:
	++YYCURSOR;
	{ return INDENT_TAB; }
yy41:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy44;
	case '\r':	goto yy112;
	case ' ':	goto yy110;
	default:	goto yy3;
	}
yy42:
	YYCTXMARKER = YYCURSOR + 1;
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy71;
	case '#':	goto yy69;
	default:	goto yy3;
	}
yy43:
	YYCTXMARKER = YYCURSOR + 1;
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '.':	goto yy60;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy62;
	default:	goto yy3;
	}
yy44:
	++YYCURSOR;
yy45:
	{ return TEXT_NL; }
yy46:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy44;
	default:	goto yy45;
	}
yy47:
	++YYCURSOR;
	{ return STAR; }
yy49:
	++YYCURSOR;
	{ return UL; }
yy51:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy59;
yy52:
	{ return BACKTICK; }
yy53:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy57;
yy54:
	{ return PIPE; }
yy55:
	yych = *++YYCURSOR;
	goto yy3;
yy56:
	++YYCURSOR;
	yych = *YYCURSOR;
yy57:
	switch (yych) {
	case '|':	goto yy56;
	default:	goto yy54;
	}
yy58:
	++YYCURSOR;
	yych = *YYCURSOR;
yy59:
	switch (yych) {
	case '`':	goto yy58;
	default:	goto yy52;
	}
yy60:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case ' ':	goto yy67;
	case '\n':	goto yy64;
	case '\r':	goto yy66;
	default:	goto yy61;
	}
yy61:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy3;
	case 1: 	goto yy5;
	case 2: 	goto yy9;
	case 3: 	goto yy11;
	case 4: 	goto yy33;
	case 5: 	goto yy118;
	case 6: 	goto yy201;
	default:	goto yy246;
	}
yy62:
	YYCTXMARKER = YYCURSOR + 1;
	++YYCURSOR;
	yych = *YYCURSOR;
	switch (yych) {
	case '.':	goto yy60;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy62;
	default:	goto yy61;
	}
yy64:
	++YYCURSOR;
yy65:
	YYCURSOR = YYCTXMARKER;
	{ return TEXT_NUMBER_POSS_LIST; }
yy66:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy64;
	default:	goto yy65;
	}
yy67:
	++YYCURSOR;
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case ' ':	goto yy67;
	default:	goto yy65;
	}
yy69:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy77;
	case '#':	goto yy82;
	default:	goto yy61;
	}
yy70:
	++YYCURSOR;
	yych = *YYCURSOR;
yy71:
	switch (yych) {
	case '\t':
	case ' ':	goto yy70;
	case '\n':	goto yy73;
	case '\r':	goto yy75;
	default:	goto yy72;
	}
yy72:
	{ return HASH1; }
yy73:
	++YYCURSOR;
yy74:
	YYCURSOR = YYCTXMARKER;
	{ return HASH1; }
yy75:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy73;
	default:	goto yy74;
	}
yy76:
	++YYCURSOR;
	yych = *YYCURSOR;
yy77:
	switch (yych) {
	case '\t':
	case ' ':	goto yy76;
	case '\n':	goto yy79;
	case '\r':	goto yy81;
	default:	goto yy78;
	}
yy78:
	{ return HASH2; }
yy79:
	++YYCURSOR;
yy80:
	YYCURSOR = YYCTXMARKER;
	{ return HASH2; }
yy81:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy79;
	default:	goto yy80;
	}
yy82:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy85;
	case '#':	goto yy83;
	default:	goto yy61;
	}
yy83:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy91;
	case '#':	goto yy96;
	default:	goto yy61;
	}
yy84:
	++YYCURSOR;
	yych = *YYCURSOR;
yy85:
	switch (yych) {
	case '\t':
	case ' ':	goto yy84;
	case '\n':	goto yy87;
	case '\r':	goto yy89;
	default:	goto yy86;
	}
yy86:
	{ return HASH3; }
yy87:
	++YYCURSOR;
yy88:
	YYCURSOR = YYCTXMARKER;
	{ return HASH3; }
yy89:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy87;
	default:	goto yy88;
	}
yy90:
	++YYCURSOR;
	yych = *YYCURSOR;
yy91:
	switch (yych) {
	case '\t':
	case ' ':	goto yy90;
	case '\n':	goto yy93;
	case '\r':	goto yy95;
	default:	goto yy92;
	}
yy92:
	{ return HASH4; }
yy93:
	++YYCURSOR;
yy94:
	YYCURSOR = YYCTXMARKER;
	{ return HASH4; }
yy95:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy93;
	default:	goto yy94;
	}
yy96:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy99;
	case '#':	goto yy97;
	default:	goto yy61;
	}
yy97:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy105;
	default:	goto yy61;
	}
yy98:
	++YYCURSOR;
	yych = *YYCURSOR;
yy99:
	switch (yych) {
	case '\t':
	case ' ':	goto yy98;
	case '\n':	goto yy101;
	case '\r':	goto yy103;
	default:	goto yy100;
	}
yy100:
	{ return HASH5; }
yy101:
	++YYCURSOR;
yy102:
	YYCURSOR = YYCTXMARKER;
	{ return HASH5; }
yy103:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy101;
	default:	goto yy102;
	}
yy104:
	++YYCURSOR;
	yych = *YYCURSOR;
yy105:
	switch (yych) {
	case '\t':
	case ' ':	goto yy104;
	case '\n':	goto yy107;
	case '\r':	goto yy109;
	default:	goto yy106;
	}
yy106:
	{ return HASH6; }
yy107:
	++YYCURSOR;
yy108:
	YYCURSOR = YYCTXMARKER;
	{ return HASH6; }
yy109:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy107;
	default:	goto yy108;
	}
yy110:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '\n':	goto yy114;
	case '\r':	goto yy116;
	case ' ':	goto yy113;
	default:	goto yy111;
	}
yy111:
	{ return NON_INDENT_SPACE; }
yy112:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy44;
	default:	goto yy45;
	}
yy113:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy114;
	case '\r':	goto yy116;
	case ' ':	goto yy117;
	default:	goto yy111;
	}
yy114:
	++YYCURSOR;
yy115:
	{ return TEXT_LINEBREAK; }
yy116:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy114;
	default:	goto yy115;
	}
yy117:
	yyaccept = 5;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\n':	goto yy114;
	case '\r':	goto yy116;
	case ' ':	goto yy119;
	default:	goto yy118;
	}
yy118:
	{ return INDENT_SPACE; }
yy119:
	++YYCURSOR;
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy114;
	case '\r':	goto yy116;
	case ' ':	goto yy119;
	default:	goto yy61;
	}
yy121:
	++YYCURSOR;
	{ return MATH_DOLLAR_DOUBLE; }
yy123:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '(':	goto yy187;
	case ')':	goto yy189;
	case '[':	goto yy191;
	case ']':	goto yy193;
	default:	goto yy124;
	}
yy124:
	{ return ESCAPED_CHARACTER; }
yy125:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy127:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy129:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy131:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy133:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy135:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy137:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy139:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy141:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy143:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy145:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy147:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy149:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy151:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy153:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy155:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy157:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy159:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy161:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy163:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy165:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy167:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy169:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy171:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy173:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy175:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy177:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy179:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy181:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy183:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy185:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy187:
	++YYCURSOR;
	{ return MATH_PAREN_OPEN; }
yy189:
	++YYCURSOR;
	{ return MATH_PAREN_CLOSE; }
yy191:
	++YYCURSOR;
	{ return MATH_BRACKET_OPEN; }
yy193:
	++YYCURSOR;
	{ return MATH_BRACKET_CLOSE; }
yy195:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'M':
	case 'm':	goto yy196;
	default:	goto yy61;
	}
yy196:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'P':
	case 'p':	goto yy197;
	default:	goto yy61;
	}
yy197:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy198;
	default:	goto yy61;
	}
yy198:
	++YYCURSOR;
	{ return AMPERSAND_LONG; }
yy200:
	++YYCURSOR;
yy201:
	YYCURSOR = YYCTXMARKER;
	{ return TEXT_PERIOD; }
yy202:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy200;
	default:	goto yy201;
	}
yy203:
	++YYCURSOR;
	yych = *YYCURSOR;
yy204:
	switch (yych) {
	case '\t':
	case ' ':	goto yy203;
	default:	goto yy201;
	}
yy205:
	yyaccept = 6;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '.':	goto yy209;
	default:	goto yy204;
	}
yy206:
	yych = *++YYCURSOR;
	switch (yych) {
	case '.':	goto yy207;
	default:	goto yy61;
	}
yy207:
	++YYCURSOR;
	{ return ELLIPSIS; }
yy209:
	yych = *++YYCURSOR;
	switch (yych) {
	case ' ':	goto yy210;
	default:	goto yy61;
	}
yy210:
	yych = *++YYCURSOR;
	switch (yych) {
	case '.':	goto yy211;
	default:	goto yy61;
	}
yy211:
	++YYCURSOR;
	{ return ELLIPSIS; }
yy213:
	++YYCURSOR;
	{ return QUOTE_RIGHT_ALT; }
yy215:
	++YYCURSOR;
	{ return BRACE_DOUBLE_RIGHT; }
yy217:
	++YYCURSOR;
	{ return BRACKET_IMAGE_LEFT; }
yy219:
	++YYCURSOR;
	{ return BRACKET_VARIABLE_LEFT; }
yy221:
	++YYCURSOR;
	{ return BRACKET_CITATION_LEFT; }
yy223:
	++YYCURSOR;
	{ return BRACKET_FOOTNOTE_LEFT; }
yy225:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy226;
	default:	goto yy61;
	}
yy226:
	++YYCURSOR;
	{ return CRITIC_HI_CLOSE; }
yy228:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy231;
	default:	goto yy61;
	}
yy229:
	++YYCURSOR;
	{ return CRITIC_SUB_DIV; }
yy231:
	++YYCURSOR;
	{ return CRITIC_SUB_CLOSE; }
yy233:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy234;
	default:	goto yy61;
	}
yy234:
	++YYCURSOR;
	{ return CRITIC_COM_CLOSE; }
yy236:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '-':	goto yy240;
	case '}':	goto yy238;
	default:	goto yy237;
	}
yy237:
	{ return DASH_N; }
yy238:
	++YYCURSOR;
	{ return CRITIC_DEL_CLOSE; }
yy240:
	++YYCURSOR;
	{ return DASH_M; }
yy242:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy243;
	default:	goto yy61;
	}
yy243:
	++YYCURSOR;
	{ return CRITIC_ADD_CLOSE; }
yy245:
	yyaccept = 7;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'T':	goto yy262;
	default:	goto yy246;
	}
yy246:
	{ return BRACE_DOUBLE_LEFT; }
yy247:
	yych = *++YYCURSOR;
	switch (yych) {
	case '=':	goto yy260;
	default:	goto yy61;
	}
yy248:
	yych = *++YYCURSOR;
	switch (yych) {
	case '~':	goto yy258;
	default:	goto yy61;
	}
yy249:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy256;
	default:	goto yy61;
	}
yy250:
	yych = *++YYCURSOR;
	switch (yych) {
	case '-':	goto yy254;
	default:	goto yy61;
	}
yy251:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':	goto yy252;
	default:	goto yy61;
	}
yy252:
	++YYCURSOR;
	{ return CRITIC_ADD_OPEN; }
yy254:
	++YYCURSOR;
	{ return CRITIC_DEL_OPEN; }
yy256:
	++YYCURSOR;
	{ return CRITIC_COM_OPEN; }
yy258:
	++YYCURSOR;
	{ return CRITIC_SUB_OPEN; }
yy260:
	++YYCURSOR;
	{ return CRITIC_HI_OPEN; }
yy262:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'O':	goto yy263;
	default:	goto yy61;
	}
yy263:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'C':	goto yy264;
	default:	goto yy61;
	}
yy264:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy265;
	default:	goto yy61;
	}
yy265:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy266;
	default:	goto yy61;
	}
yy266:
	++YYCURSOR;
	{ return TOC; }
}

}