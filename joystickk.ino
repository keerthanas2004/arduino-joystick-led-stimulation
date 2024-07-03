#define LEFT 3      //LEFT LED CONFIGURATION
#define RIGHT 4     //RIGHT LED CONFIGURATION
#define UP 5        //UP LED CONFIGURATION
#define DOWN 2      //DOWN LED CONFIGURATION
#define X_AXIS A0   //ANALOG INPUT OF X AXIS VALUE FROM JOYSTICK
#define Y_AXIS A1   //ANALOG INPUT OF Y AXIS VALUE FROM JOYSTICK
#define SW_pin A2   //SWITCH PIN OF JOYSTICK

void setup() 
{

  pinMode(RIGHT, OUTPUT);   //SET RIGHT PIN AS OUTPUT
  pinMode(LEFT, OUTPUT);    //SET LEFT PIN AS OUTPUT
  pinMode(UP, OUTPUT);      //SET UP PIN AS OUTPUT
  pinMode(DOWN, OUTPUT);    //SET DOWN PIN AS OUTPUT
  pinMode(X_AXIS,INPUT);    //SET X-AXIS PIN OF JOYSTICK AS ANALOG INPUT
  pinMode(Y_AXIS,INPUT);    //SET Y-AXIS PIN OF JOYSTICK AS ANALOG INPUT
  pinMode(SW_pin, INPUT);   //SET SWITCH PIN OF JOYSTICK AS ANALOG INPUT

  //Initialization
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

}

void loop() 
{
  
  //Initialize LED as LOW 
  digitalWrite(UP,LOW);
  digitalWrite(DOWN,LOW);
  digitalWrite(RIGHT,LOW);
  digitalWrite(LEFT,LOW);
  
  if(digitalRead(SW_pin)==HIGH)
  {

    int xread=analogRead(X_AXIS);     //READ VALUE OF X-AXIS FROM JOYSTICK
    int yread=analogRead(Y_AXIS);     //READ VALUE OF Y-AXIS FROM JOYSTICK
    Serial.print(xread);              //Print the values on screen
    Serial.print("\	");
    Serial.println(yread);

    //According to the position of the joystick, turn LED on
    if(yread >= 800)
    {
      digitalWrite(UP,HIGH);
    }

    if(xread >= 800)
    {
      digitalWrite(LEFT,HIGH);
    }

    if(yread == 0)
    {
      digitalWrite(DOWN,HIGH);
    }

    if(xread == 0)
    {
      digitalWrite(RIGHT,HIGH);
    }

  }

}

