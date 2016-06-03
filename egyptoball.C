/*------------------------------HEADER FILES--------------------------------*/

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>

/*--------------------------------------------------------------------------*/

/*-----------------------------FUNCTIONS------------------------------------*/

void opening();

void thankyou();

void loading();

int remove_brick();

void bricks_ball_paddle();

void core_logic();

void enter_player();

void cases();

void player_options();

/*--------------------------------------------------------------------------*/
void opening()
{
	int maxx, maxy, midx, midy;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	setbkcolor(BLACK);
	setcolor(GREEN);
	circle(300, 240, 200);
	circle(300, 240, 220);
	setfillstyle(SOLID_FILL, WHITE);
	circle(300, 240, 220);
	settextstyle(TRIPLEX_SCR_FONT, HORIZ_DIR, 10);
	setcolor(BLUE);
	outtextxy(110, 100, "A");
	delay(400);
	outtextxy(200, 100, "A");
	delay(400);
	outtextxy(290, 100, "P");
	delay(400);
	outtextxy(380, 100, "P");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 8);
	delay(500);
	outtextxy(160, 240, "S");
	delay(400);
	outtextxy(205, 240, "P");
	delay(400);
	outtextxy(250, 240, "O");
	delay(400);
	outtextxy(295, 240, "R");
	delay(400);
	outtextxy(340, 240, "T");
	delay(400);
	outtextxy(385, 240, "S");
	delay(400);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setcolor(5);
	outtextxy(210, 350, "P");
	delay(100);
	outtextxy(230, 350, "R");
	delay(100);
	outtextxy(250, 350, "E");
	delay(100);
	outtextxy(270, 350, "S");
	delay(100);
	outtextxy(290, 350, "E");
	delay(100);
	outtextxy(310, 350, "N");
	delay(100);
	outtextxy(330, 350, "T");
	delay(100);
	outtextxy(350, 350, "S");
	delay(5000);
}

void thankyou()
{
	int gd=DETECT, gm, i, k;
	int maxx, maxy, midx, midy;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	setbkcolor(BLACK);
	for(i=0; ; i++)
	{
		setcolor(i);
		rectangle(midx+270, midx-270, midy-200, midy+200);
		rectangle(midx+270-2, midx-270-2, midy-200-2, midy+200-2);
		delay(200);
		settextstyle(SMALL_FONT, HORIZ_DIR, 10);
		outtextxy(160, 120, "T");
		delay(50);
		outtextxy(180, 120, "H");
		delay(50);
		outtextxy(200, 120, "A");
		delay(50);
		outtextxy(220, 120, "N");
		delay(50);
		outtextxy(240, 120, "K");
		delay(50);
		outtextxy(290, 120, "Y");
		delay(50);
		outtextxy(310, 120, "O");
		delay(50);
		outtextxy(330, 120, "U");
		delay(50);
		outtextxy(380, 120, "F");
		delay(50);
		outtextxy(400, 120, "O");
		delay(50);
		outtextxy(420, 120, "R");
		delay(50);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
		outtextxy(230, 200, "P");
		delay(50);
		outtextxy(250, 200, "L");
		delay(50);
		outtextxy(270, 200, "A");
		delay(50);
		outtextxy(290, 200, "Y");
		delay(50);
		outtextxy(310, 200, "I");
		delay(50);
		outtextxy(330, 200, "N");
		delay(50);
		outtextxy(350, 200, "G");
		if(kbhit())
		{
			break;
		}
	}
	k=getch();
	if(k==27)
	{
		exit(0);
	}
	closegraph();

}
void loading()
{
	int i;
	setbkcolor(BLACK);
	setcolor(YELLOW);
	rectangle(240, 324, 386, 310);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	setcolor(WHITE);
	outtextxy(275, 310, "LOADING...");
	delay(1000);
	setfillstyle(SOLID_FILL, MAGENTA);
	for(i=0; i<65; i++)
	{
		bar(241+(i*2), 311, 257+(i*2), 323);
		outtextxy(275, 310, "LOADING...");
		delay(200);
	}
	bar(241, 314, 384, 322);
	bar(241, 322, 384, 322);
	outtextxy(265, 309, "LOAD COMPLETE");
}


