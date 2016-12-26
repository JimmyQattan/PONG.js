var Result = 0;
var NumClicks = 0;
var Operand1 = 0;
var Operand2 = 0;
var Operator = "+";
var CalcArray = [Operand1, Operator, Operand2];
var Calc = function() {
    
    if (Operator === "+") {
        return Operand1 + Operand2;
    }
    if (Operator === "*") {
        return Operand1 * Operand2;
    }
    if (Operator === "/") {
        return Operand1 / Operand2;
    }
    if (Operator === "-") {
        return Operand1 - Operand2;
    }
    
};



var Button7 = function() {
    background(0, 0, 0);
    if (mouseClicked && mouseX <= 50 && mouseX >= 0 && mouseY >= 0 && mouseY <= 50 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            
            if (NumClicks === 0) {
                Operand1 = 7;
            }
            if (NumClicks === 2) {
                Operand2 = 7;
            }
            NumClicks = NumClicks + 1;
        println("7");
        };
     
        
    } else {
        fill(255, 255, 255);
    }
    fill(255, 255, 255);
    rect(0,0,50,50);
    fill(255, 0, 0);
    text("7", 22, 28);
    
};

var Button8 = function() {
    
    if (mouseClicked && mouseX >= 50 && mouseX <= 100 && mouseY >= 0 && mouseY <= 50 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            
            println("8");
            
            if (NumClicks === 0) {
                Operand1 = 8;
            }
            if (NumClicks === 2) {
                Operand2 = 8;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(50, 0, 50, 50);
    fill(255, 0, 0);
    text("8", 72, 28);
    
    
};

var Button9 = function() {
    if (mouseClicked && ((100 <= mouseX && mouseX <= 150) && (0 <= mouseY && mouseY <= 50))&& (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("9");
            
            if (NumClicks === 0) {
                Operand1 = 9;
            }
            if (NumClicks === 2) {
                Operand2 = 9;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(100, 0, 50, 50);
    fill(255, 0, 0);
    text("9", 120, 28);
};


var Button4 = function() {
if (mouseClicked && mouseX >= 0 && mouseX <= 50 && mouseY >= 50 && mouseY <= 100 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("4");
            
            if (NumClicks === 0) {
                Operand1 = 4;
            }
            if (NumClicks === 2) {
                Operand2 = 4;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(0, 50, 50, 50);
    fill(255, 0, 0);
    text("4", 21, 79);
};


var Button5 = function() {
    if (mouseClicked && mouseX >= 50 && mouseX <= 100 && mouseY >= 50 && mouseY <= 100 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("5");
            
            if (NumClicks === 0) {
                Operand1 = 5;
            }
            if (NumClicks === 2) {
                Operand2 = 5;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(50, 50, 50, 50);
    fill(255, 0, 0);
    text("5", 72, 78);
};



var Button6 = function() {
    if (mouseClicked && mouseX >= 100 && mouseX <= 150 && mouseY >= 50 && mouseY <= 100 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("6");
            
            if (NumClicks === 0) {
                Operand1 = 6;
            }
            if (NumClicks === 2) {
                Operand2 = 6;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(100, 50, 50, 50);
    fill(255, 0, 0);
    text("6", 120, 79);
};


var Button1 = function() {
    if (mouseClicked && mouseX >= 0 && mouseX <= 50 && mouseY >= 100 && mouseY <= 150 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("Button1()");
            
            if (NumClicks === 0) {
                Operand1 = 1;
            }
            if (NumClicks === 2) {
                Operand2 = 1;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(0, 100, 50, 50);
    fill(255, 0, 0);
    text("1", 23, 128);
};

var Button2 = function() {
    if (mouseClicked && mouseX >= 50 && mouseX <= 100 && mouseY >= 100 && mouseY <= 150 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("2");
            
            if (NumClicks === 0) {
                Operand1 = 2;
            }
            if (NumClicks === 2) {
                Operand2 = 2;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(50, 100, 50, 50);
    fill(255, 0, 0);
    text("2", 71, 128);
};


var Button3 = function() {
    if (mouseClicked && mouseX >= 100 && mouseX <= 150 && mouseY >= 100 && mouseY <= 150 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("3");
            
            if (NumClicks === 0) {
                Operand1 = 3;
            }
            if (NumClicks === 2) {
                Operand2 = 3;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(100, 100, 50, 50);
    fill(255, 0, 0);
    text("3", 120, 128);
};


var Button0 = function() {
    if (mouseClicked && mouseX >= 50 && mouseX <= 100 && mouseY >= 150 && mouseY <= 200 && (NumClicks === 0 || NumClicks === 2)) {
        mouseClicked = function() {
            println("0");
            
            if (NumClicks === 0) {
                Operand1 = 0;
            }
            if (NumClicks === 2) {
                Operand2 = 0;
            }
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(50, 150, 50, 50);
    fill(255, 0, 0);
    text("0", 72, 178);
};


var Add = function() {
    if (mouseClicked && mouseX >= 150 && mouseX <= 200 && mouseY >= 0 && mouseY <= 50 && (NumClicks === 1 || NumClicks === 3)) {
        mouseClicked = function() {
            println("+");
            
            Operator = "+";
            
            NumClicks = NumClicks + 1;
            
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(150, 0, 50, 50);
    fill(255, 0, 0);
    text("+", 172, 29);
};

var Subtract = function() { 
    if (mouseClicked && mouseX >= 150 && mouseX <= 200 && mouseY >= 50 && mouseY <= 100 && (NumClicks === 1 || NumClicks === 3)) {
        mouseClicked = function() {
            println("-");
            
            Operator = "-";
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(150, 50, 50, 50);
    fill(255, 0, 0);
    text("-", 173, 81);
};

var Multiply = function() {
    if (mouseClicked && mouseX >= 150 && mouseX <= 200 && mouseY >= 100 && mouseY <= 150 && (NumClicks === 1 || NumClicks === 3)) {
        mouseClicked = function() {
            println("*");
            
            Operator = "*";
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(150, 100, 50, 50);
    fill(255, 0, 0);
    text("*", 173, 134);
};

var Divide = function() {
    if (mouseClicked && mouseX >= 150 && mouseX <= 200 && mouseY >= 150 && mouseY <= 200 && (NumClicks === 1 || NumClicks === 3)) {
        mouseClicked = function() {
            println("/");
            
            Operator = "/";
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(150, 150, 50, 50);
    fill(255, 0, 0);
    text("/", 175, 180);
};

var Equal = function() {
    if (mouseClicked && mouseX >= 100 && mouseX <= 150 && mouseY >= 150 && mouseY <= 200 && (NumClicks === 1 || NumClicks === 3)) {
        mouseClicked = function() {
            
            
            Result = Calc(); 
            
            
            println("=" + Result);
            
            NumClicks = NumClicks + 1;
        };
        
        
    
        
    } else {
        fill(255, 255, 255);
    }
    
    fill(255, 255, 255);
    rect(100, 150, 50, 50);
    fill(255, 0, 0);
    text("=", 122, 180);

};
   
 
draw = function() {
    Button7();
    Button8();
    Button9();
    Button4();
    Button5();
    Button6();
    Button1();
    Button2();
    Button3();
    Button0();
    Add();
    Subtract();
    Multiply();
    Divide();
    Equal();
    
};





