#include<bits/stdc++.h>
using namespace std;
#define int long long

const int r=1e9;

int c,n,m,d,q;
int w[1005];

int k;
int f[1005][1005];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    cin>>c>>n>>m>>d>>q;
    
    for(int i=1;i<=m;i++)
    	cin>>w[i];
    
    for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i==j)
				f[i][j]=0;
			else
				f[i][j]=r;
    
    for(int i=1;i<=n;i++){
    	cin>>k;
    	int xx1,dd1,xx2,dd2;
    	cin>>xx1>>dd1>>xx2>>dd2;
    	f[xx1][xx2]=dd1+dd2;
    	f[xx2][xx1]=dd1+dd2;
	}
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<f[l][r]+w[l]+w[r]<<'\n';
	}
}
