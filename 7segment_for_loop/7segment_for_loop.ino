//..Ù…Ù„Ø§Ø­Ø¶Ø© Ù„Ø§Ø²Ù… Ù†ØªØ§ÙƒØ¯Ùˆ Ù…Ù† ÙƒÙˆÙ…ÙˆÙ†Ø¯ Ù‡Ù„ Ø¨Ø§Ù„Ø¬ Ø§Ù† Ø¯ÙŠ ÙˆÙ„Ø§ Ø¨Ø§Ù„ ÙÙŠ Ø³ÙŠ Ø³ÙŠ
// Pin connection sequence a , b , c , d , e , f , g , dp
int segPins[] = { 12, 13,3, 4, 5,10 ,11, A5 };   

int number[11][8] =

{
    { 1, 1, 1, 1, 1, 1, 0, 0 },  // 0
    { 0, 1, 1, 0, 0, 0, 0, 0 },  // 1
    { 1, 1, 0, 1, 1, 0, 1, 0 },  // 2
    { 1, 1, 1, 1, 0, 0, 1, 0 },  // 3
    { 0, 1, 1, 0, 0, 1, 1, 0 },  // 4
    { 1, 0, 1, 1, 0, 1, 1, 0 },  // 5
    { 1, 0, 1, 1, 1, 1, 1, 0 },  // 6
    { 1, 1, 1, 0, 0, 0, 0, 0 },  // 7
    { 1, 1, 1, 1, 1, 1, 1, 0 },  // 8
    { 1, 1, 1, 1, 0, 1, 1, 0 },  // 9
    { 0, 0, 0, 0, 0, 0, 0, 1 }  // dot or dp
};
 void setup()

{
  // set all 8 pins as output
  for (int i = 0; i < 8; i++)
  {
    pinMode(segPins[i], OUTPUT);
  }
}
void show ( int n ) // n is the row number of the array
{
  for (int i = 0; i < 8; i++)  // elements (or columns) in each row of array
  {

         // write each element to each pin of Arduino as per the value 1 or 0
   // digitalWrite(segPins[i], number[n][i]); // for CC

    digitalWrite(segPins[i], 1-number[n][i]); // invert for CA 
  }
}
void loop() {

  for (int i = 0; i < 11; i++) // select each row of the array
  {
    show ( i ); //  show the code written for the row in the array
    delay(1000);
  }
}
