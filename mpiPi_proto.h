/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 *
 *   Created: Tue Oct 26 16:25:48 2004
 */

extern int open_dwarf_executable ( char *fileName );
extern void close_dwarf_executable ( void );
extern void mpiPi_msg ( char *fmt, ... );
extern void mpiPi_abort ( char *fmt, ... );
extern void mpiPi_msg_debug ( char *fmt, ... );
extern void mpiPi_msg_warn ( char *fmt, ... );
extern void mpiP_init_api ( void );
extern int mpiP_record_traceback ( void* pc_array[], int max_stack );
extern int mpiP_open_executable ( char* filename );
extern void mpiP_close_executable ( void );
extern mpiP_TIMER mpiP_gettime ( void );
extern char* mpiP_get_executable_name ( void );
extern h_t * h_open ( int size, h_HashFunct hf, h_Comparator hc );
extern void h_close ( h_t * ht );
extern int h_count ( h_t * ht );
extern int h_insert ( h_t * ht, void *ptr );
extern void * h_search ( h_t * ht, void *key, void **ptr );
extern void * h_delete ( h_t * ht, void *key, void **ptr );
extern int h_gather_data ( h_t * ht, int *ac, void ***ptr );
extern void mpiPi_init ( char *appName );
extern int callsite_pc_cache_comparator ( const void *p1, const void *p2 );
extern int callsite_pc_cache_hashkey ( const void *p1 );
extern int mpiPi_query_pc ( void *pc, char **filename, char **functname, int *lineno );
extern int callsite_src_id_cache_comparator ( const void *p1, const void *p2 );
extern int callsite_src_id_cache_hashkey ( const void *p1 );
extern int mpiPi_query_src ( callsite_stats_t * p );
extern int mpiPi_mergeResults ( void );
extern void mpiPi_publishResults ( void );
extern void mpiPi_collect_basics ( void );
extern void mpiPi_generateReport ( void );
extern void mpiPi_finalize ( void );
extern void mpiPi_update_callsite_stats ( unsigned op, unsigned rank, void **pc, double dur, double sendSize, double ioSize );
extern char* mpiPdemangle ( const char* mangledSym );
extern int mpiP_find_src_loc ( void *i_addr_hex, char **o_file_str, int *o_lineno, char **o_funct_str );
extern int open_bfd_executable ( char *filename );
extern void close_bfd_executable ( void );
extern int MPI_Pcontrol ( const int flag, ... );
extern int mpi_pcontrol_ ( int *flag, ... );
extern double calc_COV ( double* data, int dataSize );
extern int mpiPi_profile_print ( FILE * fp );
extern char * GetBaseAppName ( char *rawName );
extern int mpiPi_RecordTraceBack ( jmp_buf jb, void *pc_array[], int max_back );
extern void mpiPi_getenv ( void );
extern char* getProcExeLink ( void );
extern void getProcCmdLine ( int* ac, char** av, int max_args );
extern void mpiPi_copy_args ( int *ac, char **av, int av_len );
extern void mpiPi_copy_given_args ( int *ac, char **av, int av_len, int argc, char **argv );
extern long mpiPi_get_text_start(char *filename);
