/* $**************** KCG Version 6.4 (build i21) ****************
** Command: kcg64.exe -config C:/WindRiver/workspace/TR4/TL/config.txt
** Generation date: 2017-10-11T17:54:54
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#define KCG_MAPW_CPY

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif /* kcg_int */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_real
#define kcg_real kcg_real
typedef double kcg_real;
#endif /* kcg_real */

#ifndef kcg_char
#define kcg_char kcg_char
typedef char kcg_char;
#endif /* kcg_char */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* Architecture::sortie::SM1 */
typedef enum kcg_tag_SSM_TR_SM1 {
  SSM_TR_no_trans_SM1,
  SSM_TR_Repos_1_SM1,
  SSM_TR_Repos_2_SM1,
  SSM_TR_Sortie_P1_1_SM1,
  SSM_TR_Sortie_P1_2_SM1,
  SSM_TR_Sortie_P2_1_SM1,
  SSM_TR_Sortie_P2_2_SM1
} SSM_TR_SM1;
/* Architecture::sortie::SM1 */
typedef enum kcg_tag_SSM_ST_SM1 {
  SSM_st_Repos_SM1,
  SSM_st_Sortie_P1_SM1,
  SSM_st_Sortie_P2_SM1
} SSM_ST_SM1;
/* Architecture::capteurs_sortie_global */
typedef kcg_bool capteurs_sortie_global_Architecture[1];

/* Architecture::capteurs_entree_global */
typedef kcg_bool capteurs_entree_global_Architecture[9];

/* Architecture::cmd_entree_global */
typedef kcg_bool cmd_entree_global_Architecture[7];

/* Architecture::mode_fonct_global */
typedef kcg_bool mode_fonct_global_Architecture[2];

/* Architecture::capteurs_global */
typedef kcg_bool capteurs_global_Architecture[18];

/* Architecture::actionneurs_global */
typedef kcg_bool actionneurs_global_Architecture[19];

/* Architecture::type_piece_global */
typedef kcg_int type_piece_global_Architecture[1];

typedef kcg_bool array_bool_5[5];

/* Architecture::cmd_poste_global */
typedef array_bool_5 cmd_poste_global_Architecture;

/* Architecture::capteurs_file_global */
typedef array_bool_5 capteurs_file_global_Architecture;

typedef kcg_bool array_bool_4[4];

/* Architecture::capteurs_poste_global */
typedef array_bool_4 capteurs_poste_global_Architecture;

/* Architecture::cmd_file_global */
typedef array_bool_4 cmd_file_global_Architecture;

#ifndef kcg_copy_array_bool_5
#define kcg_copy_array_bool_5(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_bool_5)))
#endif /* kcg_copy_array_bool_5 */

#ifndef kcg_copy_array_bool_4
#define kcg_copy_array_bool_4(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_bool_4)))
#endif /* kcg_copy_array_bool_4 */

#ifndef kcg_copy_actionneurs_global_Architecture
#define kcg_copy_actionneurs_global_Architecture(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (actionneurs_global_Architecture)))
#endif /* kcg_copy_actionneurs_global_Architecture */

#ifndef kcg_copy_capteurs_global_Architecture
#define kcg_copy_capteurs_global_Architecture(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (capteurs_global_Architecture)))
#endif /* kcg_copy_capteurs_global_Architecture */

#ifndef kcg_copy_mode_fonct_global_Architecture
#define kcg_copy_mode_fonct_global_Architecture(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (mode_fonct_global_Architecture)))
#endif /* kcg_copy_mode_fonct_global_Architecture */

#ifndef kcg_copy_capteurs_entree_global_Architecture
#define kcg_copy_capteurs_entree_global_Architecture(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (capteurs_entree_global_Architecture)))
#endif /* kcg_copy_capteurs_entree_global_Architecture */

#ifndef kcg_copy_capteurs_sortie_global_Architecture
#define kcg_copy_capteurs_sortie_global_Architecture(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (capteurs_sortie_global_Architecture)))
#endif /* kcg_copy_capteurs_sortie_global_Architecture */

#ifndef kcg_copy_type_piece_global_Architecture
#define kcg_copy_type_piece_global_Architecture(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (type_piece_global_Architecture)))
#endif /* kcg_copy_type_piece_global_Architecture */

#ifndef kcg_copy_cmd_entree_global_Architecture
#define kcg_copy_cmd_entree_global_Architecture(kcg_C1, kcg_C2) (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (cmd_entree_global_Architecture)))
#endif /* kcg_copy_cmd_entree_global_Architecture */

