#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],st[25],t[25],s;
long long dis[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>st[j]>>t[j];
			for(int l=1;l<j;l++)dis[st[j]][st[l]]=dis[st[l]][st[j]]=t[j]+t[l];
		}
	}
	for(int k=2;k<m;k++){
		for(int i=1;i<k;i++){
			for(int j=k+1;j<=m;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<dis[l][r]+(long long)w[l]+(long long)w[r]<<endl;
	}
	return 0;
}