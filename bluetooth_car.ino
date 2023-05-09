//    Bluetooth controled car code

char t;

void setup() {
  pinMode(5, OUTPUT);  //  left backward
  pinMode(4, OUTPUT);  //  left forward
  pinMode(2, OUTPUT);  //  right forward
  pinMode(3, OUTPUT);  //  right backward
  pinMode(6, OUTPUT);  //Led
  pinMode(7, OUTPUT);  // Horn
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }


  if (t == 'F') {  //move  forward(all motors rotate in forward direction)

    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    {
      if (t == 'M') {
        digitalWrite(6, HIGH);
      } else if (t == 'N') {
        digitalWrite(6, LOW);
      } else if (t == 'X') {
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
      }
    }

  }

  else if (t == 'G') {  //move reverse (all  motors rotate in reverse direction)
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    
       if (t == 'M') {
        digitalWrite(6, HIGH);
      }
      else if (t == 'N') {
        digitalWrite(6, LOW);
      }
      else if (t == 'X') {
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
      }
    
  }

  else if (t == 'L') {  //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    {
       if (t == 'M') {
        digitalWrite(6, HIGH);
      }
      else if (t == 'N') {
        digitalWrite(6, LOW);
      }
      else if (t == 'X') {
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
      }
    }
  }

  else if (t == 'R') {  //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)

    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    {
       if (t == 'M') {
        digitalWrite(6, HIGH);
      }
      else if (t == 'N') {
        digitalWrite(6, LOW);
      }
      else if (t == 'X') {
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
      }
    }

  }

  else if (t == 'S') {  //STOP (all motors stop)
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);


  } else if (t == 'M') {
    digitalWrite(6, HIGH);
  } else if (t == 'N') {
    digitalWrite(6, LOW);
  } else if (t == 'X') {
    digitalWrite(7, HIGH);
    delay(500);
    digitalWrite(7, LOW);
  }
}
