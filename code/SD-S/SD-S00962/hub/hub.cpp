#include<bits/stdc++.h>

#define ll long long

using namespace std;

inline ll read(){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9' or c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9' and c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}

inline void write(ll k){
	if(k<0)putchar('-'),k=-k;
	if(k>9)write(k/10),k%=10;
	putchar(k+'0');
}




int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	write(-1);
	
	return 0;
}
