#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int biao[505][505];
int w[500005];
int guo[500005][25];
int cnt[500005];
int shi[500005][25];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int kt;cin>>kt;		
		for(int j=1;j<=kt;j++){
			int zhantai;
			cin>>zhantai;cnt[zhantai]++;guo[zhantai][cnt[zhantai]]=i;
			cin>>shi[zhantai][cnt[zhantai]];
		}
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        if(i!=j) biao[i][j]=1e17;
	for(int i=1;i<=m;i++)
	    for(int l=1;l<=cnt[i];l++)
	        for(int r=1;r<=cnt[i];r++)
	        if(l!=r)biao[guo[i][l]][guo[i][r]]=min(biao[guo[i][l]][guo[i][r]],shi[i][l]+shi[i][r]);
	for(int k=1;k<=n;k++)
	    for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++)
	            if(i!=j) biao[i][j]=min(biao[i][j],biao[i][k]+biao[k][j]);
	for(int i=1;i<=q;i++){
		int x,y,ans=1e17;
		cin>>x>>y;
		for(int l=1;l<=cnt[x];l++)
		    for(int r=1;r<=cnt[y];r++)
		        ans=min(ans,shi[x][l]+shi[y][r]+biao[guo[x][l]][guo[y][r]]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
