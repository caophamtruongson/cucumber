#ifndef GHERKIN_UNICODE_UTILITIES_H_
#define GHERKIN_UNICODE_UTILITIES_H_

#include <wchar.h>

#include "utf8_source.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Utf16Surrogates {
    wchar_t leading;
    wchar_t trailing;
} Utf16Surrogates;

long UnicodeUtilities_read_code_point_from_utf8_source(Utf8Source* utf8_source);

Utf16Surrogates UnicodeUtilities_get_utf16_surrogates(long code_point);

#ifdef __cplusplus
}
#endif

#endif /* GHERKIN_UNICODE_UTILITIES_H_ */
