#include "unicode_utilities.h"

long UnicodeUtilities_read_code_point_from_utf8_source(Utf8Source* utf8_source) {
    unsigned char c = Utf8Source_read(utf8_source);
    if (c < 0x80) {
        return (long)c;
    }
    unsigned char c2 = Utf8Source_read(utf8_source);
    long lower_part = (long)(c2 & 0x3F);
    if ((c & 0xE0) == 0xC0) {
        return (((long)(c & 0x1F)) << 6) | lower_part;
    }
    c2 = Utf8Source_read(utf8_source);
    lower_part =  (lower_part << 6) | (long)(c2 & 0x3F);
    if ((c & 0xF0) == 0xE0) {
        return (((long)(c & 0x0F)) << 12) | lower_part;
    }
    c2 = Utf8Source_read(utf8_source);
    lower_part =  (lower_part << 6) | (long)(c2 & 0x3F);
    if ((c & 0xF8) == 0xF0) {
        return (((long)(c & 0x07)) << 18) | lower_part;
    }
    c2 = Utf8Source_read(utf8_source);
    lower_part =  (lower_part << 6) | (long)(c2 & 0x3F);
    if ((c & 0xFC) == 0xF8) {
        return (((long)(c & 0x03)) << 24) | lower_part;
    }
    c2 = Utf8Source_read(utf8_source);
    lower_part =  (lower_part << 6) | (long)(c2 & 0x3F);
    if ((c & 0xFE) == 0xFC) {
        return (((long)(c & 0x01)) << 30) | lower_part;
    }
    return WEOF;
}

Utf16Surrogates UnicodeUtilities_get_utf16_surrogates(long code_point){
    Utf16Surrogates surrogates;
    long surrogates_base = code_point - 0x10000;
    surrogates.leading = 0xD800 + (surrogates_base >> 10);
    surrogates.trailing = 0xDC00 + (surrogates_base & 0x3FF);
    return surrogates;
}
