#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],k[510];
vector<int>a[510],t[510],iw[500010],iwz[500010];
int mp[510][510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=1e15;
		}
		mp[i][i]=0;
	}
	int aa,tt;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			iw[aa].push_back(i);
			iwz[aa].push_back(tt);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			int aij=a[i][j];
			int ll=-1;
			for(int kk=0;kk<iw[aij].size();kk++){
				if(iw[aij][kk]==i){
					ll=kk;
					break;
				}
			}
			for(int kk=0;kk<iw[aij].size();kk++){
				if(iw[aij][kk]==i)continue;
				mp[i][iw[aij][kk]]=iwz[aij][kk]+iwz[aij][ll];
				mp[iw[aij][kk]][i]=iwz[aij][kk]+iwz[aij][ll];
			}
		}
	}
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][kk]+mp[kk][j],mp[i][j]);
				mp[j][i]=mp[i][j];
			}
		}
	}
	int xr,yr;
	for(int i=1;i<=q;i++){
		cin>>xr>>yr;
		int ans=1e15;
		for(int j=0;j<iw[xr].size();j++){
			for(int kk=0;kk<iw[yr].size();kk++){
				ans=min(ans,w[xr]+w[yr]+mp[iw[xr][j]][iw[yr][kk]]+iwz[yr][kk]+iwz[xr][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//-static-libgcc
