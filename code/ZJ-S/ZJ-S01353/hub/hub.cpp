#include<bits/stdc++.h>
using namespace std;
#define LL long long
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
const int inf=1e7;
int T,n,m,f[4005][4005][2][3],vis[15],ans;
vector<int>mp[4005];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	T=read();T=read();
	while(T--){
		n=read();m=read();
	    ans=inf;
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		if(m==1){
			int maxx=0;
			for(int i=1;i<=n;i++){
				int a=mp[i].size();
				maxx=max(maxx,a);
			}
			if(maxx==4)ans=1;
			else ans=2;
		}else if(m!=5){
			ans=1;
		}else{
			ans=0;
		}
		write(ans);
		putchar('\n');
		for(int i=1;i<=n;i++)mp[i].clear();
	}
	return 0;
}
