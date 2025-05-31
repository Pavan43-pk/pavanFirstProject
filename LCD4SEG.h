 #define datalines P2        
sbit RS=P2^5;
sbit EN=P2^6;
void LCD_cmd(unsigned char);        //------
void LCD_data(unsigned char);       //     |
void LCD_init(void);                //     |
void LCD_string(unsigned char []);  //  Function declaration
void LCD_numb(unsigned long);       //     |
void delay(unsigned int);           //------
void LCD_cmd(unsigned char ch){
   unsigned char temp;
   temp=((ch>>4) & 0x0F);
   datalines=temp;
   RS=0;
   EN=1;
   delay(10);                 //10 microseconds
   EN=0;
   
   temp=((ch) & 0x0F);
   datalines=temp;
   RS=0;
   EN=1;
   delay(10);                 //10 microseconds
   EN=0;
}
void LCD_data(unsigned char c){
   unsigned char temp;
   temp=((c>>4) & 0x0F);
   datalines=temp;
   RS=1;
   EN=1;
   delay(10);                 //10 microseconds
   EN=0;
   
   temp=((c) & 0x0F);
   datalines=temp;
   RS=1;
   EN=1;
   delay(10);                 //10 microseconds
   EN=0;
}
void LCD_init(){
   LCD_cmd(0x02);      //Return to home
   LCD_cmd(0x28);      //4-bit mode (2 lines)
   LCD_cmd(0x06);
   LCD_cmd(0x0C);      //Cursor off
}
void LCD_string(unsigned char ch[]){
     int num;
     for(num=0;ch[num]!='\0';num++){
         LCD_data(ch[num]);
       }}
void LCD_numb(unsigned int p){
     int d,s[5];
     for(d=0;p>0;d++){
       s[d]=p%10; 
       p=p/10;
      } 
     while(d>0){
    d--;
       LCD_data(48+s[d]);
       }
} 
void delay(unsigned int k){
    int i,j;
    for(i=0;i<k;i++){
       for(j=0;j<1000;j++);
      }}