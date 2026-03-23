
#ifndef _ENCRYPTION_UTILITIES_ST_H_
  #define _ENCRYPTION_UTILITIES_ST_H_
  
  //function prototypes for .st code from encryption_utilities.c

  //returns the os-interface number of the OpenSSL v1.1.1 interface if compiled with that version, else returns 0.
  FUNCTION GLOBAL __cdecl OpenSSL111_GetInterfaceVersion VAR_OUTPUT ver : UDINT; END_VAR;


#endif // _ENCRYPTION_UTILITIES_ST_H_