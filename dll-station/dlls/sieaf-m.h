#pragma once

int business_handle(const char* inputValue, int outputLen, char* outputData, char* errMsg);
int do_update(char* errMsg);
int authorization(const char* orgName, const char* orgPwd, char* errMsg);
int read_cardnum(char* cardNum, char* errMsg);
int read_cardnum_and_name(char* cardNum, char* name, char* errMsg);
