#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,w,l,r,t,v;
int di[510][510],x[500010],len[510],y[500010][30],z[500010][30],len2[500010];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>w;
	memset(di,-1,sizeof(di));
	for(int i=1;i<=n;i++)
		di[i][i]=0;	
	for(int i=1;i<=m;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			cin>>t>>v;
			len2[t]++;
			y[t][len2[t]]=i,z[t][len2[t]]=v;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<len2[i];j++)
			for(int k=2;k<=len2[i];k++){
				if(j==k) continue;
				if(di[y[i][j]][y[i][k]]==-1)
					di[y[i][k]][y[i][j]]=di[y[i][j]][y[i][k]]=z[i][j]+z[i][k];
				else
					di[y[i][k]][y[i][j]]=di[y[i][j]][y[i][k]]=min(z[i][j]+z[i][k],di[y[i][j]][y[i][k]]);
			}		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(i==j||j==k||i==k) continue;
				if(di[j][i]==-1||di[i][k]==-1) continue;
				if(di[j][k]==-1)
					di[j][k]=di[j][i]+di[i][k];
				else 
					di[j][k]=min(di[j][i]+di[i][k],di[j][k]);
			}
	while(w--){
		cin>>l>>r;
		int mi=LLONG_MAX;
		for(int i=1;i<=len2[l];i++)
			for(int j=1;j<=len2[r];j++)
				mi=min(mi,di[y[l][i]][y[r][j]]+z[l][i]+z[r][j]);
		cout<<mi+x[l]+x[r]<<"\n";
	}
}
