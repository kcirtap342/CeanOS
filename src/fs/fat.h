#pragma once

#include <stdint.h>

#define FAT_SIGNATURE1 0x28
#define FAT_SIGNATURE2 0x29
#define FAT_EOF 0x0ffffff8
#define FAT_DELETED 0xE5
#define PADDING_CHAR 0x20

typedef struct {
	uint8_t  bootjmp[3];
	uint8_t  oem_name[8];
	uint16_t bytes_per_sector;
	uint8_t  sectors_per_cluster;
	uint16_t reserved_sectors;
	uint8_t  number_of_fat;
	uint16_t root_entry_count;
	uint16_t sector_count_small;
	uint8_t  media_type;
	uint16_t sectors_per_fat_12_16;
	uint16_t sectors_per_track;
	uint16_t head_side_count;
	uint32_t hidden_sector_count;
	uint32_t sector_count;
	// extended fat32 stuff
	uint32_t sectors_per_fat;
	uint16_t extended_flags;
	uint16_t fat_version;
	uint32_t root_cluster;
	uint16_t fat_info;
	uint16_t backup_BS_sector;
	uint8_t  reserved_0[12];
	uint8_t  drive_number;
	uint8_t  reserved_1;
	uint8_t  boot_signature;
	uint32_t volume_id;
	uint8_t  volume_label[11];
	uint8_t  fat_type_label[8];
	// this will be cast to it's specific type once the driver actually knows what
	// type of FAT this is.
	// uint8_t extended_section[54];
	// extras
	uint32_t fat_begin_lba;
	uint32_t cluster_begin_lba;
	bool     works;
} __attribute__((packed)) FAT32;

#pragma pack(push, 1)
typedef struct FAT32_Directory {
	char     filename[11];
	uint8_t  attributes;
	uint8_t  ntReserved;
	uint8_t  creationTimeSeconds;
	uint16_t creationTime;
	uint16_t creationDate;
	uint16_t lastAccessDate;
	uint16_t firstClusterHigh;
	uint16_t lastModificationTime;
	uint16_t lastModificationDate;
	uint16_t firstClusterLow;
	uint32_t filesize;
	uint32_t lba;
	uint16_t currEntry;
} __attribute__((packed)) FAT32_Directory, *pFAT32_Directory;
#pragma pack(pop)

#pragma pack(push, 1)

typedef struct FAT32_LFN {
	uint8_t  order;
	uint16_t char_sequence_1[5];
	uint8_t  attributes;
	uint8_t  lfn_type;
	uint8_t  checksum;
	uint16_t char_sequence_2[6];
	uint8_t  zero[2];
	uint16_t char_sequence_3[2];
} __attribute__((packed)) FAT32_LFN;

#pragma pack(pop)
uint8_t FAT32_DBG_PROMPTS = 0;

#define ClusterComb(high, low) (((uint32_t)(high) << 16) | (uint32_t)(low))
