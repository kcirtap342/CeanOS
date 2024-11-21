#include <stdint.h>
#include "string.h"
#include <mm/malloc.h>

int strcmp(const char *x, const char *y)
{
	uint8_t i = 0;
	uint8_t j = 0;

	while (x[i] != '\0') {
		i++;
	}
	while (y[j] != '\0') {
		if (y[j] != x[j]) {
			return 0;
		}
		j++;
	}
	if (i == j) {
		return 1;
	} else {
		return 0;
	}
}

char *strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0') {
		return (char *)haystack;
	}

	for (; *haystack != '\0'; haystack++) {
		const char *h = haystack;
		const char *n = needle;

		while (*h == *n && *n != '\0') {
			h++;
			n++;
		}

		if (*n == '\0') {
			return (char *)haystack;
		}
	}

	return NULL;
}

// 0 is true
// -1 is false

int strncmp(const char* str1,const char* str2, size_t n ){
        int val=0;
	
	if (*str1+n > *str2+n) {
		val = 1;
	}

	else if (*str1+n < *str2+n) {
		val = -1;
	}
	else {
		val = 0;
	}

	return val;
}

char *strncat(char *dest, const char *src, size_t n) {
    char *dest_ptr = dest;
    while (*dest_ptr) {
        dest_ptr++;  
    }

    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest_ptr[i] = src[i];  
    }

    dest_ptr[i] = '\0';

    return dest;
}

char* strncpy(char* dest, const char* src, size_t n)
{
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		dest[i] = src[i];
	}

	for (; i < n; i++) {
		dest[i] = '\0';
	}

	return dest;
}

size_t strlen(const char* str)
{
	size_t length = 0;

	while (str[length] != '\0') {
		length++;
	}

	return length;
}

void strcpy(char *dest, const char* src)
{
	while (*src) {
		*dest++ = *src++;
	}
	*dest = '\0';
}

void strcat(char* dest, const char* src)
{
	while (*dest) dest++;
	while (*src) *dest++ = *src++;
	*dest = '\0';
}

char *strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;  
    }
    
    if (c == '\0') {
        return (char *)str;
    }

    return NULL;
}

char *strdup(const char *str) {
    size_t len = strlen(str) + 1; 
    char *copy = (char *)kmalloc(len);  
    if (copy) {
        memcpy(copy, str, len);  
    }
    return copy;  
}