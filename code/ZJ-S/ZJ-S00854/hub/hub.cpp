#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define N 1000010
using namespace std;
ll read(){
	int f=0;
	ll ans=0;
	char c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ans=ans*10ll+c-'0';
		c=getchar();
	}
	if(f){
		ans*=-1;
	}
	return ans;
}
int c,t,n,k;
vector<int>g[N];
void solve(){
	n=read();k=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		g[u].pb(v);
		g[v].pb(u);
	}
	int half=(n/2+1)/2+1;
	if(k>half){
		if(k==n){
			half=0;
		}else{
			half=1;
		}
	}else{
		while(k>0){
			half--;
			k-=2;
		}
	}
	printf("%d\n",half);
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		solve();
	}
	return 0;
}
/*
Please give me an 1=
I don't want to AFO
Chocolate tastes good
*/