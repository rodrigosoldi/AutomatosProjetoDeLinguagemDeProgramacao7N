# -*- coding: utf-8 -*-



def consume(tok, s):
	w = s[0]
	s = s[1:]
	if w != tok:
		print w, s, tok
		print 10/0
	return s


def PROG(s):
	return MAIN(s)

def MAIN(s):
	s = consume("class", s)
	s = consume("id", s)
	s = consume("{", s)
	s = consume("public", s)
	s = consume("static", s)
	s = consume("void", s)
	s = consume("main", s)
	s = consume("(", s)
	s = consume("String", s)
	s = consume("[", s)
	s = consume("]", s)
	s = consume("id", s)
	s = consume(")", s)
	s = consume("{", s)
	s = VAR_X(s)
	s = METODO_X(s)
	s = consume("}", s)
	s = consume("}", s)
	return s

def VAR_X(s):
	if s[0] == "int" or s[0] == "boolean" or s[0] == "int" or s[0] == "id":
		s = TIPO(s)
		s = VAR_X(s)
		return s
	else:
		return s

def METODO_X(s):
	if s[0] == "public":
		s = METODO(s)
		s = MEOTOD_X(s)
		return s
	else:
		return s

def VAR(s):
	s = TIPO(s)
	s = consume("id", s)
	s = consume(";", s)
	return s

def METODO(s):
	s = consume("public", s)
	s = TIPO(s)
	s = consume("id", s)
	s = consume("(", s)
	s = PARAM_X(s)
	s = consume(")", s)
	s = consume("{", s)
	s = INSIDE_METODO(s)
	s = consume("}", s)
	return s

def PARAM_X(s):
	s = PARAM(s)
	s = PARAM_Y(s)
	return s

def PARAM_Y(s):
	s = consume(",", s)
	s = PARAM_X(s)
	return s

def PARAM(s):
	s = TIPO(s)
	s = consume("id", s)
	return s

def INSIDE_METODO(s):
	s = VAR_X(s)
	s = CMD_X(s)
	return s

def CMD_X(s):
	if s[0] == "{" or s[0] == "id" or s[0] == "if" or s[0] == "System.out.println":
		s = CMD(s)
		s = consume("return")
		s = EXP(s)
		s = consume(";")
		return s
	else:
		return s

def CMDS(s):
	if s[0] == "{" or s[0] == "id" or s[0] == "if" or s[0] == "System.out.println":
		s = CMD(s)
		s = CMDS(s)
		return s
	else:
		return s

def TIPO(s):
	if s[0] == "int" and s[1] == "[":
		s = consume("int", s)
		s = consume("[", s)
		s = consume("]", s)
		return s
	elif s[0] == "boolean":
		s = consume("boolean", s)
		return s
	elif s[0] == "int":
		s = consume("int", s)
		return s
	elif s[0] == "id":
		s = consume("id", s)
		return s

def CMD(s):
	s = consume("c", s)
	return s

s = "class id { public static void main ( String [ ] id ) {  } }".split()
PROG(s)
