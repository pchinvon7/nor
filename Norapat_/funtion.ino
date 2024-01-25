
void out_red()
  {
    Motor(20,20);delay(300);
   // do{Motor(20, 20);}while(mcp_f(1) < 500);
    Motor(-20, -20); delay(10);
    Motor(0, 0); delay(30);

    
    do{Motor(-10, 60);}while(mcp_f(1) > md_mcp_f(1));
    do{Motor(-10, 60);}while(mcp_f(4) > md_mcp_f(4));
    Motor(10, -50); delay(30);
    Motor(-1, -1); delay(30);
  }

void yello_L()
  {
    fline_2sensor(15, 15, 0.3, 0, "0:1","a7", 's', 30); 
    
    do{Motor(40, 10);}while(mcp_f(1) > md_mcp_f(1));
    do{Motor(40, 10);}while(mcp_f(1) < md_mcp_f(1));
    Motor(-40, -10); delay(30);
    Motor(0, 0); delay(30);
      
    slow_down();delay(300);
     Motor(-30,-30);delay(100);
    do{Motor(-30, -30);}while(analogRead(27) > md_adc(27));
    Motor(30, 30); delay(30);
    Motor(0, 0); delay(30);
  }
void yello_R()
  {
           
    
    fline_2sensor(15, 15, 0.3, 0, "6:7","a0", 's', 30); 

    do{Motor(10, 40);}while(mcp_f(6) > md_mcp_f(6));
    do{Motor(10, 40);}while(mcp_f(6) < md_mcp_f(6));
    Motor(-10, -40); delay(30);
    Motor(0, 0); delay(30);
      
    slow_down();delay(300);
    

    do{Motor(-30, -30);}while(analogRead(26) > md_adc(26));
    Motor(30, 30); delay(30);
    Motor(0, 0); delay(30);
             
  }
void pidsensor_0()
{
          while(1)
          {
            float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
            float error_R = map(mcp_f(0), min_mcp_f(0), max_mcp_f(0), 0, 30 );
            errors = 0- error_R;  
            I = 0;
            previous_I = 0;
            previous_error = 0;
            P = errors;
            I = I + previous_I;
            D = errors - previous_error ;            
            previous_I=I;
            previous_error=errors  ;  
            PID_output = (0.5* P) + (0.00015 * I) + (0.5* D); 

            Motor(20 + PID_output, 10 - PID_output);
            Serial.println(errors);
            
              if(mcp_f(7)<md_mcp_f(7)&&mcp_f(6)<md_mcp_f(6))
                {
                    break;
                }
                  
  
             
          }
        Motor(-20,-20);delay(30);
        Motor(0,0);delay(30); 
        
        slow_down();delay(300);
                  do{Motor(-30,-30);}while( analogRead(27)>md_adc(27));  
          Motor(30,30);delay(20);
          Motor(0,0);delay(30); 
          //////////
}
void pidsensor_7()
{
  

          while(1)
          {
            float error_L = map(mcp_f(3), min_mcp_f(3), max_mcp_f(3), 0, 30 );
            float error_R = map(mcp_f(7), min_mcp_f(7), max_mcp_f(7), 0, 30 );
            errors = 0 + error_R;  
            I = 0;
            previous_I = 0;
            previous_error = 0;
            P = errors;
            I = I + previous_I;
            D = errors - previous_error ;            
            previous_I=I;
            previous_error=errors  ;  
            PID_output = (0.5* P) + (0.00015 * I) + (0.5* D); 

            Motor(10 + PID_output, 20 - PID_output);
            Serial.println(errors);
            
              if(mcp_f(0)<md_mcp_f(0)&&mcp_f(1)<md_mcp_f(1))
                {
                    break;
                }
                  
  
             
          }
        Motor(-20,-20);delay(30);
        Motor(0,0);delay(30); 
        slow_down();delay(300);
        ////////
                  do{Motor(-30,-30);}while( analogRead(26)>md_adc(26));  
          Motor(30,30);delay(20);
          Motor(0,0);delay(30); 
          ////////
}
