#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ans;
int k[505],mp[400005][505],p[505][505];

int wc[2000],l,r,t[505];
void di(){
	while(l<=r){
		int xx=wc[l];
		for(int i=1;i<=n;i++){
			if(p[xx][i]>0){
				if(t[i]>p[xx][i]+t[xx]){
					r++;
					wc[r]=i;
					t[i]=p[xx][i]+t[xx];
				}
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int t;
		for(int j=1;j<=k[i];j++){
			cin>>t;
			cin>>mp[t][i];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==0)continue;
			for(int k=i+1;k<=n;k++){
				if(mp[i][k]==0)continue;
				p[j][k]=p[k][j]=min(p[j][k],mp[i][j]+mp[i][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			if(mp[x][i]==1){ 
				memset(t,0x3f3f3f,sizeof(t));
				wc[1]=i;
				t[i]=0;
				l=r=1;
				di();
			} 
		}
		cout<<t[y]<<endl;
	}
	return 0;
} 
