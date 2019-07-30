#ifndef BUFFER_H
# define BUFFER_H
# include <stdlib.h>

void	fill_buffer_with(void *buf, void *model, unsigned int elt_size, unsigned int elt_count);
void	clear_buffer(void *buf, unsigned int elt_size, unsigned int elt_count);
void	*build_larger_buffer(void *buf, unsigned int elt_size, unsigned int old_count, unsigned int new_count);
void	copy_buffer(void *dest, void *src, unsigned int elt_size, unsigned int elt_count);
void	shiftl_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count);
void	shiftr_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count);
void	rolr_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count);
void	roll_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, unsigned int count);
void	insert_buffer(void *buf, unsigned int elt_size, unsigned int elt_count, void *ins, unsigned int ins_count, unsigned int pos);
#endif
