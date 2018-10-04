$gcc pal.c
#include<stdio.h>

  int main(){
    char line[MAXLINE];
    int value;
    value=htoi(line);
    printf("The value of %s is %d",line,value);
    return 0;  //End of 2-3
    
    printf("%u",setbits((unsigned)12,3,2,(unsigned)57));  // 2-6
    
    printf("%u",(unsigned)invert((unsigned)8,(int)3,(int)3)); // 2-7
  }
  
  int htoi(char s[]){    //need help to make this one work
    int hexdigit,i,inhex,n;
    i = 0;
      if( s[i] == '0'){
          ++i;
          if(s[i] == 'x' || s[i] == 'X')
              ++i;
      }
    n = 0;
    inhex = YES;
      for(inhex==YES;++i){
          if(s[i] >='0' && s[i] <='9')
              hexdigit= s[i] - '0';
          else if(s[i] >='a' && s[i] <='f')
              hexdigit= s[i] -'a' + 10;
          else if(s[i] >='A' && s[i] <='F')
              hexdigit= s[i] -'A' + 10;
          else
              inhex = NO;
          if(inhex == YES)
              n = 16 * n + hexdigit;
      }
    return n;
  }
  
  unsigned setbits(unsigned x,int p,int n,unsigned y){  //2-6
    return x & ~(~(~0 << n) << (p+1-n)) | ( y & ~(~0<<n)) << (p+1-n);
  }
  
  unsigned invert(unsigned x, int p, int n){
     return   x ^ (~(~0 << n) << (p + 1 - n));
  }
