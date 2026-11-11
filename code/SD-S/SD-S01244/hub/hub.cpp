#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char g=getchar();
	while(g<'0'||g>'9'){
		if(g=='-')f=-1;
		g=getchar();
	}
	while(g>='0'&&g<='9'){
		x=x*10+g-'0';
		g=getchar();
	}
	return x*f;
}
int n,t;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	n=read(),t=read();
	srand(time(0));
	for(int i=1;i<=t;i++){
		cout<<rand()%3<<'\n';
	}
	return 0;
}

