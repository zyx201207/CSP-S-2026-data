#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int x[N],nnn[N];
int fa[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cout.tie(nullptr)->sync_with_stdio(0);
	cin>>c;
	cin>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int tail=n;
		for(int i=n-1;i>=1;){
			if(i==tail) i--;
			if(x[tail]-x[i]<=d) fa[tail]=i,i--;
			else tail--;
		}
		if(tail!=1){
			for(int i=1;i<=tail;i++) fa[i]=1;
		}
		for(int i=n;i>=1;i--){
			if(x[fa[fa[i+1]]]+d>=x[fa[i]+2]) continue;
			if(fa[i]==i) continue;
			ans+=fa[i]-fa[fa[i]+i];
			nnn[fa[fa[i]+1]]*=2; 
			if(x[fa[fa[i]]]+d<=x[fa[i]]+i||nnn[fa[i]]) continue;
			ans+=nnn[fa[i]];
			nnn[fa[fa[i]]]=2;
		}
		cout<<ans<<'\n';
	} 
	return 0;
}