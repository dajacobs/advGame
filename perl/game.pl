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