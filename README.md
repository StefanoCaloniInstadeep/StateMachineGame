# StateMachineGame

A small example of how to handle user inputs in games by using a finite state machine.

The evolution of branches:
- `start` the intial game (moving and jumping)
- `ducking` adding the ability to duck
- `diving` adding the ability to dive while jumping
- `enum` first finite state machine implementation using enums
- `state` equivalent but using a State object
- `state2` further evolution of the idea above
- `bird` how to experiment a completely new State without affecting the previous implementation

Credits:
- State pattern explanation by https://gameprogrammingpatterns.com/state.html
- The toy example inspired by https://www.raylib.com/examples.html
