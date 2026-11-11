#include<bits/stdc++.h>
using namespace std;
int w[500005],k[500005];
int t[505][50005],a[505][50005];
int x,y,sum=1e9,c,n,m,d,q;
void dfs(int xx,int ans,bool f,int u1,int u2){
	if(xx==y){
		sum=min(sum,ans);
		//cout<<sum<<'\n';
		return;
	}
	if(f&&k[u1]>=u2+1){
		//cout<<1;
		//
		//cout<<ans+t[u1][u2]<<'\n';
		dfs(a[u1][u2+1],ans+t[u1][u2],1,u1,u2+1);
	}
	//cout<<1;
	//dfs(xx+1,ans+w[xx],0,0,0);
	for(int i=1;i<=n;i++){
		int l=1,r=k[i],sum=-1;
		//cout<<ans<<"m"<<'\n';
		while(l<=r){
			//cout<<'0';
			int mid=l+(r-l)/2;
			if(a[i][mid]==xx){
				sum=mid;
				break;
			}else if(a[i][mid]>xx) r=mid-1;
			else l=mid+1;
			//cout<<1;
		}
		//cout<<sum<<" "<<ans<<" "<<i<<'\n';
		if(sum!=-1&&sum+1<=k[i]){
			//cout<<1;
			//cout<<i<<"\n";
			//cout<<i<<" "<<sum<<'\n';
			//cout<<ans<<'+'<<t[i][sum]<<'\n';
			dfs(a[i][sum+1],ans+t[i][sum],1,i,sum+1);
		}
		//dfs(a[i][sum],ans+t[i][sum],1,i,sum);
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		//cout<<w[x]+w[y];
		dfs(x,w[x]+w[y],0,0,0);
		cout<<sum<<'\n';
	}
	return 0;
} 