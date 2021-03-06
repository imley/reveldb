/*
 * =============================================================================
 *
 *       Filename:  rpc.h
 *
 *    Description:  reveldb rpc implementation.
 *
 *        Created:  12/15/2012 04:43:52 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _REVELDB_RPC_H_
#define _REVELDB_RPC_H_

#include <reveldb/reveldb.h>

typedef struct reveldb_rpc_callbacks_s_ reveldb_rpc_callbacks_t;
typedef struct reveldb_rpc_s_ reveldb_rpc_t;

struct reveldb_rpc_callbacks_s_ {
    /* only for server status test. */
    evhttpx_callback_t  *rpc_void_cb;
    evhttpx_callback_t  *rpc_echo_cb;
    evhttpx_callback_t  *rpc_head_cb;

    /* reveldb reports and internal leveldb storage engine status. */
    evhttpx_callback_t  *rpc_report_cb;
    evhttpx_callback_t  *rpc_status_cb;
    evhttpx_callback_t  *rpc_property_cb;

    /* admin operations. */
    evhttpx_callback_t  *rpc_new_cb;
    evhttpx_callback_t  *rpc_compact_cb;
    evhttpx_callback_t  *rpc_size_cb;
    evhttpx_callback_t  *rpc_repair_cb;
    evhttpx_callback_t  *rpc_destroy_cb;

    /* set(C), get(R), update(U), delete(D) (CRUD)operations. */

    /* set related operations. */
    evhttpx_callback_t  *rpc_add_cb;
    evhttpx_callback_t  *rpc_set_cb;
    evhttpx_callback_t  *rpc_mset_cb;
    evhttpx_callback_t  *rpc_append_cb;
    evhttpx_callback_t  *rpc_prepend_cb;
    evhttpx_callback_t  *rpc_insert_cb;

    /* get related operations. */
    evhttpx_callback_t  *rpc_get_cb;
    evhttpx_callback_t  *rpc_mget_cb;
    evhttpx_callback_t  *rpc_seize_cb;
    evhttpx_callback_t  *rpc_mseize_cb;
    evhttpx_callback_t  *rpc_range_cb;
    evhttpx_callback_t  *rpc_regex_cb;
    evhttpx_callback_t  *rpc_kregex_cb;
    evhttpx_callback_t  *rpc_vregex_cb;
    evhttpx_callback_t  *rpc_similar_cb;
    evhttpx_callback_t  *rpc_ksimilar_cb;
    evhttpx_callback_t  *rpc_vsimilar_cb;

    /* update related operations. */
    evhttpx_callback_t  *rpc_incr_cb;
    evhttpx_callback_t  *rpc_decr_cb;
    evhttpx_callback_t  *rpc_cas_cb;
    evhttpx_callback_t  *rpc_replace_cb;

    /* delete related operations. */
    evhttpx_callback_t  *rpc_del_cb;
    evhttpx_callback_t  *rpc_mdel_cb;
    evhttpx_callback_t  *rpc_remove_cb;
    evhttpx_callback_t  *rpc_clear_cb;

    /* iterator related operations. */
    evhttpx_callback_t  *rpc_iter_new_cb;
    evhttpx_callback_t  *rpc_iter_first_cb;
    evhttpx_callback_t  *rpc_iter_last_cb;
    evhttpx_callback_t  *rpc_iter_next_cb;
    evhttpx_callback_t  *rpc_iter_prev_cb;
    evhttpx_callback_t  *rpc_iter_forward_cb;
    evhttpx_callback_t  *rpc_iter_backward_cb;
    evhttpx_callback_t  *rpc_iter_seek_cb;
    evhttpx_callback_t  *rpc_iter_key_cb;
    evhttpx_callback_t  *rpc_iter_value_cb;
    evhttpx_callback_t  *rpc_iter_kv_cb;
    evhttpx_callback_t  *rpc_iter_destroy_cb;

    /* snapshot related operations. */
    evhttpx_callback_t  *rpc_snapshot_new_cb;
    evhttpx_callback_t  *rpc_snapshot_release_cb;

    /* writebatch related operations. */
    evhttpx_callback_t  *rpc_writebatch_new_cb;
    evhttpx_callback_t  *rpc_writebatch_put_cb;
    evhttpx_callback_t  *rpc_writebatch_delete_cb;
    evhttpx_callback_t  *rpc_writebatch_clear_cb;
    evhttpx_callback_t  *rpc_writebatch_commit_cb;
    evhttpx_callback_t  *rpc_writebatch_destroy_cb;

    /* miscs operations. */
    evhttpx_callback_t  *rpc_sync_cb;
    evhttpx_callback_t  *rpc_check_cb;
    evhttpx_callback_t  *rpc_exists_cb;
    evhttpx_callback_t  *rpc_version_cb;
};

struct reveldb_rpc_s_ {
    const char *host;
    uint32_t ports[REVELDB_RPC_MAX_PORTS_LISTENING_ON];
    uint32_t num_ports;
    int backlog;

    evbase_t *evbase;
    evhttpx_t *httpx;
    evhttpx_ssl_cfg_t *sslcfg;

    reveldb_rpc_callbacks_t *callbacks;
    reveldb_config_t *config;
};

extern reveldb_rpc_t * reveldb_rpc_init(reveldb_config_t *config);

extern void reveldb_rpc_run(reveldb_rpc_t *rpc);

extern void reveldb_rpc_stop(reveldb_rpc_t *rpc);

#endif // _REVELDB_RPC_H_
