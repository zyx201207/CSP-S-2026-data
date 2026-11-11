#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,d,q,n,m,t,a[500010],w[500010],ans[2001][2001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(ans,0x3f,sizeof(ans));
	if(m<=400){
	    for(int i=1;i<=n;i++){
	   	    int k;
	  	    cin>>k;
	   	    for(int j=1;j<=k;j++){
	   		 	ll p,t;
		 	  	cin>>p>>t;
			   	ans[p][i+m]=min(ans[p][i+m],t);
			    ans[i+m][p]=min(ans[i+m][p],t);
	   	    }
    	}
	    for(int p=1;p<=m;p++){
		    for(int i=1;i<=n+m;i++){
			ans[i][i]=0;
			    for(int j=1;j<=m+n;j++){
				    for(int k=1;k<=m+n;k++){
					    ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
				    }
			    }
		    }
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<ans[x][y]+w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
