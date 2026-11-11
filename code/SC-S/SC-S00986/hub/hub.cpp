#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	if(t==1){
		write(1);
	}else if(t==2){
		write(1);
		putchar('\n');
		write(2);
	}else{
		for(int i=1;i<=t;i++){
			write(1);putchar('\n');
		}
	}
	return 0;
}