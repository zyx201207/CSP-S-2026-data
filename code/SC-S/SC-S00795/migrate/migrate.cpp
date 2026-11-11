#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[200005];
int ans,cnt;
int minl=0x3f3f3f3f3f3f3f;
void dfs1(int idx,int tgt,int num){
	if(idx==tgt){
		minl=min(minl,num);
		return; 
	}
	for(int i=idx+1;i<=tgt;i++){
		if(x[i]-x[idx]<=d) dfs1(i,tgt,num+1);
	}
}
void dfs2(int idx,int tgt,int num){
	if(idx==tgt){
		cnt+=num==minl;
		return;
	}
	for(int i=idx+1;i<=n;i++){
		if(x[i]-x[idx]<=d) dfs2(i,tgt,num+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				minl=0x3f3f3f3f3f3f3f;
				cnt=0;
				dfs1(i,j,0);
				dfs2(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}