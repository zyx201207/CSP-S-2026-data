#include<bits/stdc++.h>

using namespace std;

#define int long long
struct NODA{
	int who,station;
};

int c,n,m,d,p;
int w[500010];
vector<int> a[510],t[510];
vector<NODA> g[510];
priority_queue<int ,vector<int> , greater<int> > pq;
signed main(){
	freopen("subway.in" ,"r",stdin );
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int numStation;
		cin>>numStation;
		for(int j=1;j<=numStation;j++){
			int id;
			cin>>id;
			a[i].push_back(id);
			int tim;
			cin>>tim;
			t[i].push_back(tim);
			
			
		}
		sort(a[i].begin(),a[i].end());
	}
	
	cout<<1;
	for(int i=1;i<=n;i++){
		for(int station:a[i]){
			for(int j=i+1;j<=n;j++){
				int ans;
				int l=0,r=a[j].size()-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(a[j][mid]>station){
						r=mid-1;
					}else{
						ans=mid;
						l=mid+1;
					}
				}
				cout<<ans;
				if(a[i][ans]==station){
					g[i].push_back({j,station});
					g[j].push_back({i,station});
				}
			}
		}
	}
	
	return  0;
}
/*md! vector<pair<int,int> > will RE! I don't write!!!!!!!!!!!!!!*/
