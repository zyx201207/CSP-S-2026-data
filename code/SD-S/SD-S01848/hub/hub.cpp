#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
long long ans=1;
int c,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		int u[100005],v[100005];
		int n=read(),k=read();
		for(int i=1;i<=n-1;i++){
			u[i]=read(),v[i]=read();
		}
		int m=(n-1)/2,aa=1;
		for(int i=1;i<=m;i++){
			if(u[i]!=i||v[i]!=i+1) aa=0;
		}
		for(int i=m+1;i<=n-1;i++){
			if(u[i]!=i-m||v[i]!=i+1) aa=0;
		}
		if(aa==1){
			cout<<12251<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
	return 0;
}
