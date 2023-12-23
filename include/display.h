using namespace std;
// Rectangle Measurements
    struct Measurements {
        // Rectangle shape measurements
        double gridX = 20;
        double gridY = 20;
        double width = 120;
        double height = 60;
        // Spacing between the rectangles
        double rowSpacing = 30;
        double colSpacing = 40;
        int numRows = 2;
        int numCols = 3;
        // confirm Button
        double confirmX = gridX;
        double confirmY = gridY + numRows * (height + rowSpacing);
        // Span column width
        double buttonWidth = numCols * width + (numCols - 1) * colSpacing;
        // Half height
        double buttonHeight = height / 2.0;
        // Confirm Text
        double confirmTx = confirmX + buttonWidth / 3;
        double confirmTy = confirmY + buttonHeight / 2;
        // Auton Text
        double autonTx = confirmTx + colSpacing * 2.5;
        double autonTy = confirmTy + 10;
    };
 
// Determine Text Width
double calculate_text_width(string text);
 
// Draw Button with Text
void draw_button(double x, double y, double width, double height, double tx, double ty, string text);
 
// Create button grid
void button_grid(const Measurements& bt);
 
// Confirm Button
void confirm_button(const Measurements& cb, const vex::color color, string text, const vex:: color penColor);
 
// Touch Control
int touch_control(Measurements& b, int& auton, bool& confirmed);
 
// Auton Selction Display
void current_selction(Measurements& a, int current_auton);
