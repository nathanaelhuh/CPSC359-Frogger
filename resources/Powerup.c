/* GIMP RGBA C-Source image dump (Powerup.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[32 * 32 * 2 + 1];
} Powerup = {
  32, 32, 2,
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\376\006\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\376\006\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\040\372"
  "\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376"
  "\006\376\006\376\006\376\006\040\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\040\372\040\372\040\372\040\372\040\372\040\372\000\000"
  "\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\040\372\040\372\040"
  "\372\040\372\040\372\040\372\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\040\372\040\372"
  "\040\372\040\372\040\372\040\372\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376"
  "\006\376\006\376\006\040\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\040\372\040\372\040\372\340&\340&\340&\340&\340&\340&\376"
  "\006\376\006\376\006\376\006\376\006\040\372\040\372\040\372\040\372\040\372\040\372\040\372"
  "\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\000\000\000\000\000\000\040\372\040\372"
  "\040\372\340&\340&\340&\340&\340&\340&\376\006\376\006\376\006\376\006\376\006\040\372"
  "\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040"
  "\372\000\000\000\000\000\000\000\000\000\000\000\000\040\372\040\372\040\372\340&\340&\340&\340&\340"
  "&\340&\376\006\376\006\376\006\376\006\376\006\040\372\040\372\040\372\040\372\040\372\040"
  "\372\040\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\340&\340&\340"
  "&\340&\340&\340&\340&\340&\340&\040\372\040\372\040\372\040\372\040\372\040\372"
  "\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040"
  "\372\040\372\040\372\040\372\376\006\376\006\376\006\340&\340&\340&\340&\340&\340"
  "&\340&\340&\340&\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372"
  "\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040"
  "\372\040\372\376\006\376\006\376\006\340&\340&\340&\340&\340&\340&\340&\340&\340"
  "&\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040"
  "\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\376\006"
  "\376\006\376\006\000\000\000\000\000\000\040\372\040\372\040\372\340&\340&\340&\340&\340&\340"
  "&\376\006\376\006\376\006\376\006\376\006\040\372\040\372\040\372\040\372\040\372\040\372"
  "\040\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\000\000\000\000\000\000\040\372"
  "\040\372\040\372\340&\340&\340&\340&\340&\340&\376\006\376\006\376\006\376\006\376"
  "\006\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372"
  "\040\372\040\372\000\000\000\000\000\000\000\000\000\000\000\000\040\372\040\372\040\372\340&\340&\340"
  "&\340&\340&\340&\376\006\376\006\376\006\376\006\376\006\040\372\040\372\040\372\040\372"
  "\040\372\040\372\040\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\000\000"
  "\000\000\000\000\040\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\376\006\376"
  "\006\376\006\376\006\376\006\376\006\376\006\376\006\040\372\040\372\040\372\040\372\040\372"
  "\040\372\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\040\372\040\372\040\372\040\372\040"
  "\372\040\372\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\040"
  "\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\040\372\040\372\040\372\040\372\040\372\040\372\000\000\000\000\000\000\376\006\376\006\376"
  "\006\376\006\376\006\376\006\376\006\376\006\040\372\040\372\040\372\040\372\040\372\040\372"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\376\006\376\006\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006\376\006"
  "\376\006\376\006\376\006\376\006\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\376\006\376\006\376\006\376\006\376\006"
  "\376\006\376\006\376\006\376\006\376\006\376\006\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000",
};