#ifdef kcg_use_array_bool_5
#ifndef kcg_comp_array_bool_5
extern kcg_bool kcg_comp_array_bool_5(
  array_bool_5 *kcg_c1,
  array_bool_5 *kcg_c2);
#endif /* kcg_comp_array_bool_5 */
#endif /* kcg_use_array_bool_5 */

#ifdef kcg_use_array_bool_4
#ifndef kcg_comp_array_bool_4
extern kcg_bool kcg_comp_array_bool_4(
  array_bool_4 *kcg_c1,
  array_bool_4 *kcg_c2);
#endif /* kcg_comp_array_bool_4 */
#endif /* kcg_use_array_bool_4 */

#ifdef kcg_use_actionneurs_global_Architecture
#ifndef kcg_comp_actionneurs_global_Architecture
extern kcg_bool kcg_comp_actionneurs_global_Architecture(
  actionneurs_global_Architecture *kcg_c1,
  actionneurs_global_Architecture *kcg_c2);
#endif /* kcg_comp_actionneurs_global_Architecture */
#endif /* kcg_use_actionneurs_global_Architecture */

#ifdef kcg_use_capteurs_global_Architecture
#ifndef kcg_comp_capteurs_global_Architecture
extern kcg_bool kcg_comp_capteurs_global_Architecture(
  capteurs_global_Architecture *kcg_c1,
  capteurs_global_Architecture *kcg_c2);
#endif /* kcg_comp_capteurs_global_Architecture */
#endif /* kcg_use_capteurs_global_Architecture */

#ifdef kcg_use_mode_fonct_global_Architecture
#ifndef kcg_comp_mode_fonct_global_Architecture
extern kcg_bool kcg_comp_mode_fonct_global_Architecture(
  mode_fonct_global_Architecture *kcg_c1,
  mode_fonct_global_Architecture *kcg_c2);
#endif /* kcg_comp_mode_fonct_global_Architecture */
#endif /* kcg_use_mode_fonct_global_Architecture */

#ifdef kcg_use_capteurs_entree_global_Architecture
#ifndef kcg_comp_capteurs_entree_global_Architecture
extern kcg_bool kcg_comp_capteurs_entree_global_Architecture(
  capteurs_entree_global_Architecture *kcg_c1,
  capteurs_entree_global_Architecture *kcg_c2);
#endif /* kcg_comp_capteurs_entree_global_Architecture */
#endif /* kcg_use_capteurs_entree_global_Architecture */

#ifdef kcg_use_capteurs_sortie_global_Architecture
#ifndef kcg_comp_capteurs_sortie_global_Architecture
extern kcg_bool kcg_comp_capteurs_sortie_global_Architecture(
  capteurs_sortie_global_Architecture *kcg_c1,
  capteurs_sortie_global_Architecture *kcg_c2);
#endif /* kcg_comp_capteurs_sortie_global_Architecture */
#endif /* kcg_use_capteurs_sortie_global_Architecture */

#ifdef kcg_use_type_piece_global_Architecture
#ifndef kcg_comp_type_piece_global_Architecture
extern kcg_bool kcg_comp_type_piece_global_Architecture(
  type_piece_global_Architecture *kcg_c1,
  type_piece_global_Architecture *kcg_c2);
#endif /* kcg_comp_type_piece_global_Architecture */
#endif /* kcg_use_type_piece_global_Architecture */

#ifdef kcg_use_cmd_entree_global_Architecture
#ifndef kcg_comp_cmd_entree_global_Architecture
extern kcg_bool kcg_comp_cmd_entree_global_Architecture(
  cmd_entree_global_Architecture *kcg_c1,
  cmd_entree_global_Architecture *kcg_c2);
#endif /* kcg_comp_cmd_entree_global_Architecture */
#endif /* kcg_use_cmd_entree_global_Architecture */

#define kcg_comp_cmd_poste_global_Architecture kcg_comp_array_bool_5

#define kcg_copy_cmd_poste_global_Architecture kcg_copy_array_bool_5

#define kcg_comp_capteurs_poste_global_Architecture kcg_comp_array_bool_4

#define kcg_copy_capteurs_poste_global_Architecture kcg_copy_array_bool_4

#define kcg_comp_cmd_file_global_Architecture kcg_comp_array_bool_4

#define kcg_copy_cmd_file_global_Architecture kcg_copy_array_bool_4

#define kcg_comp_capteurs_file_global_Architecture kcg_comp_array_bool_5

#define kcg_copy_capteurs_file_global_Architecture kcg_copy_array_bool_5

#endif /* _KCG_TYPES_H_ */
/* $**************** KCG Version 6.4 (build i21) ****************
** kcg_types.h
** Generation date: 2017-10-11T17:54:54
*************************************************************$ */