int remove_brick ( int b, int l )
{
   setcolor ( BLACK ) ;
   rectangle ( b * 32, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 ) ;
   rectangle ( b * 32+1 , l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 1 );
   rectangle ( b * 32+2 , l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 2 );
   rectangle ( b * 32+3 , l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 3 );
   rectangle ( b * 32+4 , l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 4 );
   rectangle ( b * 32+5 , l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 5 );
   rectangle ( b * 32+6 , l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 6 );
   rectangle ( b * 32+7, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 7 ) ;
   rectangle ( b * 32+8, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 8 ) ;
   rectangle ( b * 32+9, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 9 ) ;
   rectangle ( b * 32+10, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 10) ;
   rectangle ( b * 32+11, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 11) ;
   rectangle ( b * 32+12, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 12) ;
   rectangle ( b * 32+13, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 13) ;
   rectangle ( b * 32+14, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 14) ;
   rectangle ( b * 32+15, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 15) ;
   rectangle ( b * 32+16, l * 10, ( b * 32 ) + 20 , ( l * 10 ) + 7 - 16) ;

}


void bricks_ball_paddle()
{
	int maxx, maxy, midx, midy;
	int i, j, lx=0, ly=0;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	setbkcolor(BLACK);

	setcolor(RED);
	rectangle ( 0, 0, maxx, maxy - 11 );
	setcolor(1+2+3+4);
	for(i=0;i<15; i++)
	{
		for(j=0; j<20; j++)
		{
			rectangle(lx, ly, lx+31, ly+9);
			lx=lx+33;
		}
		lx=0;
		ly=ly+11;
	}
	line(0, maxy-12, maxx, maxy-12);
	getch();
}

