Program is functional
Due to writing of so many pixels, the refresh rate is not good
Main Menu is left right instead of up and down, hope that is ok
Powerup adds 100 more moves
Sometimes, objects pass through frog due to how velocity is used
Controller can sometimes skip if spammed too fast or held down too long, leading to program crash
Platforms display and position may be offset
- Therefore hard to play. Can check code to confirm 4 different stages that are unique (In the initialization function)
- Win screen is displayed at the same code location as lose screen, hard to check win screen functionality since hard to win game
    - TO TEST WIN screen
        - Change "currentStage >= 3 && game.frog.y <= 0" on line 1133 to "currentStage >= 0 && game.frog.y >= 20"  