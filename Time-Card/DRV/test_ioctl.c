#include <sys/fcntl.h> 
#include <sys/stat.h>
#include <sys/ioctl.h>      
#include <unistd.h>     
#include <stdio.h>
#include <stdlib.h>
#include "oscillator_mRO50_ioctl.h"

typedef u_int32_t uint32_t;
typedef u_int32_t u32;

/* our ioctl header file */
int main()
{
	uint32_t freq_value = 0;
	uint32_t temp_value = 0;
	int fd;
	char *new_name = "lorem_ipsum"; /* must not be longer than MAX_PART_NAME */
	fd = open("/dev/oscillator_mRO50", O_RDWR);
	if (fd == -1){
		printf("Error while opening mRO50 char device !\n");
		return -1;
	}
	ioctl(fd, MRO50_READ_FINE, &freq_value); /* ioctl call to get partition size */
	freq_value +=10;
	printf("freq_value is %d\n", freq_value);
	ioctl(fd, MRO50_ADJUST_FINE, &freq_value);

	ioctl(fd, MRO50_READ_COARSE, &freq_value); /* ioctl call to get partition size */
	freq_value +=10;
	printf("freq_value is %d\n", freq_value);
	ioctl(fd, MRO50_ADJUST_COARSE, &freq_value);

	ioctl(fd, MRO50_READ_TEMP, &temp_value);
	printf("temp_value is %x\n", temp_value);
	close(fd);
	return 0;
}
