#include "vex.h"
using namespace std;
using namespace vex;

double calculate_text_width(string text) {
  // Adjust character width based on font size
  return text.length() * 9.0;
}
 
void draw_button(double x, double y, double width, double height, double tx, double ty, string text) {
  Brain.Screen.setFont(fontType::mono15);
  Brain.Screen.drawRectangle(x, y, width, height);
  Brain.Screen.printAt(tx, ty, text.c_str());
}
 
// & reference to an existing object, allowing changes to affect the original object
void confirm_button(const Measurements& cb, const vex::color color, string text, const vex:: color penColor) {
  Brain.Screen.setFillColor(color);
  Brain.Screen.setPenColor(penColor);
  Brain.Screen.setFont(fontType::mono30);
  Brain.Screen.drawRectangle(cb.confirmX, cb.confirmY, cb.buttonWidth, cb.buttonHeight);
  double textWidth = calculate_text_width(text);
  double adjustedTx = cb.confirmTx - textWidth / 2.0;
  double textHeight = 1.05;
  double adjustedTy = cb.confirmTy * textHeight;
  Brain.Screen.printAt(adjustedTx, adjustedTy, text.c_str());
}
 
void button_grid(const Measurements& bt) {
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.setPenColor(black);
  Brain.Screen.setFont(fontType::mono30);
  int counter = 0;
  // Text list of auton routes
  string autonLabel[6] = {"Inertial_test", "short_drive", "leftSwing", "rightSwing", "fullSwing", "Path"};
  // Iterate over rows
  for (int row = 0; row < bt.numRows; ++row) {
      // Iterate over columns
      for (int col = 0; col < bt.numCols; ++col) {
          double x = bt.gridX + col * (bt.width + bt.colSpacing);
          double y = bt.gridY + row * (bt.height + bt.rowSpacing);
          // Center x-pos
          double tx = x + bt.width / 2;
          double textHeight = 1.1;
          // Center y-pos
          double ty = (y + bt.height / 2) * textHeight;
          // // Generate a label based on the current row and column
          // stringstream ssCounter;
          // ssCounter << counter;
          // string counterString = ssCounter.str();
          // string label = "R" + counterString;
          double textWidth = calculate_text_width(autonLabel[counter]);
          double adjustedTx = tx - textWidth / 2.0;
          // Draw the button
          draw_button(x, y, bt.width, bt.height, adjustedTx, ty, autonLabel[counter]);
          counter++;
      }
  }
  // Confirm Button Initial
  confirm_button(bt, green, "Confirm:", black);
}
 
int touch_control(Measurements& b, int& auton, bool& confirmed) {
  // Get touch coordinates
  waitUntil(Brain.Screen.pressing());
  int xPos = Brain.Screen.xPosition();
  int yPos = Brain.Screen.yPosition();
  while (Brain.Screen.pressing()) {
    // Brain.Screen.printAt(100, 100, "X: %d Y: %d", xPos, yPos);
    // Check if confirm button is pressed
    if (xPos >= b.confirmX && xPos <= (b.confirmX + b.buttonWidth) && yPos >= b.confirmY && yPos <= (b.confirmY + b.buttonHeight)) {
      confirmed = true;
      // Confirm button when pressed
      confirm_button(b, purple, "Confirm:", black);
      return auton;
    } else {
      // Check which grid button is pressed
      for (int row=0; row < b.numRows; ++row) {
        for (int col=0; col < b.numCols; ++col) {
          double x = b.gridX + col * (b.width + b.colSpacing);
          double y = b.gridY + row * (b.height + b.rowSpacing);
          // Check if touch coordinates are within button boundary
          if (xPos >= x && xPos <= (x + b.width) && yPos >= y &&  yPos <= y + b.height) {
            // Set auton value based on button position press
            auton = row * b.numCols + col + 1;
          }
        }
      }
    }
  // Update touch coordinates
  xPos = Brain.Screen.xPosition();
  yPos = Brain.Screen.yPosition();
  }      
  // No change in auton value
  return auton;
}
 
void current_selction(Measurements& a, int current_auton) {
  Brain.Screen.printAt(a.autonTx, a.autonTy, "R%d", current_auton);
}
