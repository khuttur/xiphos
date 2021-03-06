/*
  Xiphos, a UCI chess engine
  Copyright (C) 2018 Milos Tatarevic

  Xiphos is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Xiphos is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HASH_H
#define HASH_H

#include "game.h"
#include "pthread.h"
#include "search.h"

enum {
  HASH_BOUND_NOT_USED,
  HASH_LOWER_BOUND,
  HASH_UPPER_BOUND,
  HASH_EXACT,
};

enum {
  Z_KEYS_EP_FLAG = (EMPTY + 1),
  Z_KEYS_MAX_INDEX,
};

struct {
  uint64_t positions[SQ_LIMIT][Z_KEYS_MAX_INDEX];
  uint64_t c_flags[C_FLAG_MAX];
  uint64_t side_flag;
} shared_z_keys;

typedef union {
  struct {
    move_t move;
    int8_t depth;
    uint8_t bound, iter;
  };
  uint64_t raw;
} hash_data_t;

int adjust_hash_score(int, int);
hash_data_t get_hash_data(search_data_t *);
void set_hash_data(search_data_t *, int, move_t, int, int, int);
void set_hash_iteration();
void reset_hash_key(search_data_t *);
uint64_t init_hash(int);

#endif
