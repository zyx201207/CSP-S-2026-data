#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;

inline ll read(){
	ll f=1,w=0;
	char ch=getchar();
	for(;ch>'9' or ch<'0';ch=getchar())if(ch=='-') f=-1;
	for(;ch>='0' and ch<='9';ch=getchar()) w=w*10+ch-'0';
	return f*w;
}
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10),x%=10;
	putchar(x+'0');
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c=read(),t=read();
	for(ll i=1;i<=t;i++){
		write(i/2+1),putchar('\n');
	}
	return 0;
}
