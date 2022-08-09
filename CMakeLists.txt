#
# wxEncodingDetection static library
#

SET(ENCODING_DETECTION_PUBLIC_HEADER_FILES
	inc/wxEncodingDetection/wxEncodingDetection.h
	inc/wxEncodingDetection/wxNoConv.h
	inc/wxEncodingDetection/wxTextInputStreamOnString.h
	inc/wxEncodingDetection/wxTextOutputStreamOnString.h
	inc/wxEncodingDetection/wxTextOutputStreamWithBOM.h
	inc/wxEncodingDetection/wxTextStreamUtils.h
)
SET(ENCODING_DETECTION_HEADER_FILES src/StdWx.h)
SET(ENCODING_DETECTION_SOURCE_FILES
	src/wxEncodingDetection.cpp
	src/wxMLangConvertCharset.cpp
	src/wxMultiLanguage.cpp
	src/wxTextInputStreamOnString.cpp
	src/wxTextOutputStreamOnString.cpp
	src/wxTextOutputStreamWithBOM.cpp
	src/wxTextStreamUtils.cpp
	src/wxMBConvUnaccent.hpp
)

ADD_LIBRARY(wxEncodingDetection STATIC
	${ENCODING_DETECTION_SOURCE_FILES}
	${ENCODING_DETECTION_HEADER_FILES}
	${ENCODING_DETECTION_PUBLIC_HEADER_FILES}
)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/inc)
TARGET_INCLUDE_DIRECTORIES(wxEncodingDetection INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
TARGET_PRECOMPILE_HEADERS(wxEncodingDetection PRIVATE src/StdWx.h)

ConfigureWxWidgetsUsage(wxEncodingDetection)
ConfigureSourceEncoding(wxEncodingDetection)
SET_PROPERTY(TARGET wxEncodingDetection PROPERTY OUTPUT_NAME EncodingDetection)
TARGET_LINK_LIBRARIES(wxEncodingDetection PUBLIC "$<$<CXX_COMPILER_ID:GNU>:mlang>" )
IF(MINGW)
	SET_SOURCE_FILES_PROPERTIES(src/wxEncodingDetection.cpp src/wxTextOutputStreamWithBOM.cpp PROPERTIES COMPILE_OPTIONS -fpermissive)
ENDIF()

SET_PROPERTY(TARGET wxEncodingDetection PROPERTY FOLDER tool)
