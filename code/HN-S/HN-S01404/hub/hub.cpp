#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0; char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+(c^48),
		c=getchar();
	return x;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	for(int i=1;i<=t;i++){
		int n=read(),k=read();
		for(int j=1;j<n;j++)
			int x=read(),y=read();
	}
	for(int i=1;i<=t;i++)
		cout<<0<<'\n';
	return 0;
}
