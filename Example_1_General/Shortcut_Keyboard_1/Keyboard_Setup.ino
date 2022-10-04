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
    Keyboard.key_code('c', KEY_CTRL);
    }
    if(button == 2)
    {
    Keyboard.key_code('y', KEY_CTRL);  
    }
    if(button == 3)
    {
    Keyboard.key_code('z', KEY_CTRL); 
    }
    if(button == 4)
    {
    Keyboard.key_code('v', KEY_CTRL); 
    }

  }

    if (page == 2)
  {
    if(button == 1)
    {
    Keyboard.key_code(KEY_F11);
    }
    if(button == 2)
    {
    Keyboard.key_code('e', KEY_LOGO);  
    }
    if(button == 3)
    {
    Keyboard.key_code('s', KEY_CTRL);   
    }
    if(button == 4)
    {
    Keyboard.key_code('f', KEY_CTRL);   
    }

  }
  if (page == 3)
  {
    if(button == 1)
    {
    Keyboard.key_code('t', KEY_CTRL);   
    }
    if(button == 2)
    {
    Keyboard.key_code(KEY_F5); 
    }
    if(button == 3)
    {
    Keyboard.key_code('l', KEY_LOGO);  
    }
    if(button == 4)
    {
    Keyboard.key_code('r', KEY_CTRL); 
    
    }

  }

  if (page == 4)
  {
    if(button == 1)
    {
    Keyboard.media_control(KEY_VOLUME_DOWN);
    delay(50);
    Keyboard.media_control(KEY_VOLUME_DOWN);

    }
    if(button == 2)
    {
    Keyboard.media_control(KEY_VOLUME_UP); 
    delay(50);
    Keyboard.media_control(KEY_VOLUME_UP);  
    }
    if(button == 3)
    {
    Keyboard.media_control(KEY_STOP);   
    }
    if(button == 4)
    {
    Keyboard.media_control(KEY_PLAY_PAUSE); 
    }

  }
  //add if statements here...

}