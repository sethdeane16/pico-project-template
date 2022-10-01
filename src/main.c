#include <stdio.h>
#include "library-template.h"
#include "project-template.h"

#include "pico/stdlib.h"
#include "hardware/address_mapped.h"
#include "hardware/regs/sysinfo.h"

uint32_t rp2040_registerread(){
	uint32_t chip_id = *((io_ro_32*)(SYSINFO_BASE + SYSINFO_CHIP_ID_OFFSET));
	uint32_t manufacturer = (chip_id & SYSINFO_CHIP_ID_MANUFACTURER_BITS)  >> SYSINFO_CHIP_ID_MANUFACTURER_LSB;
	uint32_t part         = (chip_id & SYSINFO_CHIP_ID_PART_BITS)          >> SYSINFO_CHIP_ID_PART_LSB;
	uint     version      = (chip_id & SYSINFO_CHIP_ID_REVISION_BITS)      >> SYSINFO_CHIP_ID_REVISION_LSB;
	return (uint32_t) manufacturer;
}

int main() {
	
    stdio_init_all();
    while (true) {
        example(500);
        printf("0x%x\n", rp2040_registerread());
        sleep_ms(1000);
    }
    return 0;
}

