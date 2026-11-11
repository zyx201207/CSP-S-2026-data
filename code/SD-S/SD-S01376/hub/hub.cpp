#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int c,T;

void solve(){
	int n,k;
	n=read();k=read();
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();T=read();
	for(int i=1;i<=T;i++){
		solve();
		cout<<i<<"\n";
	}
	return 0;
}
/*
*/
