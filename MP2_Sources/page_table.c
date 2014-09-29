#include "paging_low.H"
#include "page_table.H"

PageTable::PageTable * current_page_table; /* pointer to currently loaded page table object */
PageTable::static unsigned int    paging_enabled;     /* is paging turned on (i.e. are addresses logical)? */
PageTable::static FramePool     * kernel_mem_pool;    /* Frame pool for the kernel memory */
PageTable::static FramePool     * process_mem_pool;   /* Frame pool for the process memory */
PageTable::static unsigned long   shared_size;        /* size of shared address space */

/* Set the global parameters for the paging subsystem. */
void PageTable:: init_paging(FramePool * _kernel_mem_pool,
                             FramePool * _process_mem_pool,
                             const unsigned long _shared_size);
{
	this._kernel_mem_pool = _kernel_mem_pool;
	this._process_mem_pool = _process_mem_pool;
	this._shared_size = _shared_size;

}

PageTable::PageTable();
{
 	//initialize the page directory here
        page_directory[0] = (unsigned long)page_table | 3; //page table address and flags valid
        unsigned long i = 1;
        for(; i<1023; i++) {
                page_directory[i] = 0x2; //address 0 and flags invalid
        }
        page_directory[1023] = (unsigned long)page_directory | 3; //2 self referencing
        
        //initialize page table for first 2MB
        for(i=0; i<512; i++) {
                page_table[i] = i<<12 | 3; //mirrored physical address and flags valid
        }
        //initialize page table for the rest of the table
        for(i = 512; i<1024; i++) {
                page_table[i] = 0x2; //address 0 and flags invalid
        }
}

void load()
{
	write_cr3(page_directory);

}

void PageTable:: enable_paging()
{
 	//long temp = long read_cr0() 
 	write_cr0(read_cr0() | 0x80000000);
}

/* The page fault handler. */
void PageTable:: handle_fault(REGS * _r)
{

}

