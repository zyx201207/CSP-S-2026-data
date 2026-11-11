#include<bits/stdc++.h>
using namespace std;
int read(){
  int x=0,f=0;char ch=getchar();
  if(ch=='-') f=1;
  while(ch<'0' || ch>'9') ch=getchar();
  while(ch>='0' && ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
  if(f) x=-x;
  return x;
}
void write(int x){
  if(x>9) write(x/10);
  putchar(x%10+'0');
  return ;
}
int main(){
  int a=read(),b=read();
  write(a+b),putchar('\n');
  return 0;
}