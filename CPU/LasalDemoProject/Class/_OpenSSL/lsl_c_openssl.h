/*
 * lsl_c_openssl.h
 *
 *  Created on: Mar 9, 2017
 *  Author: krimar
 */

#ifndef _LSL_C_OPENSSL_H

  #pragma once
  #define _LSL_C_OPENSSL_H

  typedef struct
  {
    unsigned long version;
    unsigned long size;

    X509* (* d2i_X509)(X509 **px, const unsigned char **in, long len);
    X509_NAME* (* X509_get_subject_name)(X509 *a); //1.1.0
    int   (* X509_NAME_get_index_by_NID)(X509_NAME *name,int nid,int lastpos);
    X509_NAME_ENTRY* (* X509_NAME_get_entry)(X509_NAME *name, int loc);
    ASN1_STRING* (* X509_NAME_ENTRY_get_data)(X509_NAME_ENTRY *ne);
    int  (* ASN1_STRING_to_UTF8)(unsigned char **out, ASN1_STRING *in);
    void (* OPENSSL_free)(void *addr);
    void (* X509_free)(X509 *a);
    
    const char * (* SSLeay_version)(int type);
    void (* OpenSSL_add_all_algorithms)(void);
    void (* ERR_load_crypto_strings)(void);
    int (* X509_STORE_CTX_get_ex_new_index)(long argl, void *argp, CRYPTO_EX_new *new_func, CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func);
    void (* EVP_cleanup)(void);
    void (* CRYPTO_cleanup_all_ex_data)(void);
    void (* ERR_remove_state)(unsigned long pid);
    void (* ERR_free_strings)(void);
    
    int  (* AES_set_encrypt_key)(const unsigned char *userKey, const int bits, AES_KEY *key);
    int  (* AES_set_decrypt_key)(const unsigned char *userKey, const int bits, AES_KEY *key);
    void (* AES_cbc_encrypt)(const uint8_t *in, uint8_t *out, size_t len, const AES_KEY *key, uint8_t *ivec, const int enc);
    
    const EVP_MD* (* EVP_sha1)(void);
    unsigned char* (* HMAC)(const EVP_MD *evp_md, const void *key, int key_len, const unsigned char *d, size_t n, unsigned char *md, unsigned int *md_len);
    
    void  (* X509_STORE_free)(X509_STORE *ctx);
    int   (* X509_STORE_add_cert)(X509_STORE *ctx, X509 *x);
    unsigned char* (* SHA1)(const unsigned char *d, size_t n, unsigned char *md);
    
    int   (* RAND_bytes)(unsigned char *buf, int num);
    
    RSA*  (* RSA_generate_key)(int bits, unsigned long e, void (*callback) (int, int, void *), void *cb_arg);
    int   (* i2d_RSAPublicKey)(const RSA *a, unsigned char **pp);
    int   (* i2d_RSAPrivateKey)(const RSA *a, unsigned char **pp);
    RSA*  (* d2i_RSAPrivateKey)(RSA **a, const unsigned char **pp, long length);
    EVP_PKEY* (* d2i_PublicKey)(int type, EVP_PKEY **a, const unsigned char **pp, long length);
    EVP_PKEY* (* d2i_PrivateKey)(int type, EVP_PKEY **a, const unsigned char **pp, long length);
    void  (* RSA_free)(RSA *rsa);
    BIO*  (* BIO_new_file)(const char *filename, const char *mode);
    EVP_PKEY* (* PEM_read_bio_PrivateKey)(BIO *bp, EVP_PKEY **x, pem_password_cb *cb, void *u);
    PKCS12* (* d2i_PKCS12_bio)(BIO *bp, PKCS12 **p12);
    int   (* PKCS12_parse)(PKCS12 *p12, const char *pass, EVP_PKEY **pkey, X509 **cert, STACK_OF(X509) **ca);
    void  (* PKCS12_free)(PKCS12 *a);
    RSA*  (* EVP_PKEY_get1_RSA)(EVP_PKEY *pkey);
    void  (* EVP_PKEY_free)(EVP_PKEY *key);
    int   (* BIO_free)(BIO *a);
    int   (* PEM_write_bio_RSAPrivateKey)(BIO *bp, RSA *x, const EVP_CIPHER *enc, unsigned char *kstr, int klen, pem_password_cb *cb, void *u);
    int   (* RSA_size)(const RSA *rsa);
    int   (* RSA_public_encrypt)(int flen, const unsigned char *from, unsigned char *to, RSA *rsa, int padding);
    int   (* RSA_private_decrypt)(int flen, const unsigned char *from, unsigned char *to, RSA *rsa, int padding);
    int   (* RSA_sign)(int type, const unsigned char *m, unsigned int m_len, unsigned char *sigret, unsigned int *siglen, RSA *rsa);
    unsigned long (* ERR_get_error)(void);
    char* (* ERR_error_string)(unsigned long e, char *buf);
    int   (* RSA_verify)(int type, const unsigned char *m, unsigned int m_len, const unsigned char *sigbuf, unsigned int siglen, RSA *rsa);
    
    int   (* OBJ_txt2nid)(const char *s);
    X509_NAME_ENTRY* (* X509_NAME_ENTRY_create_by_NID)(X509_NAME_ENTRY **ne, int nid, int type,unsigned char *bytes, int len);
    int   (* X509_NAME_add_entry)(X509_NAME *name,X509_NAME_ENTRY *ne, int loc, int set);
    X509_EXTENSION* (* X509V3_EXT_conf)(LHASH_OF(CONF_VALUE) *conf, X509V3_CTX *ctx, char *name, char *value);
    int   (* X509_add_ext)(X509 *x, X509_EXTENSION *ex, int loc);
    void  (* X509_EXTENSION_free)(X509_EXTENSION *a);
    X509* (* X509_new)(void);
    int   (* X509_set_version)(X509 *x, long version);
    ASN1_INTEGER* (* X509_get_serialNumber)(X509 *x);
    void* (* OPENSSL_Realloc)(void *addr, int num, const char *file, int line);
    int  (* ASN1_INTEGER_set)(ASN1_INTEGER *a, long v); 
    int   (* X509_set_pubkey)(X509 *x, EVP_PKEY *pkey);
    X509_NAME* (* X509_NAME_new)(void);
    int   (* X509_set_subject_name)(X509 *x, X509_NAME *name);
    int   (* X509_set_issuer_name)(X509 *x, X509_NAME *name);
    ASN1_UTCTIME* (* X509_gmtime_adj)(ASN1_UTCTIME *s, long adj);
    void  (* X509V3_set_ctx)(X509V3_CTX* ctx, X509* issuer, X509* subj, X509_REQ* req, X509_CRL* crl, int flags);
    int   (* X509_sign)(X509 *x, EVP_PKEY *pkey, const EVP_MD *md);
    void  (* X509_NAME_free)(X509_NAME *a);
    int   (* i2d_X509_bio)(BIO *bp, X509 *x);
    X509* (* d2i_X509_bio)(BIO *bp, X509 **x);
    X509* (* PEM_read_bio_X509)(BIO *bp, X509 **x, pem_password_cb *cb, void *u);
    EVP_PKEY* (* X509_get_pubkey)(X509 *x);
    int   (* OBJ_obj2nid)(const ASN1_OBJECT *o);
    BIO*  (* BIO_new)(BIO_METHOD *t);
    
    //functions available from API version >= 2
    int   (* i2d_X509)(X509 *x, unsigned char **out);
    int   (* X509_verify)(X509 *a, EVP_PKEY *r);
    X509_STORE* (* X509_STORE_new)(void);
    int   (* CRYPTO_add_lock)(int *pointer, int amount, int type, const char *file, int line);
    X509_LOOKUP_METHOD *(* X509_LOOKUP_file)(void);
    int   (* X509_LOOKUP_ctrl)(X509_LOOKUP *ctx, int cmd, const char *argc, long argl, char **ret);
    int   (* X509_verify_cert)(X509_STORE_CTX *ctx);
    char *(* X509_NAME_oneline)(X509_NAME *a, char *buf, int size);
    int   (* X509_load_crl_file)(X509_LOOKUP *ctx, const char *file, int type);
    X509_STORE_CTX *(* X509_STORE_CTX_new)(void);
    void  (* X509_STORE_CTX_free)(X509_STORE_CTX *ctx);
    int   (* X509_STORE_CTX_init)(X509_STORE_CTX *ctx, X509_STORE *store, X509 *x509, STACK_OF(X509) *chain);
    X509_NAME *(* X509_get_issuer_name)(X509 *a);
    X509_LOOKUP_METHOD *(* X509_LOOKUP_hash_dir)(void);
    int   (* X509_STORE_set_flags)(X509_STORE *ctx, unsigned long flags);
    X509_LOOKUP *(* X509_STORE_add_lookup)(X509_STORE *v, X509_LOOKUP_METHOD *m);
    int   (* X509_STORE_set_default_paths)(X509_STORE *ctx);
    void *(* X509_STORE_CTX_get_ex_data)(X509_STORE_CTX *ctx, int idx);
    int   (* X509_STORE_CTX_set_ex_data)(X509_STORE_CTX *ctx, int idx, void *data);
    int   (* X509_STORE_CTX_get_error)(X509_STORE_CTX *ctx);
    X509 *(* X509_STORE_CTX_get_current_cert)(X509_STORE_CTX *ctx);
    int   (* X509_STORE_CTX_get_error_depth)(X509_STORE_CTX *ctx);
    const char *(* X509_verify_cert_error_string)(long n);
    int   (* i2d_PublicKey)(EVP_PKEY *a, unsigned char **pp);
    int   (* EVP_PKEY_type)(int type);
    void *(* CRYPTO_realloc)(void *addr, int num, const char *file, int line);
    long (* BIO_ctrl)(BIO *bp, int cmd, long larg, void *parg);
    BIO_METHOD *(* BIO_s_mem)(void);
    BIO_METHOD *(* BIO_s_file)(void);
    X509_EXTENSION *(* X509_get_ext)(X509 *x, int loc);
    int   (* EVP_PKEY_cmp)(const EVP_PKEY *a, const EVP_PKEY *b);
    EVP_PKEY *(* EVP_PKEY_new)(void);
    ASN1_TIME *(* ASN1_TIME_set)(ASN1_TIME *s, time_t t);
    int   (* X509_CRL_sign)(X509_CRL *x, EVP_PKEY *pkey, const EVP_MD *md);
    EVP_PKEY *(* X509_PUBKEY_get)(X509_PUBKEY *key);
    int   (* EVP_PKEY_assign)(EVP_PKEY *pkey, int type, void *key);
    int   (* X509V3_EXT_print)(BIO *out, X509_EXTENSION *ext, unsigned long flag, int indent);
    int   (* X509_get_ext_by_NID)(X509 *x, int nid, int lastpos);
    int   (* X509_CRL_set_version)(X509_CRL *x, long version);
    int   (* X509_CRL_add0_revoked)(X509_CRL *crl, X509_REVOKED *rev);
    int   (* X509_CRL_add1_ext_i2d)(X509_CRL *x, int nid, void *value, int crit, unsigned long flags);
    int   (* X509_CRL_set_lastUpdate)(X509_CRL *x, const ASN1_TIME *tm);
    int   (* X509_CRL_set_nextUpdate)(X509_CRL *x, const ASN1_TIME *tm);
    int   (* X509_NAME_add_entry_by_txt)(X509_NAME *name, const char *field, int type, const unsigned char *bytes, int len, int loc,int set);
    int   (* X509_REVOKED_set_revocationDate)(X509_REVOKED *r, ASN1_TIME *tm);
    int   (* X509_CRL_set_issuer_name)(X509_CRL *x, X509_NAME *name);
    int   (* X509_REVOKED_set_serialNumber)(X509_REVOKED *x, ASN1_INTEGER *serial);
    void  (* X509_NAME_ENTRY_free)(X509_NAME_ENTRY* ne);
	  X509_CRL *(* X509_CRL_new)(void);
	  void  (* X509_CRL_free)(X509_CRL *crl);
	  void  (* ASN1_TIME_free)(ASN1_TIME *mut);
	  ASN1_INTEGER *(* ASN1_INTEGER_new)(void);
	  void  (* ASN1_INTEGER_free)(ASN1_INTEGER *a);
	  X509_REVOKED *(* X509_REVOKED_new)(void);
	  void  (* X509_REVOKED_free)(X509_REVOKED *r);
	  int   (* PEM_write_bio_X509_CRL)(BIO *bp, X509_CRL *x);
	  int   (* X509_cmp_time)(const ASN1_TIME *s, time_t *t);
    
	  ASN1_TIME *(* X509_get_notBefore)(X509* x);
	  ASN1_TIME *(* X509_get_notAfter)(X509* x);

	  const EVP_MD* (* EVP_sha256)(void);
	  unsigned char* (* SHA256)(const unsigned char *d, size_t n, unsigned char *md);
	  int   (* BIO_write)(BIO *b, const void *data, int len);
	  RSA  *(* PEM_read_bio_RSA_PUBKEY)(BIO *bp, RSA **x, pem_password_cb *cb, void *u);
	  int   (* SHA512_Init)(SHA512_CTX *c);
	  int   (* SHA512_Update)(SHA512_CTX *c, const void *data, size_t len);
	  int   (* SHA512_Final)(unsigned char *md, SHA512_CTX *c);
	  unsigned char* (* SHA512)(const unsigned char *d, size_t n, unsigned char *md);

  } LSL_OPENSSL;

  cExtern LSL_OPENSSL *lsl_openssl;

  #define OS_OPENSSL_SIZE                                         lsl_openssl->size

  #define d2i_X509(px, in, len)                           		    lsl_openssl->d2i_X509(px, in, len)
  #define X509_get_subject_name(a)                        		    lsl_openssl->X509_get_subject_name(a)
  #define X509_NAME_get_index_by_NID(name, nid, lastpos)  		    lsl_openssl->X509_NAME_get_index_by_NID(name, nid, lastpos)
  #define X509_NAME_get_entry(name, loc)                  		    lsl_openssl->X509_NAME_get_entry(name, loc)
  #define X509_NAME_ENTRY_get_data(ne)                    		    lsl_openssl->X509_NAME_ENTRY_get_data(ne)
  #define ASN1_STRING_to_UTF8(out, in)                    		    lsl_openssl->ASN1_STRING_to_UTF8(out, in)
  #define OPENSSL_free(addr)             		                      lsl_openssl->OPENSSL_free(addr)
  #define X509_free(a)                                    		    lsl_openssl->X509_free(a)
  
  #define SSLeay_version(type)                            		    lsl_openssl->SSLeay_version(type)
  #define OpenSSL_add_all_algorithms()                    		    lsl_openssl->OpenSSL_add_all_algorithms()
  #define ERR_load_crypto_strings()                       		    lsl_openssl->ERR_load_crypto_strings()
  #define X509_STORE_CTX_get_ex_new_index(argl, argp, new_func, dup_func, free_func) lsl_openssl->X509_STORE_CTX_get_ex_new_index(argl, argp, new_func, dup_func, free_func)
  #define EVP_cleanup()                                   		    lsl_openssl->EVP_cleanup()
  #define CRYPTO_cleanup_all_ex_data()                    		    lsl_openssl->CRYPTO_cleanup_all_ex_data()
  #define ERR_remove_state(pid)                           		    lsl_openssl->ERR_remove_state(pid)
  #define ERR_free_strings()                              		    lsl_openssl->ERR_free_strings()
  
  #define AES_set_encrypt_key(userKey, bits, key)         		    lsl_openssl->AES_set_encrypt_key(userKey, bits, key)
  #define AES_set_decrypt_key(userKey, bits, key)         		    lsl_openssl->AES_set_decrypt_key(userKey, bits, key)
  #define AES_cbc_encrypt(in, out, len, key, ivec, enc)   		    lsl_openssl->AES_cbc_encrypt(in, out, len, key, ivec, enc)
  
  #define EVP_sha1()												                      lsl_openssl->EVP_sha1()
  #define HMAC(evp_md,key,key_len,d,n,md,md_len) 	                lsl_openssl->HMAC(evp_md, key, key_len, d, n, md, md_len)
  
  #define X509_STORE_free(ctx)  						                      lsl_openssl->X509_STORE_free(ctx)
  #define X509_STORE_add_cert(ctx, x)  							              lsl_openssl->X509_STORE_add_cert(ctx, x)
  #define SHA1(d, n, md)  										                    lsl_openssl->SHA1(d, n, md)
  
  #define RAND_bytes(buf, num) 									                  lsl_openssl->RAND_bytes(buf, num);
  
  #define RSA_generate_key(bits, e, callback, cb_arg) 			      lsl_openssl->RSA_generate_key(bits, e, callback, cb_arg)
  #define i2d_RSAPublicKey(a, pp)									                lsl_openssl->i2d_RSAPublicKey(a, pp)
  #define i2d_RSAPrivateKey(a, pp)								                lsl_openssl->i2d_RSAPrivateKey(a, pp)
  #define d2i_RSAPrivateKey(a, pp, length)                        lsl_openssl->d2i_RSAPrivateKey(a, pp, length)
  #define d2i_PublicKey(type, a, pp, length)						          lsl_openssl->d2i_PublicKey(type, a, pp, length)
  #define d2i_PrivateKey(type,a, pp, length)						          lsl_openssl->d2i_PrivateKey(type,a, pp, length)
  #define RSA_free(rsa)											                      lsl_openssl->RSA_free(rsa)
  #define BIO_new_file(filename, mode)				                    lsl_openssl->BIO_new_file(filename, mode)
  #define PEM_read_bio_PrivateKey(  bp, x, cb, u)			            lsl_openssl->PEM_read_bio_PrivateKey(bp, x, cb, u)
  #define d2i_PKCS12_bio(bp, p12)									                lsl_openssl->d2i_PKCS12_bio(bp, p12)
  #define PKCS12_parse(p12, pass, pkey, cert, ca)					        lsl_openssl->PKCS12_parse(p12, pass, pkey, cert, ca)
  #define PKCS12_free(a)											                    lsl_openssl->PKCS12_free(a)
  #define EVP_PKEY_get1_RSA(pkey)									                lsl_openssl->EVP_PKEY_get1_RSA(pkey)
  #define EVP_PKEY_free(key)										                  lsl_openssl->EVP_PKEY_free(key)
  #define BIO_free(a)												                      lsl_openssl->BIO_free(a)
  #define PEM_write_bio_RSAPrivateKey(bp, x, enc, kstr, klen, cb, u)	lsl_openssl->PEM_write_bio_RSAPrivateKey(bp, x, enc, kstr, klen, cb, u)
  #define RSA_size(rsa)											                      lsl_openssl->RSA_size(rsa)
  #define RSA_public_encrypt(flen, from, to, rsa, padding)		    lsl_openssl->RSA_public_encrypt(flen, from, to, rsa, padding)
  #define RSA_private_decrypt(flen, from, to, rsa, padding)		    lsl_openssl->RSA_private_decrypt(flen, from, to, rsa, padding)
  #define RSA_sign(type, m, m_len, sigret, siglen, rsa)			      lsl_openssl->RSA_sign(type, m, m_len, sigret, siglen, rsa)
  #define ERR_get_error()											                    lsl_openssl->ERR_get_error()
  #define ERR_error_string(e, buf)								                lsl_openssl->ERR_error_string(e, buf)
  #define RSA_verify(type, m, m_len, sigbuf, siglen, rsa)			    lsl_openssl->RSA_verify(type, m, m_len, sigbuf, siglen, rsa)
  
  #define OBJ_txt2nid(s) 											                    lsl_openssl->OBJ_txt2nid(s)
  #define X509_NAME_ENTRY_create_by_NID(ne, nid, type, bytes, len) 	lsl_openssl->X509_NAME_ENTRY_create_by_NID(ne, nid, type, bytes, len)
  #define X509_NAME_add_entry(name, ne,loc,set)					          lsl_openssl->X509_NAME_add_entry(name, ne,loc,set)
  #define X509V3_EXT_conf(  conf, ctx, name, value)	              lsl_openssl->X509V3_EXT_conf(  conf, ctx, name, value)
  #define X509_add_ext(x, ex, loc)								                lsl_openssl->X509_add_ext(x, ex, loc)
  #define X509_EXTENSION_free(a)									                lsl_openssl->X509_EXTENSION_free(a)
  #define X509_new()												                      lsl_openssl->X509_new()
  #define X509_set_version(x, version)							              lsl_openssl->X509_set_version(x, version)
  #define X509_get_serialNumber(x)								                lsl_openssl-> X509_get_serialNumber(x)
  #define OPENSSL_Realloc(addr, num)								              lsl_openssl->OPENSSL_Realloc(addr, num, __FILE__,__LINE__)
  #define ASN1_INTEGER_set(a, v) 									                lsl_openssl->ASN1_INTEGER_set(a, v)
  #define X509_set_pubkey(x, pkey) 								                lsl_openssl->X509_set_pubkey(x, pkey)
  #define X509_NAME_new()											                    lsl_openssl->X509_NAME_new()
  #define X509_set_subject_name(x, name)							            lsl_openssl->X509_set_subject_name(x, name)
  #define X509_set_issuer_name(x, name)							              lsl_openssl->X509_set_issuer_name(x, name)
  #define X509_gmtime_adj(s, adj)									                lsl_openssl->X509_gmtime_adj(s, adj)
  #define X509V3_set_ctx(ctx, issuer, subj, req, crl, flags)		  lsl_openssl->X509V3_set_ctx(ctx, issuer, subj, req, crl, flags)
  #define X509_sign(x, pkey, md)									                lsl_openssl->X509_sign(x, pkey, md)
  #define X509_NAME_free(a)										                    lsl_openssl->X509_NAME_free(a)
  #define i2d_X509_bio(bp, x)										                  lsl_openssl->i2d_X509_bio(bp, x)
  #define d2i_X509_bio(bp, x)								                      lsl_openssl->d2i_X509_bio(bp, x)
  #define PEM_read_bio_X509(bp, x, cb, u)					                lsl_openssl->PEM_read_bio_X509(bp, x, cb, u)
  #define X509_get_pubkey(x) 										                  lsl_openssl->X509_get_pubkey(x)
  #define OBJ_obj2nid(o)											                    lsl_openssl->OBJ_obj2nid(o)
  #define BIO_new(t)                                              lsl_openssl->BIO_new(t)
  
  //functions available from API version >= 2
  #define i2d_X509(x, out)			                                  lsl_openssl->i2d_X509(x, out)
  #define X509_verify(a, r)			                                  lsl_openssl->X509_verify(a, r)
  #define X509_STORE_new()			                                  lsl_openssl->X509_STORE_new()
  #define CRYPTO_add_lock(pointer, amount, type, file, line)			lsl_openssl->CRYPTO_add_lock(pointer, amount, type, file, line)
  #define X509_LOOKUP_file()			                                lsl_openssl->X509_LOOKUP_file()
  #define X509_LOOKUP_ctrl(ctx, cmd, argc, argl, ret)			        lsl_openssl->X509_LOOKUP_ctrl(ctx, cmd, argc, argl, ret)
  #define X509_verify_cert(ctx)			                              lsl_openssl->X509_verify_cert(ctx)
  #define X509_NAME_oneline(a, buf, size)			                    lsl_openssl->X509_NAME_oneline(a, buf, size)
  #define X509_load_crl_file(ctx, file, type)			                lsl_openssl->X509_load_crl_file(ctx, file, type)
  #define X509_STORE_CTX_new()			                              lsl_openssl->X509_STORE_CTX_new()
  #define X509_STORE_CTX_free(ctx)			                          lsl_openssl->X509_STORE_CTX_free(ctx)
  #define X509_STORE_CTX_init(ctx, store, x509, chain)			      lsl_openssl->X509_STORE_CTX_init(ctx, store, x509, chain)
  #define X509_get_issuer_name(a)			                            lsl_openssl->X509_get_issuer_name(a)
  #define X509_LOOKUP_hash_dir()			                            lsl_openssl->X509_LOOKUP_hash_dir()
  #define X509_STORE_set_flags(ctx, flags)			                  lsl_openssl->X509_STORE_set_flags(ctx, flags)
  #define X509_STORE_add_lookup(v,  m)			                      lsl_openssl->X509_STORE_add_lookup(v,  m)
  #define X509_STORE_set_default_paths(ctx)			                  lsl_openssl->X509_STORE_set_default_paths(ctx)
  #define X509_STORE_CTX_get_ex_data(ctx, idx)			              lsl_openssl->X509_STORE_CTX_get_ex_data(ctx, idx)
  #define X509_STORE_CTX_set_ex_data(ctx, idx, data)			        lsl_openssl->X509_STORE_CTX_set_ex_data(ctx, idx, data)
  #define X509_STORE_CTX_get_error(ctx)			                      lsl_openssl->X509_STORE_CTX_get_error(ctx)
  #define X509_STORE_CTX_get_current_cert(ctx)			              lsl_openssl->X509_STORE_CTX_get_current_cert(ctx)
  #define X509_STORE_CTX_get_error_depth(ctx)			                lsl_openssl->X509_STORE_CTX_get_error_depth(ctx)
  #define X509_verify_cert_error_string(n)			                  lsl_openssl->X509_verify_cert_error_string(n)
  #define i2d_PublicKey(a, pp)			                              lsl_openssl->i2d_PublicKey(a, pp)
  #define EVP_PKEY_type(type)			                                lsl_openssl->EVP_PKEY_type(type)
  #define CRYPTO_realloc(addr, num, file, line)			              lsl_openssl->CRYPTO_realloc(addr, num, file, line)
  #define BIO_ctrl(bp, cmd, larg, parg)			                      lsl_openssl->BIO_ctrl(bp, cmd, larg, parg)
  #define BIO_s_mem()			                                        lsl_openssl->BIO_s_mem()
  #define BIO_s_file()			                                      lsl_openssl->BIO_s_file()
  #define X509_get_ext(x, loc)			                              lsl_openssl->X509_get_ext(x, loc)
  #define EVP_PKEY_cmp(a, b)			                                lsl_openssl->EVP_PKEY_cmp(a, b)
  #define EVP_PKEY_new()			                                    lsl_openssl->EVP_PKEY_new()
  #define ASN1_TIME_set(s, t)			                                lsl_openssl->ASN1_TIME_set(s, t)
  #define X509_CRL_sign(x, pkey, md)			                        lsl_openssl->X509_CRL_sign(x, pkey, md)
  #define X509_PUBKEY_get(key)			                              lsl_openssl->X509_PUBKEY_get(key)
  #define EVP_PKEY_assign(pkey, type, key)			                  lsl_openssl->EVP_PKEY_assign(pkey, type, key)
  #define X509V3_EXT_print(out, ext, flag, indent)			          lsl_openssl->X509V3_EXT_print(out, ext, flag, indent)
  #define X509_get_ext_by_NID(x, nid, lastpos)			              lsl_openssl->X509_get_ext_by_NID(x, nid, lastpos)
  #define X509_CRL_set_version(x, version)			                  lsl_openssl->X509_CRL_set_version(x, version)
  #define X509_CRL_add0_revoked(crl, rev)			                    lsl_openssl->X509_CRL_add0_revoked(crl, rev)
  #define X509_CRL_add1_ext_i2d(x, nid, value, crit, flags)			  lsl_openssl->X509_CRL_add1_ext_i2d(x, nid, value, crit, flags)
  #define X509_CRL_set_lastUpdate(x, tm)			                    lsl_openssl->X509_CRL_set_lastUpdate(x, tm)
  #define X509_CRL_set_nextUpdate(x, tm)			                    lsl_openssl->X509_CRL_set_nextUpdate(x, tm)
  #define X509_NAME_add_entry_by_txt(name, field, type, bytes, len, loc, set)			lsl_openssl->X509_NAME_add_entry_by_txt(name, field, type, bytes, len, loc, set)
  #define X509_REVOKED_set_revocationDate(r, tm)			            lsl_openssl->X509_REVOKED_set_revocationDate(r, tm)
  #define X509_CRL_set_issuer_name(x, name)			                  lsl_openssl->X509_CRL_set_issuer_name(x, name)
  #define X509_REVOKED_set_serialNumber(x, serial)			          lsl_openssl->X509_REVOKED_set_serialNumber(x, serial)
  #define X509_NAME_ENTRY_free(ne)                                lsl_openssl->X509_NAME_ENTRY_free(ne) 
	#define X509_CRL_new()                                          lsl_openssl->X509_CRL_new()
	#define X509_CRL_free(crl)                                      lsl_openssl->X509_CRL_free(crl)
	#define ASN1_TIME_free(mut)                                     lsl_openssl->ASN1_TIME_free(mut) 
	#define ASN1_INTEGER_new()                                      lsl_openssl->ASN1_INTEGER_new() 
	#define ASN1_INTEGER_free(a)                                    lsl_openssl->ASN1_INTEGER_free(a)
	#define X509_REVOKED_new()                                      lsl_openssl->X509_REVOKED_new() 
	#define X509_REVOKED_free(r)                                    lsl_openssl->X509_REVOKED_free(r)
	#define PEM_write_bio_X509_CRL(bp, x)                           lsl_openssl->PEM_write_bio_X509_CRL(bp, x)
	#define X509_cmp_time(s, t)                                     lsl_openssl->X509_cmp_time(s, t)

	//functions available from API version >= 3
	#define X509_get_notBefore(x)                                   lsl_openssl->X509_get_notBefore(x)
	#define X509_get_notAfter(x)                                    lsl_openssl->X509_get_notAfter(x)

	//functions available from API version >= 4
	#define EVP_sha256()												                    lsl_openssl->EVP_sha256()
	#define SHA256(d, n, md)  										                  lsl_openssl->SHA256(d, n, md)

	//functions available from API version >= 5
	#define BIO_write(b, data, len)  										            lsl_openssl->BIO_write(b, data, len)
	#define PEM_read_bio_RSA_PUBKEY(bp, x, cb, u)  									lsl_openssl->PEM_read_bio_RSA_PUBKEY(bp, x, cb, u)
	#define SHA512_Init(c)  										                    lsl_openssl->SHA512_Init(c)
	#define SHA512_Update(c, data, len)  										        lsl_openssl->SHA512_Update(c, data, len)
	#define SHA512_Final(md, c)  										                lsl_openssl->SHA512_Final(md, c)      
	#define SHA512(d, n, md)  										                  lsl_openssl->SHA512(d, n, md)

#endif /* _LSL_C_OPENSSL_H */
