#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],cnt,sum;
bool vis[2000005];
void dfs(int stx,int sta,int enx,int ena,int l){
	if(sta==ena && l>=3){
		cnt++;return;
	}
	if(sta>ena) return;
	if(stx<enx){
		for(int i=sta+1;stx+d>=x[i];++i){
			if(!vis[i] || i==ena){
				dfs(x[i],i,enx,ena,l+1);
//				cout<<l<<endl;
				vis[i]=1;
			}
		}
	}
}

int main(){
	freopen("migrate.in" ,"r",stdin );
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int q=1;q<=t;++q){
		sum=0;
		cin>>n>>d;d++;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				cnt=0;memset(vis,0,sizeof vis);
				dfs(x[i],i,x[j],j,1);
				if(cnt==2) sum++;
			}
		}cout<<sum<<'\n';
	}
	return 0;
}
