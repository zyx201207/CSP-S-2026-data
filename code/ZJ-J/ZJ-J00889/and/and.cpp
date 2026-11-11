#include<bits/stdc++.h>
using namespace std;
int a[200007];
bool vis[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int mod=1<<30,ans=0;
	while(mod>0){
		int g=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]>=mod) g++;
		}
		if(g>=m){
			ans+=mod;
			for(int i=1;i<=n;i++){
				if(a[i]<mod) vis[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=mod) a[i]-=mod;
		}
		mod/=2;
	}
	cout<<ans;
}