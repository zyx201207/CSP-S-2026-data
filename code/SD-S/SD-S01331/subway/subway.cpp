#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=505;
const int M=5e5+5;
const ll Ma=0x1f3f3f3f3f3f3f3f;
int C,n,m,d,q,aa,ab,ac,a[M];
bool b[N];
ll la[N][N],l;
vector<pair<ll,int> >v[M],ve[N];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>aa;
		for(int j=1;j<=aa;j++){
			cin>>ab>>ac;
			v[ab].push_back({i,ac});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			la[i][j]=Ma;
			if(i==j){
				la[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int x=v[i].size();
		for(int j=0;j<x;j++){
			for(int k=j+1;k<x;k++){
				int ba=v[i][j].first,bb=v[i][k].first;
				la[ba][bb]=min(la[ba][bb],(ll)v[i][j].second+v[i][k].second);
				la[bb][ba]=min(la[bb][ba],(ll)v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((la[i][j]!=Ma)&&(i!=j)){
//				cerr<<i<<" "<<j<<" "<<la[i][j]<<endl;
				ve[i].push_back({j,la[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=1;
		}
		pq.push({0ll,i});
		while(pq.size()){
			int x=pq.top().second;
			pq.pop();
			if(!b[x]){
				continue;
			}
//			cerr<<i<<"p"<<x<<endl;
			for(int j=0;j<ve[x].size();j++){
				int y=ve[x][j].first;
				
//				cerr<<i<<"q"<<x<<" "<<y<<" "<<la[i][y]<<" "<<la[i][x]+ve[x][j].second<<endl;
				if(la[i][y]>la[i][x]+ve[x][j].second||b[y]){
					la[i][y]=la[i][x]+ve[x][j].second;
					pq.push({la[i][y],y});
				}
			}
			b[x]=0;
		}
	}
	while(q--){
		cin>>aa>>ab;
		l=Ma;
		for(int i=0;i<v[aa].size();i++){
			for(int j=0;j<v[ab].size();j++){
				ll lb=la[v[aa][i].first][v[ab][j].first]+v[aa][i].second+v[ab][j].second;
				l=min(l,lb);
			}
		}
		l=l+a[aa]+a[ab];
		cout<<l<<endl;
	}
	return 0;
}
//Oct31==Dec25?
/*
schedule
14:30-15:00 T1_t+w
15:00-15:45 T2_t+T3_t
15:45-16:45 T2_w
16:45-17:45 T3_w
17:45-18:15 T4_t+w

time table
14:39 KT1
16:30 KT2
*/
