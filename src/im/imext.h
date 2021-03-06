

#ifndef __AX_CORE_IM_EXT_H__
#define __AX_CORE_IM_EXT_H__


#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#if	defined(__cplusplus)
extern "C" {
#endif

enum{
	BRINK_AND_PENDOCK = 0,
	LI_AND_LEE	
};	

struct _imImage;

int median( int a[], int size, bool sort_array = true );

float medianf( float a[], int size, bool sort_array = true );

int max_val( int a[], int size , int *pos = NULL);

int sum( int a[], int size );

int count( int a[], int size );

void corr( int a[], int b[], int size, int win, int *dec, int *max);

//*****
    
double** alloc2DArray( int x, int y );
    
void free2DArray( double **array, int x );

void imSetData( _imImage *image, _imImage *selection, int pos_x, int pos_y );

bool imProcessSafeCrop( _imImage *image, int *width, int *height, int *pos_x, int *pos_y );

void imAnalyzeRuns(const _imImage* image, int *peak_val, int *median_val, int type = 0, bool vertical = true);

void imAnalyzeProjectionH(const _imImage* image, int* hist);

void imAnalyzeProjectionV(const _imImage* image, int* hist);

void imAnalyzeMeasureMeanHeight(const _imImage* image, int* data_area, int region_count );

void imAnalyzeClearHeight(const _imImage* image, int region_count, int min_threshold, int max_threshold );

void imAnalyzeBoundingBoxes(const _imImage* image, int* boxes, int region_count );

void imAnalyzeClearWidth(const _imImage* image, int region_count, int min_threshold, int max_threshold );

void imAnalyzeClearMin(const _imImage* image, int region_count, int threshold );

int imProcessKittlerThreshold(const _imImage* image, _imImage* NewImage);

int imProcessSauvolaThreshold( const _imImage* src, _imImage* dest,	int region_size,
	float sensitivity = 0.5, int dynamic_range = 128, int lower_bound = 20, int upper_bound = 150, bool white_is_255 = true );
	
int imProcessPuginThreshold( const _imImage* src, _imImage* dest, bool white_is_255 = true );

// implementation in im_brink.cpp
int imProcessBrinkThreshold( const _imImage* src, _imImage* dest, bool white_is_255 = true );

// implemented in imbrink3classes.cpp
int imProcessBrink2ClassesThreshold( const _imImage* image,_imImage* dest, bool white_is_255, int algorithm );	
int imProcessBrink3ClassesThreshold( const _imImage* image,_imImage* dest, bool white_is_255, int algorithm );		
	
void imPhotogrammetric( const _imImage* image,_imImage* dest );
	
void imSaveValues( int *values, int count, const char *filename );

void imPrintValues( int *values, int count );

//void DistByCorrelation( _imImage *im1, _imImage *im2, int width, int height, int *decalageX, int *decalageY);

#if defined(__cplusplus)
}
#endif


#endif // __AX_CORE_IM_EXT_H__
