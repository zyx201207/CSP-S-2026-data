#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],st[500005][505],r[100005][2],tl[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//XXXXXXXXXX
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)tl[i][j]=0;
			else tl[i][j]=1e9+5;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			st[i][j]=1e9+5;
		}
	}
	//XXXXXXXXXX
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			st[a][i]=t;
		}
	}
	for(int i=1;i<=q;i++)cin>>r[i][0]>>r[i][1];
	//XXXXXXXXXX
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				tl[j][k]=min(tl[j][k],st[i][j]+st[i][k]);
				tl[k][j]=min(tl[j][k],st[i][j]+st[i][k]);
			}
		}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		for(int k=1;k<=n;k++){
    			tl[j][k]=min(tl[j][k],tl[j][i]+tl[i][k]);
			}
		}
	}
	//XXXXXXXXXX
	for(int i=1;i<=q;i++){
		int ans=1e9+5;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ans=min(ans,w[r[i][0]]+w[r[i][1]]+st[r[i][0]][j]+st[r[i][1]][k]+tl[j][k]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
