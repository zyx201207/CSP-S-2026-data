#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
   int s=0,w=1;char ch=getchar();
   while(!isdigit(ch)){if(ch=='-'){w=-1;}ch=getchar();}
   while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main(){

	return 0;
}

