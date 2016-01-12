/*
	Text descriptions of all the palces in the game.
*/
description(valley, 
	'You are in a pleasant valley, with a trail ahead.').
description(path, 
	'You are on a path, with ravines on both sides.').
description(cliff,
	'You are teetering on the edge of a cliff.').
description(fork,
	'You are at a fork in the path.').
description(maze(_),
	'You are in a maze of twisty trails, all alike.').
description(mountaintop,
	'You are on the mountaintop.').
description(labyrinth(_),
	'You are lost in a winding corridor.').
/*
	Prints description of current location in maze.
*/
report :-
	at(you,X),
	description(X,Y),
	write(Y), nl.

connect(valley,forward,path).
connect(path,right,cliff).
connect(path,left,cliff).
connect(path,forward,fork).
connect(mountaintop,left,fork).
connect(maze(0),left,maze(1)).
connect(maze(0),right,maze(3)).
connect(maze(1),left,maze(0)).
connect(maze(1),right,maze(2)).
connect(maze(2),forward,maze(4)).
connect(maze(2),left,fork).
connect(maze(2),right,maze(0)).
connect(maze(3),left,maze(0)).
connect(maze(3),right,maze(3)).
connect(maze(4),forward,mountaintop).
connect(maze(4),right,maze(4)).
connect(labyrinth(0),left,labyrinth(1)).
connect(labyrinth(0),right,labyrinth(15)).
connect(labyrinth(1),left,labyrinth(2)).
connect(labyrinth(1),right,labyrinth(10)).
connect(labyrinth(2),left,labyrinth(3)).
connect(labyrinth(2),right,labyrinth(9)).
connect(labyrinth(3),right,labyrinth(4)).
connect(labyrinth(4),left,labyrinth(5)).
connect(labyrinth(4),right,labyrinth(9)).
connect(labyrinth(5),left,labyrinth(6)).
connect(labyrinth(5),right,labyrinth(8)).
connect(labyrinth(6),right,labyrinth(7)).
connect(labyrinth(7),left,labyrinth(8)).
connect(labyrinth(7),right,labyrinth(12)).
connect(labyrinth(8),left,labyrinth(7)).
connect(labyrinth(8),right,labyrinth(9)).
connect(labyrinth(9),left,labyrinth(10)).
connect(labyrinth(9),right,labyrinth(8)).
connect(labyrinth(10),left,labyrinth(9)).
connect(labyrinth(10),right,labyrinth(11)).
connect(labyrinth(11),left,labyrinth(12)).
connect(labyrinth(11),right,labyrinth(10)).


/*
	Moves you in accordance with direction(Dir), then
	prints the description of the new location moved to.
*/
move(Dir) :-
	at(you,Loc),
	connect(Loc,Dir,Next),
	retract(at(you,Loc)),
	assert(at(you,Next)),
	report,
	!.	
/*
	Prints an error message to the user if an illegal move
	is performed and does not move, staying put in current
	location.
*/	
move(_) :-
	write('That is not a legal move.\n\n'),
	report.
/*
	Shorthand for moves.
*/
forward :- move(forward).
left :- move(left).
right :- move(right).	
/*
	When Ogre and current location equal, then it kills you.
*/
ogre :- 
	at(ogre,Loc),
	at(you,Loc),
	write('An ogre sucks your brain out through\n'),
	write('your eye sockets, and you die.\n'),
	retract(at(you,Loc)),
	assert(at(you,done)),
	!.
/*
	When Ogre and currention location are not equal,
	then nothing happens.
*/
ogre.	
/*
	When Treasure and current location equal, then
	you win the game.
*/
treasure :-
	at(treasure,Loc),
	at(you,Loc),
	write('There is a treasure here.\n'),
	write('Congratulations, you win!\n'),
	retract(at(you,Loc)),
	assert(at(you,done)),
	!.
/*
	When Treasure and current location are not equal,
	then nothing happens.	 
*/
treasure.
/*
  	When cliff and current location equal, then 
  	you fall off and die.
*/
cliff :-
  at(you,cliff),
  write('You fall off and die.\n'),
  retract(at(you,cliff)),
  assert(at(you,done)),
  !.
/*
	But if you are not at the cliff nothing happens.
*/
cliff.	