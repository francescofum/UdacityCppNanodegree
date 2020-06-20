#include "ncurses_display.h"
#include "system.h"
#include "helpers.h"

int main() {
  System system;
  NCursesDisplay::Display(system);
}