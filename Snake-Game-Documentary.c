               .....Documentary for the Snake game.....

  * IN snake game, how  the methods are working is...
   -The whole snake game can be divide into some parts(methods) they are:

    1.Instructions(): 
       *In this method, to gave the instructions for operate the snake that is
         -Use arrow keys to move the snake
         -We provide the food in different places, You must be eat the food
         -After ate the food the length of the snake will be increase every time
         -If you hit the edges of the box or hit your own body you will be dead
        -You have two lives, after completing the lives snake will be dead
 
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
           of the snake by using the Delay method(Delay is explained in below)
         - There are three speed level (1, 2, 3).
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
           - snake can ate the food every time then this function can regenerate
             the food 
           -and also score can increase by using the Score mentod(explained below) 

    6.Console_change():
        * This method can be change cursore
          -This method is very important, it is used every method through out 
            the program

    7.Right():
         *This method can be used for the snake move right side

    8.Left():
         *This method can be used for the snake move left side

    9.Up():
         *This method can be used for the snake move to the top

  10.Down():
         *This method can be used for the snake move to th bottom

  11.Bend():
       *This method can indicate the snake direction
          -and the snake direction  change and to move forward by using
            Move method(explained in below)

  12.Move(): 
        *This method can used to call the method Right(), Left(), Up(), Down()
          -And the snake can be change that direction and move

  13.Delay():
        *This method can be Delay the snake that means snake can move slowly
           pseudo code:
                   for(int i=0;i<100000000;i++); 

  14.Score():
       *This method can display the score and the numer of lives
         -If the snake can ate the food then Score can be increse
         -If the snake can hit the boarder then snake life can reduce(Exitgame method).
         - Remaining lives can display in this method
 
  15.Exitgame():
        *This method used to exit the game
           -If the snake lives completed then exit the game
  