var GameScore = 0;
var Level = 0;








var keys = [];

var keyPressed = function() {
    keys[keyCode] = true;
};

keyReleased = function() {
    keys[keyCode] = false;
};


var Player = function(x, y, size, speed) {
    this.x = x;
    this.y = y;
    this.size = size;
    this.speed = speed;
    this.update = function() {
        if (keys[UP]) {
            this.y = this.y - this.speed;
            if (this.y < 10) {
                this.y = 10;
            }
        }
        if (keys[DOWN]) {
            this.y = this.y + this.speed;
            if (this.y > 390) {
                this.y = 390;
            }
        }
        if (keys[LEFT]) {
            this.x = this.x - this.speed;
            if (this.x < 10) {
                this.x = 10;
            }
        }
        if (keys[RIGHT]) {
            this.x = this.x + this.speed;
            if (this.x < 390) {
                this.x = 390;
            }
        }
    noStroke();
    fill(0, 255, 0);
    ellipse(this.x, this.y, this.size, this.size);
    };

};
var Dot = function(x, y, speed, size) {
    this.x = x;
    this.y = y;
    this.xVel = random(-speed,speed);
    this.yVel = random(-speed,speed);
    this.speed = speed;
    this.size = size;
    this.update = function(GreenDot) {
        if (this.x < GreenDot.x) {
            // the Green dot is to the left of the Red dot
            this.xVel = this.xVel - 0.05 * Level;
        }
        if (this.x > GreenDot.x) {
            // the Green dot is to the left of the Red dot
            this.xVel = this.xVel - 0.05 * Level;
        }
        if (this.y > GreenDot.y) {
            // the Green dot is to the left of the Red dot
            this.yVel = this.yVel - 0.05 * Level;
        }
        if (this.x < -8 || this.x > 408 || this.y < -8 || this.y > 408) {
        //something went wrong. lost red dot
        this.x = 200;
        this.y = 200;
        this.xVel = 3;
        this.yVel = 3;
        }
        
        
        //make the dots move
        this.x = this.x + this.xVel;
        if (this.x < 10 || this.x > 390) {
            this.xVel = -this.xVel;
        }
        if (this.y < 10 || this.y > 390) {
            this.yVel = -this.yVel;
        }
        
        this.y = this.y + this.yVel;
        // draw the dot
        noStroke();
        fill(255, 0, 0);
        ellipse(this.x, this.y, this.size, this.size);
    };
};



var player = new Player(100,100,49,1);

var dots = [];


var checkForCollisions = function(player, dots) {
    for (var i = 0; i < dots.length; i++) {
        var distance = dist(player.x, player.y, dots[i].x, dots[i].y);
        
        if (distance < 100) {
            dots[i].size = dots[i].size * 0.99;
            if (dots[i].size > player.size) {
                dots[i].size = 10;
            }
        } else {
            dots[i].size = dots[i].size * 1.002;
            if (dots[i].size > player.size) {
                dots[i].size = player;
            }
        }
        
        
        if (distance <= (player.size / 2 + dots[i].size / 2)) {
            // a collision has occured. remove the red dot from the array. add a point to the score. increase the level and difficulty
            dots.splice(i,1);
            GameScore = GameScore + 1;
        }
    }
};



var draw = function() {
    background(0, 0, 255);
    player.update();
    for (var i = 0; i < dots.length; i++) {
        dots[i].update(player);
    }
    checkForCollisions(player, dots);
    text("Score:" + GameScore + "Level" + Level, 20, 20);
    if (dots.length === 0) {
        // the level is cleared. make a new set of dots. increase the level and difficulty
        for (var i = 0; i < 10; i++) {
    dots[i] = new Dot(random(10, 390), random(10, 390), random(0,2), 20);
    }
    Level = Level + 1;
    }

};

