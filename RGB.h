class RGB{
  private:
    unsigned char red;
    unsigned char blue;
    unsigned char green;
    unsigned char rpin;
    unsigned char gpin;
    unsigned char bpin;
    bool rs;
    bool bs;
    bool gs;
  public:
    RGB(int, int, int);
    void tick();
    void begin();
    unsigned char r = red;
    unsigned char g = green;
    unsigned char b = blue;
    void stop();
};

RGB::RGB(int r,int g, int b){
  rpin = r;
  gpin = g;
  bpin = b;
  red = 255;
  blue = 127;
  green = 1;
  rs = true;
  bs = true;
  gs = true;
}

void RGB::begin(){
  pinMode(rpin,OUTPUT);
  pinMode(gpin,OUTPUT);
  pinMode(bpin,OUTPUT);
}

void RGB::tick(){
  analogWrite(rpin,red);
  analogWrite(gpin,green);
  analogWrite(bpin,blue);
  if(red >= 255 || red <= 0) rs = !rs; 
  if(green >= 255 || green <= 0) gs = !gs;
  if(blue >= 255 || blue <= 0) bs = !bs;
  red+= rs ? 1 : -1;
  blue+= bs ? 1 : -1;
  green+= gs ? 1 : -1;
} 

void RGB::stop(){
  analogWrite(rpin,0);
  analogWrite(gpin,0);
  analogWrite(bpin,0);
}
