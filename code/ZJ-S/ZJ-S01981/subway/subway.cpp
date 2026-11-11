#include<iostream>
#include<vector>
#define fi first
#define se second
using namespace std;
int c,n,m,d,q;
int k[505];
int w[500005];
long long flo[505][505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<vector<pair<int,int> > >sta(m+2);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			flo[i][j]=1e14;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int c;
		long long ww;
		for(int j=1;j<=k[i];j++){
			cin>>c>>ww;
			for(auto kk:sta[c]){
				flo[kk.fi][i]=min(flo[kk.fi][i],ww+kk.se);
				flo[i][kk.fi]=flo[kk.fi][i];
			}
			sta[c].push_back(make_pair(i,ww));
		}
	}
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				flo[i][j]=min(flo[i][j],flo[i][kk]+flo[kk][j]);
			}
		}
	}
	int l,r;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		long long ans=1e15;
		for(auto j:sta[l]){
			for(auto kk:sta[r]){
				ans=min(flo[j.fi][kk.fi]+j.se+kk.se,ans);
			}
		}
		cout<<ans+w[l]+w[r]<<"\n";
	}
	return 0;	
}