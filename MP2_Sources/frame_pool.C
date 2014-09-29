#include "frame_pool.H"
FramePool:: FramePool(unsigned long _base_frame_no,
             unsigned long _nframes,
             unsigned long _info_frame_no)

{
	
this._base_frame_no = _base_frame_no;
this._nframes = _nframes;
if (_info_frame_no !=0)
{
this._info_frame_no=_info_frame_no;
}
else
{
this._info_frame_no=0x00200000;
}
}

FramePool:: get_frame()
{

	if (

}


/*
 
 void alloc_frame(page_t *page, int is_kernel, int is_writeable)
{
   if (page->frame != 0)
   {
       return; // Frame was already allocated, return straight away.
   }
   else
   {
       u32int idx = first_frame(); // idx is now the index of the first free frame.
       if (idx == (u32int)-1)
       {
           // PANIC is just a macro that prints a message to the screen then hits an infinite loop.
           PANIC("No free frames!");
       }
       set_frame(idx*0x1000); // this frame is now ours!
       page->present = 1; // Mark it as present.
       page->rw = (is_writeable)?1:0; // Should the page be writeable?
       page->user = (is_kernel)?0:1; // Should the page be user-mode?
       page->frame = idx;
   }
}
 */
