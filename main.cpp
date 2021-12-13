#include "mainwindow.h"
#include "scorekeeper.h"
#include "testjudge.h"

#include <QApplication>

#include <SDL2/SDL.h>

// Haven't tested this since I don't have a joystick. Looks like you can use uinput pretty easily to do this.
// https://www.kernel.org/doc/html/v4.12/input/uinput.html
void gosdl()
{
    SDL_Joystick *joy;

    // Initialize the joystick subsystem
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    // Check for joystick
    if (SDL_NumJoysticks() > 0) {
        // Open joystick
        joy = SDL_JoystickOpen(0);

        if (joy) {
            printf("Opened Joystick 0\n");
            printf("Name: %s\n", SDL_JoystickNameForIndex(0));
            printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
            printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
            printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
        } else {
            printf("Couldn't open Joystick 0\n");
        }

        // Close if opened
        if (SDL_JoystickGetAttached(joy)) {
            SDL_JoystickClose(joy);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("mrmcgibby");
    QCoreApplication::setOrganizationDomain("mrmcgibby.duckdns.org");
    QCoreApplication::setApplicationName("TKD Score");

    ScoreKeeper sk;
    sk.addJudge(new TestJudge());
    sk.addJudge(new TestJudge());
    sk.addJudge(new TestJudge());

    MainWindow w;

    QObject::connect(&sk, &ScoreKeeper::scoreChanged,
                     &w, &MainWindow::setPoints);

    w.show();

    return a.exec();
}
