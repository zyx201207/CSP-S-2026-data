#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,l,r,mina;
long long w[500005],k[505];
map <long long,long long> a[505],s[505];
map <long long,bool> vis[505];
void dfs(long long nows,long long num,long long sum){
	if(nows==r){
		mina=min(mina,sum+a[num][r]);
//		cout<<"\n";
//		cout<<mina<<"\n";
		return;
	}
	for(int i=1;i<=k[num];i++){
		if(vis[num][s[num][i]]==0){
			vis[num][s[num][i]]=1;
			dfs(s[num][i],num,sum+a[num][nows]);
			vis[num][s[num][i]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==num){
			continue;
		}
		for(int j=1;j<=k[i];j++){
			if(s[i][j]==nows&&vis[i][nows]==0){
				vis[i][nows]=1;
				dfs(nows,i,sum+a[num][nows]);
				vis[i][nows]=0;
				break;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("subway3.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>s[i][j];
			cin>>a[i][s[i][j]];
		}
	}
	while(q--){
		cin>>l>>r;
		mina=1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(s[i][j]==l){
					for(int x=1;x<=n;x++){
						for(int y=1;y<=k[x];y++){
							vis[x][y]=0;
						}
					}
//					cout<<i<<" "<<j<<"\n";
					vis[i][l]=1;
					dfs(l,i,w[l]);
				}
			}
		}
		cout<<mina+w[r]<<"\n";
	}
	return  0;
}
