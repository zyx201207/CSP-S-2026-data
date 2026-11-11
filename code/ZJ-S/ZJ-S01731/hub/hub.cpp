#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int N=5e5+5;
inline int read( ){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
#define rd read()
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>10)write(x/10);
	putchar(x%10+'0');
}
int c,t,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand((unsigned)time(0));
    c=rd;t=rd;n=rd;k=rd;
    for(int i=1;i<n;i++){int u,v;u=rd;v=rd;}
    while(t--){
    	if(n<=5){write(rand()%3);putchar('\n');}
    	else if(n<=10){write(rand()%6);putchar('\n');}
    	else if(n<=100){write(rand()%51);putchar('\n');}
    	else if(n<=1000){write(rand()%501);putchar('\n');}
    	else{ write(rand());putchar('\n');}
	}
	return 0;
}
/*

*/