#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll read(){
	ll x=0;bool sym=0;char ch=getchar();
	while(!isdigit(ch)) sym^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return sym?-x:x;
}

ll c,t;

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	c=read(),t=read();
	srand(time(0));
	for(ll i=1;i<=t;i++) cout<<rand()<<'\n';

	return 0;
}
