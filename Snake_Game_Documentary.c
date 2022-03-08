               .....Documentary for the Snake game.....

  * Here is functions working is explained below.
   -The whole snake game can be divide into some functions(parts) they are:

    1.Instructions(): 
       *In this method, to gave the instructions for operate the snake that is
         -Use arrow keys to move the snake (left, right, up, down).
         -Food is randomly generated with in the game space, snake wants to eat food, if snake eat food then the score will be incresed by 2 or 5.
         -After ate the food the length of the snake will be increase every time
         -If snake hits the edges, or hits snake body itself then the number of lives will be reduced by 1.
        -If all lives are completed then game will terminated.
 
    2.Loading():
        *This method to load the snake game, that means to print the 177 ASCII
           Character slowly.
          Pseudo code:
                 for(int i=0;i<20;i++)
                 {
                        for(int j=0;j<10000000;j++);
                            printf("%c",177);
                  }  
  
    3.Speed_level():
        *This method can control the snake speed and we can set the speed 
           of the snake by using the Delay method(Delay function is explained in below)
         - There are three speed levels (1, 2, 3).
         -If we select the '1' then snake will move normal speed.
         -else if we select the '2' then snake will move faster than normal speed.
         -else we select the '3' then snake will more faster.
         
    4.Edges():
       *This method for the display the Boarder.
         -which means the snake can move the within the boarder.
         -If the snake the touches the edges then snake life can be reduced
          by using the method Exitgame(Which is expalined in below)

    5.Food():
       *This method can be provide the food in random palces every time
           - By using the random() function, we are able to generate food in defferent places with in the border. 
           -and also score can increase by using the Score() mentod(explained below) 

    6.Console_change():
        * This method can be change cursore one place to another place.
          - By considering the co-ordinates (x,y) of the compiler (display), we can change the cursor.
          -This method is very important, This function is used through out 
            the program.

    7.Right():
         *This method can be used for the snake move right side
         - If the user clik the right arrow then right() method will invoked and the snake head will point towards right side.

    8.Left():
         *This method can be used for the snake move left side
         -If the user clik the left arrow then left() method will invoked and the snake head will point towards left side.

    9.Up():
         *This method can be used for the snake move to the top
         -If the user clik the up arrow then up() method will invoked and the snake head will point towards up side.

  10.Down():
         *This method can be used for the snake move to th bottom
         -If the user clik the down arrow then down() method will invoked and the snake head will point towards down side.

  11.Bend():
       *This method can indicate the snake direction
          -and the snake direction  change and to move forward by using
            Move method(explained in below)

  12.Move(): 
        *This method can used to call the method Right(), Left(), Up(), Down()
          -And the snake can be change that direction and move

  13.Delay():
        *This method can be Delay the snake that means snake can move slowly.
           pseudo code:
                   for(int i=0;i<100000000;i++); 

  14.Score():
       *This method can display the score and the numer of lives
         -If the snake ate the food then Score can be increse by 2 or 5.
         -If the snake hits the boarder then snake life can reduce by 1 (by using Exitgame method), initially snake has three lifes.
         - Remaining lives can be displayed by using score() method.
 
  15.Exitgame():
        *This method used to exit the game
           -If the snake lives completed then the game will terminate.
  