void core_logic()
{

   int maxx, maxy, midx, midy;
   int arr[15][20];
   int ball_x_cor, ball_y_cor, base_1, base_2, del_x = 1, del_y = -1, obs_x_cor, obs_y_cor, k ;
   int total_surface[15] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150 }, limit = 150, surface = 14 ;
   int i, flag = 0, velocity = 10, score = 0, life = 4, area_covered ;

   char *ptr1, *ptr2 ;

   int gd=DETECT, gm;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   midx = maxx / 2 ;
   midy = maxy / 2 ;

   bricks_ball_paddle();
   rectangle ( midx - 25, maxy - 7 - 12, midx + 25, maxy - 12 ) ;
   circle ( midx, maxy - 13 - 12, 5 ) ;

   /* memory allocation for storing the image of the paddle */
   area_covered = imagesize ( midx - 12, maxx - 18, midx + 12, maxy - 8 ) ;
   ptr1 =((char*) malloc ( area_covered )) ;

   /* memory allocation for storing the image of the ball */
   area_covered = imagesize ( midx - 25, maxy - 7, midx + 25, maxy - 1 ) ;
   ptr2 =((char *) malloc ( area_covered ) );

   /* image of the paddle and the ball is stored into allocated memory */
   getimage ( midx - 12, maxy - 30, midx + 12, maxy - 20, ptr1);
   getimage ( midx - 25, maxy - 7 - 12, midx + 25, maxy - 1 - 12, ptr2 ) ;

   /* store current position of the paddle and ball */
   base_1 = midx - 25 ;
   base_2 = maxy-19 ;
   ball_x_cor = midx - 12 ;
   ball_y_cor = maxx - 30 ;

   while ( 1 )
   {
      flag = 0 ;

      /* saving current x and y coordinates of the ball */
      obs_x_cor = ball_x_cor ;
      obs_y_cor = ball_y_cor ;

      /* update ballx and bally to move the ball in correct direction */
      ball_x_cor = ball_x_cor + del_x ;
      ball_y_cor = ball_y_cor + del_y ;

      /* according to the position of ball the layer of bricks is determined
*/
      if ( ball_y_cor > 140 )
      {
	 limit = 150 ;
	 surface = 14 ;
      }
      else
      {
	 if ( ball_y_cor > 130 )
	 {
	    limit = 140 ;
	    surface = 13 ;
	 }
	 else
	 {
	    if ( ball_y_cor > 120 )
	    {
	       limit = 130 ;
	       surface = 12 ;
	    }
	    else
	    {
	       if ( ball_y_cor > 110 )
	       {
		  limit = 120 ;
		  surface = 11 ;
	       }
	       else
	       {
			if(ball_y_cor > 100)
			{
				limit = 110;
				surface = 10;
			}
			else
			{
				if(ball_y_cor > 90)
				{
					limit = 100;
					surface = 9;
				}
				else
				{
					if(ball_y_cor > 80)
					{
						limit = 90;
						surface = 8;
					}
					else
					{
						if(ball_y_cor > 70)
						{
							limit = 80;
							surface = 7;
						}
						else
						{
							if(ball_y_cor > 60)
							{
								limit = 70;
								surface = 6;
							}
							else
							{
								if(ball_y_cor > 50)
								{
									limit = 60;
									surface = 5;
								}
								else
								{
									if(ball_y_cor > 40)
									{
										limit = 50;
										surface = 4;
									}
									else
									{
										if(ball_y_cor > 30)
										{
											limit = 40;
											surface = 3;
										}
										else
										{
											if(ball_y_cor > 20)
											{
												limit = 30;
												surface = 2;
											}
											else
											{
												if(ball_y_cor > 10)
												{
													limit = 20;
													surface = 1;
												}
												else
												{
													limit = 10;
													surface = 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
	       }

	}
 }
}
     /* if the ball hits the right boundary, move it to the left */
      if ( ball_x_cor > ( maxx - 25 ) )
      {
	 ball_x_cor = maxx - 25 ;
	 del_x = -del_x ;
      }

      /* if the ball hits the left boundary, move it to the right */
      if ( ball_x_cor < 1 )
      {
	 ball_x_cor = 1 ;
	 del_x = -del_x ;
      }

      /* if the ball hits the top boundary, move it down */
      if ( ball_y_cor < 1 )
      {
	  ball_y_cor = 1 ;
	  del_y = -del_y ;
      }

      /* if the ball is in the area of the bricks */
      if ( ball_y_cor < limit )
      {
	 /* if there is no brick  at the top of the ball */
	 if ( arr[surface][ ( ball_x_cor + 11 ) / 33 ] == 1 )
	 {
	    /*  if the ball touches a brick */
	    for ( i = 1 ; i <= 16 ; i++ )
	    {
	       /* check whether there is a brick to the right of the ball */
	       if ( arr[surface][ ( ball_x_cor + i + 10 ) / 32 ] == 0 )
	       {
		  /* if there is a brick */
		  ball_x_cor = ball_x_cor + i ;
		  flag = 1 ;
		  break ;
	       }

	       /* check whether there is a brick to the left of the ball */
	       if ( arr[surface][ ( ball_x_cor - i + 10 ) / 32 ] == 0 )
	       {
		  ball_x_cor = ball_x_cor - i ;
		  flag = 1 ;
		  break ;
	       }
	    }

	    /* if the ball does not touch a brick at the top, left or right */
	    if ( !flag )
	    {
	       /* check if the ball has moved above the current layer */
	       if ( ball_y_cor < total_surface[surface - 1] )
	       {
		  /* if so, change current layer appropriately */
		  surface-- ;
		  limit = total_surface[surface] ;
	       }

	       /* restore the image of the ball at the old coordinates */
	       putimage ( obs_x_cor, obs_y_cor, ptr1, OR_PUT ) ;

	       /* erase the image at the old coordinates */
	       putimage ( obs_x_cor, obs_y_cor, ptr1, XOR_PUT ) ;

	       /* place the image of the ball at the new coordinates */
	       putimage ( ball_x_cor, ball_y_cor, ptr1, XOR_PUT ) ;

	       /*  delay for fewseconds*/
	       delay ( velocity ) ;

	       /* carry on moving the ball */
	       continue ;
	    }
	 }

	 /* erase the touched brick  */
	 remove_brick ( ( ball_x_cor +10) / 32, surface ) ;

	 /* if the brick hit is on the extreme right */
	 if ( ( ball_x_cor + 10 ) / 32 == 19 )
	    line ( maxx, 0, maxx, 50 ) ;  /* redraw right boundary */

	 /* if the brick hit is on the extreme left */
	 if ( ( ball_x_cor + 10 ) / 32 == 0 )
	    line ( 0, 0, 0, 50 ) ;  /* redraw left boundary */

	 /* if the brick hit is in the topmost layer */
	 if ( surface == 0 )
	    line ( 0, 0, maxx, 0 ) ;  /* redraw top boundary */

	 /* set appropriate array element to 1 to indicate absence of brick */
	 arr[surface][ ( ball_x_cor + 10 ) / 32 ] = 1 ;

	 ball_y_cor = ball_y_cor + 1 ;  /* update the y coordinate */
	 del_y = -del_y ;  /* change the current direction of the ball */
	 score += 10 ;  /* increment the score by 10 */
     }


      /* if  ball reached the bottom */
      if ( ball_y_cor > maxy - 30 )
      {

	 /* if paddle missed the ball */
	 if ( ball_x_cor < base_1 - 20 || ball_x_cor > base_1 + 50 )
	 {
	    /* continue the decrement of the ball */
	    while ( ball_y_cor < maxy-3 )
	    {
	       /* erase the image of the ball at the old coordinates */
	       putimage ( obs_x_cor, obs_y_cor, ptr1, XOR_PUT ) ;

	       /* put the image of the ball at the new coordinates */
	       putimage ( ball_x_cor, ball_y_cor, ptr1, XOR_PUT ) ;

	       /* introduce delay for fewseconds */
	       delay ( 0.0005 ) ;

	       /* saveing current x and y coordinates of the ball */
	       obs_x_cor = ball_x_cor ;
	       obs_y_cor = ball_y_cor ;

	       /* update ballx and bally to move the ball in correct direction */
	       ball_x_cor = ball_x_cor + del_x ;
	       ball_y_cor = ball_y_cor + del_y ;
	    }

	    life-- ;  /* decrement the total number of chances */
	    score -= 10 ;  /* decrement 10 points for each ball lost */

	    /* erase one  of the available balls */
	    if ( life )
	       putimage ( 515 + ( life - 1 ) * 35 - 12 , maxy - 10, ptr1, XOR_PUT );

	    /* if all the balls are lost */
	    if ( !life )
	    {
	       settextstyle(SMALL_FONT, HORIZ_DIR, 10);
	       delay(400);
	       setcolor(RED);
	       outtextxy(220, 185, "GAME OVER");
	       settextstyle(SMALL_FONT, HORIZ_DIR, 4);
	       setcolor(BLUE);
	       outtextxy(250, 265, "PRESS ANY KEY TO EXIT...");
	       getch();
	       thankyou();
	       exit(0);
	    }
	 }

	 /* if ball is collected on paddle */
	 ball_y_cor = maxy - 30 ;  /* restore the y coordinate of ball */
	 del_y = -del_y ;  /* move the ball upwards */
      }

      /* put the image of the ball at the old coordinates */
      putimage ( obs_x_cor, obs_y_cor, ptr1, OR_PUT ) ;

      /* erase the image of the ball at the old coordinates */
      putimage ( obs_x_cor, obs_y_cor, ptr1, XOR_PUT ) ;

      /* put the image of the ball at the upadted coordinates */
      putimage ( ball_x_cor, ball_y_cor, ptr1, XOR_PUT ) ;

      /* if all the bricks have been knockout */
      if ( score == 1500 - ( ( 4 - life ) * 20 ) )
      {
	 outtextxy ( midx, midy, "Winner !!" ) ;

	 if ( score < 1600 )
	    outtextxy ( midx, midy + 30, "Try to score 600" ) ;
	 else
	    outtextxy ( midx, midy + 30, " GREAT!" ) ;

	 closegraph() ;
	 restorecrtmode();
      }

      /* introduce delay for few seconds */
      delay ( velocity ) ;

      /* if the key is pressed to move the paddle */
      if ( kbhit() )
      {
	 k=getch();

	 /* put the image of the paddle at the old coordinates */
	 putimage ( base_1, base_2, ptr2, OR_PUT ) ;

	 /* erase the image of the paddle at the old coordinates */
	 putimage ( base_1, base_2, ptr2, XOR_PUT ) ;

	 /* if Esc key has been pressed */
	 if ( k == 27 )
	    exit ( 0 ) ;

	 /* right arrow key */
	 if ( k == 75 )
	    base_1 = base_1 - 25 ;

	 /* left arrow key */
	 if ( k == 77 )
	    base_1= base_1 + 25 ;

	 /* if paddle goes beyond left boundary */
	 if ( base_1 < 0 )
	    base_1 = 0 ;

	 /* if paddle goes beyond right boundary */
	 if ( base_1 > 589 )
	    base_1 = 589 ;

	 /* put the image of the paddle at the proper position */
	 putimage ( base_1, base_2, ptr2, XOR_PUT ) ;
      }

   }
   closegraph();       /* Return the system to text mode   */
}

void enter_player()
{
	int maxx, maxy, midx, midy, i, k;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	setbkcolor(BLUE);
	setcolor(RED);
	rectangle(midx+270, midx-270, midy-200, midy+200);
	rectangle(midx+270-2, midx-270-2, midy-200-2, midy+200-2);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 4);
	outtextxy(80, 80, "ENTER PLAYER NAME......");
	setcolor(WHITE);
	rectangle(80, 140, 160, 160);
	settextstyle(SMALL_FONT, HORIZ_DIR, 2);
	outtextxy(165, 145, "ONLY FOUR CHARACTERS...");
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	ellipse(100, 400, 0, 360, 50, 25);
	ellipse(102, 402, 0, 360, 52, 27);
       //ellipse(320, 400, 0, 360, 50, 25);
       //ellipse(322, 402, 0, 360, 52, 27);
	ellipse(525, 400, 0, 360, 50, 25);
	ellipse(527, 402, 0, 360, 52, 27);
	outtextxy(64, 380, "SUBMIT");
	//outtextxy(294, 380, "BACK");
	outtextxy(505, 380, "EXIT");

}

void player_options()
{
	int maxx, maxy, midx, midy, i;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;
	setbkcolor(BLUE);
	setcolor(WHITE);
	rectangle(midx+270, midx-270, midy-200, midy+200);
	rectangle(midx+270-2, midx-270-2, midy-200-2, midy+200-2);
	setcolor(GREEN);
	settextstyle(TRIPLEX_SCR_FONT, HORIZ_DIR, 3);
	outtextxy(60, 80, "--------CHOOSE YOUR OPTIONS--------");
	setcolor(BLACK+RED+GREEN);
	rectangle(60, 120, 350, 420);
	outtextxy(80, 140, "1.");
	outtextxy(80, 210, "2.");
	outtextxy(80, 280, "3.");
	outtextxy(80, 350, "4.");
	setcolor(BLACK+RED+GREEN);
	ellipse(220, 160, 0, 360, 70, 25);
	ellipse(222, 162, 0, 360, 70, 25);
	ellipse(220, 230, 0, 360, 70, 25);
	ellipse(222, 232, 0, 360, 70, 25);
	ellipse(220, 300, 0, 360, 70, 25);
	ellipse(222, 302, 0, 360, 70, 25);
	ellipse(220, 370, 0, 360, 70, 25);
	ellipse(222, 372, 0, 360, 70, 25);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	setcolor(BLACK+WHITE+YELLOW+RED+GREEN);
	outtextxy(195, 145, "START");
	outtextxy(195, 215, "LOAD");
	outtextxy(160, 290, "INSTRUCTIONS");
	outtextxy(185, 355, "CREDITS");
	setcolor(RED);
	circle(530, 390, 30);
	circle(532, 392, 30);
	outtextxy(515, 380, "EXIT");
	settextstyle(GOTHIC_FONT, VERT_DIR, 5);
	for(i=0; ;i++)
	{
		setcolor(i);
		outtextxy(415, 120, "EGYPTOBALL");
		delay(500);
		if(kbhit())
		{
			break;
		}
	}
}
void cases()
{
	int maxx, maxy, midx, midy, ch;
	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=maxy/2;

	setbkcolor(BLUE);
	setcolor(WHITE);
	ch=getch();
	if(ch=='1')
		core_logic();


	if(ch=='2')
		outtextxy(midx, midy, "UNDER CONSTRUCTION");

	if(ch=='3')
		{
			rectangle(midx+270, midx-270, midy-200, midy+200);
			rectangle(midx+270-2, midx-270-2, midy-200-2, midy+200-2);
			setcolor(GREEN);
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 3);
			outtextxy(190, 60, "INSTRUCTIONS......");
			outtextxy(180, 60, "______________");
			settextstyle(SMALL_FONT, HORIZ_DIR, 6);
			outtextxy(60, 120, "1. USE RIGHT ARROW KEY TO MOVE THE PADDLE RIGHT.");
			delay(400);
			outtextxy(60, 140, "2. USE LEFT ARROW KEY TO MOVE THE PADDLE LEFT.");
			delay(400);
			outtextxy(60, 160, "3. USE SPACE TO MAKE THE BALL MOVE.");
			delay(400);
			outtextxy(60, 180, "4. YOU CAN ALSO USE MOUSE TO MOVE THE PADDLE LEFT");
			outtextxy(60, 200, "   AND RIGHT.");
			delay(400);
			outtextxy(60, 220, "5. USE LEFT CLICK TO MAKE THE BALL MOVE.");
			delay(400);
			rectangle(80, 350, 180, 400);
			rectangle(82, 352, 182, 402);
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
			setcolor(RED);
			outtextxy(100, 360, "BACK");
		}

		if(ch=='4')
		{
			rectangle(midx+270, midx-270, midy-200, midy+200);
			rectangle(midx+270-2, midx-270-2, midy-200-2, midy+200-2);
			setcolor(GREEN);
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 4);
			outtextxy(247, 60, "CREDITS......");
			outtextxy(220, 60, "__________");
			settextstyle(TRIPLEX_SCR_FONT, HORIZ_DIR, 3);
			outtextxy(120, 140, "1. ARNISH SAHAI");
			delay(1000);
			outtextxy(120, 180, "2. AKSHIT KAUSHIK");
			delay(1000);
			outtextxy(120, 220, "3. PRATEEK DUTTA");
			delay(1000);
			outtextxy(120, 260, "4. PRIYANSHU SINHA");
			delay(500);
			rectangle(80, 350, 180, 400);
			rectangle(82, 352, 182, 402);
			settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
			setcolor(RED);
			outtextxy(100, 360, "BACK");
		}
}
void main()
{
	int gd=DETECT, gm, x=58, y=20, font=4, i, k, l, m, n, str[5];
	initgraph(&gd, &gm, "c:\\TC\\BGI");
	opening();
	cleardevice();
	setbkcolor(BLACK);
	setcolor(RED);																																  settextstyle(font, HORIZ_DIR, 8);
	outtextxy(x, y, "EGYPTOBALL");
	delay(3000);
	loading();
	delay(1000);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	for(i=5; ;i=i+9)
	{
		setcolor(i);
		outtextxy(255, 395, "PRESS ANY KEY");
		delay(500);
		if(kbhit())
		{
			break;
		}
	}
	getch();
	cleardevice();
	enter_player();
	l=getch();
	if(l==27)
	{
		exit(0);
	}

	m=12;
	n=10;

	gotoxy(m, n);
	scanf("%s", str);
	l=getch();
	if(l==13)
	{
		cleardevice();
		player_options();
	}
	if(l==27)
	{
		exit(0);
	}
	cleardevice();
	cases();
	k=getch();
	if(k==8)
	{
		cleardevice();
		player_options();
		cleardevice();
		cases();
		k=getch();
		if(k==8)
		{
			cleardevice();
			player_options();
			cleardevice();
			cases();
		}
		k=getch();
		if(k==8)
		{
			cleardevice();
			player_options();
			cleardevice();
			cases();
		}
		k=getch();
		if(k==8)
		{
			cleardevice();
			player_options();
			cleardevice();
			cases();
		}
		k=getch();
		if(k==27)
		{
			exit(0);
		}
	}
	closegraph();
}
