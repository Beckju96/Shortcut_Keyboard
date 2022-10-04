//set the color of the LEDs for each page:

void set_color(int page)
{
  if (page == 1)
  {
  r = 0;
  g = 0;
  b = 100;
  }
  if (page == 2)
  {
  r = 0;
  g = 100;
  b = 0;
  }
  if (page == 3)
  {
  r = 100;
  g = 0;
  b = 0;
  }
  if (page == 4)
  {
  r = 100;
  g = 100;
  b = 100;
  }

  pixels.setPixelColor(0, pixels.Color(r/8, g/8, b/8)); //decrease the brightness of the status LED
  pixels.show();

}


//Define your shortcuts here 
//To add pages, just copy and paste additional if statements (page ==5 , page == 6, ...) and add the button definition:
//Example: Keyboard.key_code('s', KEY_CTRL); Keyboard.printf("a"); Keyboard.media_control(KEY_VOLUME_UP);

void send_key(int button, int page){

  if (page == 1)
  {
    if(button == 1)
    {
    Keyboard.printf("e");
    }
    if(button == 2)
    {
    Keyboard.printf("h"); 
    }
    if(button == 3)
    {
    Keyboard.printf("f");
    }
    if(button == 4)
    {
    Keyboard.printf("q");
    }

  }

    if (page == 2)
  {
    if(button == 1)
    {
    Keyboard.printf("r");
    }
    if(button == 2)
    {
    Keyboard.printf("c");  
    }
    if(button == 3)
    {
    Keyboard.printf("d");  
    }
    if(button == 4)
    {
    Keyboard.printf("l");  
    }

  }
  if (page == 3)
  {
    if(button == 1)
    {
    Keyboard.printf("m");  
    }
    if(button == 2)
    {
    Keyboard.printf("a");
    }
    if(button == 3)
    {
    Keyboard.printf("d");  
    }
    if(button == 4)
    {
    Keyboard.key_code('z', KEY_CTRL); 
    
    }

  }

  if (page == 4)
  {
    if(button == 1)
    {
    Keyboard.printf("o");
    }
    if(button == 2)
    {
    Keyboard.printf("t"); 
    }
    if(button == 3)
    {
    Keyboard.printf("j"); 
    }
    if(button == 4)
    {
    Keyboard.key_code('j', KEY_SHIFT);
    }

  }
  //add if statements here...

}