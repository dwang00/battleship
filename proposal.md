# battleship

David Wang

This project is a recreation of the board game battleship on the command line. The goal is to use text to simulate 2 boards, one with your ships visible and the other being the computer's, ships invisible. Hits will be tracked by revealing the cell that was a hit, and misses will be represented by "o"s.

ex:<pre>       your board                 enemy board </pre>
<pre>    0 1 2 3 4 5 6 7 8 9         0 1 2 3 4 5 6 7 8 9  
  0 - - * * * * * - - -       0 - - - - - - - - - -  
  1 - - * * * - - - - -       1 - - - - - - - - - -  
  2 - - * * - - - - - -       2 - - - - - - - - - -  
  3 - - * * * * - - - -       3 - - - - - - - - - -  
  4 - - * * * - - - - -       4 - - - - - - - - - -  
  5 - - - - - - - - - -       5 - - - - - - - - - -  
  6 - - - - - - - - - -       6 - - - - - - - - - -  
  7 - - - - - - - - - -       7 - - - - - - - - - -  
  8 - - - - - - - - - -       8 - - - - - - - - - -  
  9 - - - - - - - - - -       9 - - - - - - - - - -  </pre>

I plan to represent the boards with files and edit the files as the game state changes. I plan to store board info in 2 double arrays, so I would have to allocate memory to both. The program would cat the files in order to display the boards. I will use signals to separate turns.

1/5 - get boards to display properly  
1/9 - be able to arrange ships  
1/13 - finish computer ai  
1/17 - be able to play a game of battleship  
