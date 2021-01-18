#ifndef LIBPT_BUFFER_H
#define LIBPT_BUFFER_H

#include <stddef.h>  // size_t
#include <stdbool.h> // bool
#include <stdint.h>  // uint8_t
#include <stdio.h>   // FILE *

/**
 * \struct buffer_t
 * \brief A buffer structure.
 */

typedef struct {
    uint8_t * data; /**< Data stored in the buffer   */
    size_t    size; /**< Size of the data (in bytes) */
} buffer_t;

//-----------------------------------------------------------------
// Allocation
//-----------------------------------------------------------------


/**
 * \brief Create a buffer structure
 * \return Pointer to the newly created buffer structure
 *    NULL in case of failure
 */

buffer_t * buffer_create();

/**
 * \brief Duplicate a buffer instance
 * \param buffer The buffer to duplicate
 * \return The address of the newly created buffer, NULL
 *    if the memory allocation has failed.
 */

buffer_t * buffer_dup(const buffer_t * buffer);

/**
 * \brief Free a buffer structure.
 * \param buffer Pointer to the buffer structure to free
 */

void buffer_free(buffer_t * buffer);

//-----------------------------------------------------------------
// Accessors
//-----------------------------------------------------------------

/**
 * \brief Retrieve the address where data is stored
 * \param buffer A pointer to the buffer
 * \return The address of the data. Returns NULL
 *   if buffer == NULL or if it is empty.
 */

uint8_t * buffer_get_data(const buffer_t * buffer);

/**
 * \brief Retrieve the size of the allocated memory area
 * managed by the buffer
 * \param buffer The address of the buffer
 * \return The size (in bytes)
 */

size_t buffer_get_size(const buffer_t * buffer);

/**
 * \brief (Re)allocate the buffer to a specified size.
 * \param buffer Pointer to a buffer_t structure to (re)allocate
 * \param size new size of the buffer
 * \return true iif successfull
 */

bool buffer_resize(buffer_t * buffer, size_t size);

/**
 * \brief Change the address of the memory managed by the buffer.
 *   The old address but be freed before if not more used.
 * \param buffer The address of the altered buffer. It is automatically
 *   resized if required.
 * \param bytes Address of bytes copied in the buffer
 * \param num_bytes Number of bytes that must be copied in the buffer
 * \return true iif successfull.
 */

bool buffer_write_bytes(buffer_t * buffer, const void * bytes, size_t num_bytes);

/**
 * \brief Alter the size declared in the buffer structure.
 * It does not reallocate anything.
 * \param buffer The address of the buffer.
 */

void buffer_set_size(buffer_t * buffer, size_t size);

//-----------------------------------------------------------------

/**
 * \brief Print the buffer content on the standard output.
 * \param buffer The address of the buffer.
 */

void buffer_dump(const buffer_t * buffer);

/**
 * \brief Print the buffer content.
 * \param out The file descriptor of the output file.
 * \param buffer The address of the buffer.
 */

void buffer_fprintf(FILE * out, const buffer_t * buffer);

/**
 * \brief Print bytes.
 * \param out The file descriptor of the output file.
 * \param bytes The bytes to print (at least num_bytes allocated).
 * \param num_bytes The number of bytes to print.
 */

void hex_fprintf(FILE * out, const uint8_t * bytes, size_t num_bytes);

/**
 * \brief Print bytes in the standard output.
 * \param out The file descriptor of the output file.
 * \param bytes The bytes to print (at least num_bytes allocated).
 * \param num_bytes The number of bytes to print.
 */

void hex_dump(const uint8_t * bytes, size_t num_bytes);

#endif // LIBPT_BUFFER_H
