/* GIMP RGBA C-Source image dump (Time.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[100 * 32 * 2 + 1];
} Time = {
  100, 32, 2,
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\373\336"
  "\000\000\000\000q\214\377\377\377\377\377\377\347\071\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\373\336\000\000\000\000"
  "q\214\377\377\377\377\377\377\347\071\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\373\336\000\000\000\000q\214\377"
  "\377\377\377\377\377\347\071\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377"
  "\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377\377U\255\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377"
  "\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000\307\071"
  "u\255\373\336\276\367\377\377\276\367\333\336\323\234\000\000\000\000\000\000\004!\024\245"
  "\272\326\236\367\377\377\337\377<\347U\255\343\030\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000q\214y\316}\357\337\377\337\377\236\367\272\326\323\234\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\377\377Mk\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377"
  "\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377}\357U\255\276"
  "\367\377\377\377\377\377\377\377\377\377\377\377\377\377\377y\316\000\000\323"
  "\234\236\367\377\377\377\377\377\377\377\377\377\377\377\377\377\377\333"
  "\336\004!\000\000\000\000\000\000\000\000\000\000\000\000\000\000\252R\373\336\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\034\347IJ\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000Y\316\377\377\377\377\377\377Mk\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377\377U\255\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377}\357\000\000\000\000\000\000"
  "\000\000\000\000\353Z\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377<\347\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\226\265\000\000\000\000"
  "\000\000\000\000\000\000\000\000\353Z\236\367\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377<\347\004!\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "Y\316\377\377\377\377\377\377Mk\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377\377U\255\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377}\357\000\000\000\000\000\000\000\000\000\000"
  "\353Z\377\377\377\377\377\377\377\377\276\367\367\275\216s\206\061IJ\363\234"
  "\276\367\377\377\377\377\377\377\377\377\377\377y\316\060\204\010B\347\071\060"
  "\204<\347\377\377\377\377\236\367a\010\000\000\000\000\000\000\000\000\004!<\347\377\377\377"
  "\377\276\367\226\265mk\206\061\206\061mk\266\265\337\377\377\377\377\377\266"
  "\265\000\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\377\377Mk\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336"
  "\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377"
  "\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377\377\377\232\326IJ\000\000"
  "\000\000\000\000\000\000\000\000\363\234\377\377\377\377\377\377<\347\216s\000\000\000\000\000\000\000"
  "\000\000\000\313Z\377\377\377\377\377\377Mk\000\000\000\000\000\000\000\000\024\245\377\377\377"
  "\377]\357iJ\000\000\000\000\000\000\000\000\000\000\000\000\317{\377\377\377\377\236\367\242\020\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377\377U\255"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377}\357\000\000\000\000\000"
  "\000\000\000\000\000\353Z\377\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\000\000\000\000\307\071\377"
  "\377\377\377\377\377\307\071\000\000\000\000\000\000\000\000\000\000\000\000\000\000<\347\377\377\377"
  "\377\222\224\000\000\000\000\000\000\000\000<\347\377\377\377\377Mk\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000y\316\377\377\377\377\216s\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000iJ\377\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377"
  "]\357\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\276\367\377\377\377\377iJ\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\272\326\377\377\377\377\363\234\000\000\000\000\000\000\010B\377\377"
  "\377\377\034\347\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000U\255\377\377\377\377"
  "\024\245\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377"
  "\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377}\357"
  "\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\236\367\377\377\377\377\252R\000\000\000\000\000\000\000\000\000\000\000\000\000\000y\316\377"
  "\377\377\377\024\245\000\000\000\000\000\000\020\204\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\226\265\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333"
  "\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377"
  "\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "Y\316\377\377\377\377\024\245\000\000\000\000\000\000\262\224\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\327\275\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000iJ\377\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000Y\316\377\377\377\377\024\245\000\000\000\000\000\000\323\234\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\367\275\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000iJ\377\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377"
  "\377\377]\357\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000}\357\377\377\377\377\252R\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\024\245\000\000\000\000\000\000\060\204"
  "\377\377\377\377\333\336\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377"
  "\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377}\357"
  "\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377"
  "\377\377\024\245\000\000\000\000\000\000\313Z\377\377\377\377\236\367\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000iJ\377\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377"
  "]\357\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\024\245\000\000\000\000\000\000\000\000}\357\377\377"
  "\377\377\262\224\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377\377\377\377U\255\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377}\357\000\000\000\000\000\000\000"
  "\000\000\000\353Z\377\377\377\377]\357\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000}\357\377"
  "\377\377\377\252R\000\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\024\245"
  "\000\000\000\000\000\000\000\000\226\265\377\377\377\377\276\367\020\204\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000,c\272\326mk\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\333\336\377\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000i"
  "J\377\377\377\377}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000Y\316\377\377\377\377\024\245\000\000\000\000\000\000\000\000\246\061}\357\377\377"
  "\377\377\377\377\232\326\222\224\252R$!(B\216su\255\373\336\377\377\377\377"
  "mk\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\377\377Mk\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377"
  "\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377"
  "}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377"
  "\377\377\377\024\245\000\000\000\000\000\000\000\000\000\000Mk\276\367\377\377\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377"
  "mk\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\377\377Mk\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377"
  "\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377"
  "}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377"
  "\377\377\377\024\245\000\000\000\000\000\000\000\000\000\000\000\000\313Z\373\336\377\377\377\377"
  "\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\272\326"
  "IJ\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377\377\377\377\377\377Mk\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\333\336\377"
  "\377\377\377U\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000iJ\377\377\377\377"
  "}\357\000\000\000\000\000\000\000\000\000\000\353Z\377\377\377\377]\357\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000}\357\377\377\377\377\252R\000\000\000\000\000\000\000\000\000\000\000\000\000\000Y\316\377"
  "\377\377\377\024\245\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\317{\030\306<\347\276"
  "\367\377\377\337\377\236\367\272\326U\255IJ\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000Y\316\377\377\377\377\377\377Mk\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000",
};

