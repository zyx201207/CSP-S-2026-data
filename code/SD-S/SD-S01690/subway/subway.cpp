#include<bits/stdc++.h>
using namespace std;
long long w[500010],f[510][510];
vector<long long> vt[500010],xa[500010],xt[500010];
int main(){
	freopen("subway.in","r",stdin);
  	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,n,m,d,q,x,y,l;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)	cin>>w[i];
    for(int i=1;i<=n;i++){
    	cin>>l;
    	for(int j=0;j<l;j++){
    		cin>>x>>y;
//    		va[i].push_back(x);
    		vt[i].push_back(y);
    		xa[x].push_back(i);
    		xt[x].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)	f[i][j]=1e18; 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<xa[i].size();j++){
			for(int k=0;k<xa[i].size();k++){
				if(j==k)	continue;
				f[xa[i][j]][xa[i][k]]=min(f[xa[i][j]][xa[i][k]],vt[xa[i][j]][xt[i][j]]+vt[xa[i][k]][xt[i][k]]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)	f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
		}
	}
	for(int i=1;i<=q;i++){
		long long ans=1e18;
		cin>>x>>y;
		for(int j=0;j<xa[x].size();j++){
			for(int k=0;k<xa[y].size();k++)	ans=min(ans,f[xa[x][j]][xa[y][k]]+vt[xa[x][j]][xt[x][j]]+vt[xa[y][k]][xt[y][k]]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

