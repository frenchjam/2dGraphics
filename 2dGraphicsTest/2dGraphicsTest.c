/***************************************************************************/
/*                                                                         */
/*                             2dGraphicsTest.c                            */
/*                                                                         */
/***************************************************************************/

/* (c) Copyright 1994, 1995, 2006 - PsyPhy Consulting. All Rights Reserved.*/

/*
 *	Test the 2D Graphics Views and Displays systems.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <useful.h>

#include <Views.h>
#include <Layouts.h>

#include <2dMatrix.h>
#include <Regression.h>

#include "ogldisplayinterface.h"

// #include <PictDisplay.h>

Display display; 
Layout  layout;
View	view1, view2;

local double	x[] = {.2, .3, .4, .1, .7, .9, .5};
local double	y[] = {.1, .4, .7, .3, .9, .5, .6};

local double ellipse[2][2] = { { 4.0, 0.0 }, { 0.0, 1.0 }};
local double scale = 1.0;
local double center[2] = { 0.25, 0.4 };

local double p[3] = { 0.2, 0.0, 1.0 };

local double ramp( void *ptr, double angle ) {

  while ( angle < - PI ) angle += 2.0 * PI;
  while ( angle > PI ) angle -= 2.0 * PI;
  return( angle / PI );

}

void main ( int argc, char *argv[] ) {

  float r;

  char    *string = "TESTTESTTESTTESTTestTestTest\nTestT\ne\ns\nt";

#ifdef MACINTOSH
  argc = ccommand( &argv );
#endif

  display = DefaultDisplay();
  // display = HardcopyDisplay;

//  SgiReadMaps( display, "tst.map" );
//  DisplaySetSizeInches( display, 4.0, 4.0 );
  DisplayInit( display );
  Erase( display );


  Color( display, GREEN );
  glprintf( 300, 300, 12.0, "TESTAGAIN" );
//  DisplayLabel( display, "TESTAGAIN", 600, 600, 0, LEFT_JUSTIFY, TOP_JUSTIFY );

    Swap();
    Sleep( 1000 );

  Color( display, RED );
  for ( r = 100; r < 500; r += 100 ) FilledCircle( display, r, r, 30.0 );

#if 0
	layout = CreateLayout( display, 2, 2 );
	LayoutSetDisplayEdgesRelative( layout, 0.250, 0.250, 0.75, 0.75 );

	view1 = LayoutView( layout, 0, 0 );
	view2 = LayoutView( layout, 1, 1 );


	ViewMakeSquare(view1);
	
	ViewDescribe(view1);
	ViewDescribe(view2);
  
  ViewColor( view1, RED );	
  ViewXYPlotDoubles(view1, x, y, 0, 6, 1, sizeof(*x), sizeof(*y));

  ViewPlotSpectrumCircle( view1, 0, 0, 1.0, ramp, NULL );


  ViewColor( view1, GREY4 );	
	ViewBox( view1 );
	ViewAxes( view1 );

	ViewPlotPolynomial( view1, p, 2 );

  ViewColor( view1, RED );	
  for ( xx = -1.0; xx < 1.0; xx += 0.25 ) ViewSymbol( view1, xx, xx, SYMBOL_FILLED_CIRCLE );

  /*
  ViewColor( view1, RED );	
  ViewFilledRectangle( view1, 0.0, 0.0, -1.0, -1.0 );
	ViewColor( view1, YELLOW );	
  ViewFilledCircle( view1, 0.0, 0.0, 0.3 );
  ViewCircle( view1, 1.0, 0.0, 0.3 );
  */

  
	ViewStartPolygon(view1);
	ViewAddVertex( view1, -0.1 , -0.2 );
	ViewAddVertex( view1, -0.5 , -0.25 );
	ViewAddVertex( view1, -0.41 , -0.72 );
	ViewAddVertex( view1, -0.31 , -0.32 );
	ViewColor( view1, BLUE );
	ViewOutlinePolygon( view1 );
	ViewFillPolygon( view1 );
	



  ViewColor( view1, 1 );
	ViewArrow( view1, 0.0, 0.0, 2.0, 0.0 );

	ViewColor( view1, 2 );
	ViewArrow( view1, 0.0, 0.0, 2.0, 1.0 );

	ViewColor( view1, 3 );
	ViewArrow( view1, 0.0, 0.0, 2.0, 2.0 );


	ViewColor( view1, 1 );
//	SgiSelectFont( "Helvetica", 16 );
	ViewLabel(view1, "Test", 0.0, 0.0, 0.0, LEFT_JUSTIFY, BOTTOM_JUSTIFY);



  Color( display, RED );
  DisplayBox( display );
  Color( display, MAGENTA );

  Color( display, CYAN );
  Line(display, display->left, display->bottom, display->right, display->top);
  Line(display, display->left, display->top, display->right, display->bottom);	

  Color( display, MAGENTA );
  LayoutBox( layout );
  LayoutDescribe( layout );
  LayoutTitle( layout, "Layout", INSIDE_LEFT, OUTSIDE_TOP, 0 );

  ViewColor(view1, BLACK);

  ViewColor(view1, BLACK);
//  ViewLine(view1, 0.0, 0.5, 0.5, 0.5);


  ViewColor(view1, RED);	
  ViewPoint( view1, -.5, .5 );
  ViewColor(view1, GREEN);
	
/*
  ViewStartPolygon(view1);
  ViewAddVertex( view1, -0.1 , -0.2 );
  ViewAddVertex( view1, -0.5 , -0.25 );
  ViewAddVertex( view1, -0.41 , -0.72 );
  ViewAddVertex( view1, -0.31 , -0.32 );
  ViewColor( view1, BLUE );
  ViewFillPolygon( view1 );
  ViewColor( view1, RED );
  ViewOutlinePolygon( view1 );
*/


  ViewErase(view2);
  ViewColor(view2, BLUE);	
  ViewBox(view2);
  ViewText(view1, "LeftBottom@0.5,0.5", .5, .5, 0.0);
  ViewLabel(view1, "RightTop@-0.5,0.5", -.5, .5, 0.0, RIGHT_JUSTIFY, TOP_JUSTIFY);
  ViewTitle(view1, "LeftTop", INSIDE_LEFT, INSIDE_TOP, 0.0 );
  ViewTitle(view2, "RightTop", INSIDE_RIGHT, INSIDE_TOP, 0.0 );
  ViewText(view2, "VIEW2+", .5, .5, 0.0);
  DisplayTitle(display, "Display", INSIDE_LEFT, INSIDE_BOTTOM, 0.0); 
  DisplayTitle(display, string, INSIDE_RIGHT, INSIDE_TOP, 0.0); 
  DisplayTitle(display, "TestTestTest", INSIDE_RIGHT, INSIDE_BOTTOM, 0.0); 
  DisplayTitle(display, string, INSIDE_LEFT, INSIDE_TOP, 0.0); 

  while ( DisplayInput( display, &click_x, &click_y ) ) {
    fprintf( stderr, "Click: %d %d\n", click_x, click_y );

    fprintf( stderr, "View 1: %s\n", 
			 ViewDisplayPointInside( view1, click_x, click_y ) ? "YES" : "NO" );
    fprintf( stderr, "View 2: %s\n", 
			 ViewDisplayPointInside( view2, click_x, click_y ) ? "YES" : "NO" );

  }
#endif

//  OglDisplayRedraw( display );

  Close( display );

  

}

