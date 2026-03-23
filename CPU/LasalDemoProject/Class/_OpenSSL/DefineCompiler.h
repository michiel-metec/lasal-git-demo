#ifndef _DefineCompilerH
  #define _DefineCompilerH
  
  #ifndef cCompile

    #ifdef _MSC_VER
      #define cCompile
    #endif
    #ifdef _GNUC
      #define cCompile
    #endif
  
  #endif

  #ifdef cCompile

    #ifndef cExtern
      #ifdef __cplusplus
        #define cExtern extern "C"
      #else
        #define cExtern extern 
      #endif
    #endif
  
  #endif
  
#endif
