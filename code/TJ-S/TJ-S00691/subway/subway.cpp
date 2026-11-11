#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x,y;
int w[500002],k[502];
int s[500002];
int a[502][10002],t[502][10002];
int fa[502][502];
int huan(int t2,int t1){
	int sm=0,cnt=INT_MAX;
	bool f=false;
	for(int i=1;i<=n;i++){
		f=false;
		sm=0;
		if(t2==i){
			continue;
		}
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==t1){
				f=true;
			}
		}
		if(f){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==y){
					sm+=t[i][j];
				}
			}
		}
		cnt=min(cnt,sm);
	}
	return cnt;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				fa[a[i][j]][a[i][j-1]]=a[i][j-1];
				fa[a[i][j-1]][a[i][j]]=a[i][j];
			}
		}
		fa[a[i][k[i]]][a[i][1]]=a[i][1];
		fa[a[i][1]][a[i][k[i]]]=a[i][k[i]];
	}
	int ans=0;
	int sum=0;
	while(q--){
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		sum=21000000;
		memset(s,0,sizeof(s));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
					s[i]+=t[i][j];
				}
				if(fa[a[i][j]][y]==y){
					s[i]+t[i][j];
				}
				s[i]+=huan(i,a[i][j]);
			}
			sum=min(sum,s[i]);
		}
		cout<<sum+ans<<'\n';
	}
	return 0;
} 
