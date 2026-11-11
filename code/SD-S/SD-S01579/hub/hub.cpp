#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000005];
inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C=read(),T=read();
	while(T--){
		int n=read(),k=read();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout<<n/2<<'\n';
	}
	return 0;
}
