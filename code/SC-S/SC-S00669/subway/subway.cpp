#include<bits/stdc++.h>
#define ll long long
#define VI vector<int>
#define endl '\n'
#define up(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
const int MM=5e5+5,NN=505;
const ll INF=1e16+7;
ll c,m,n,d,q,w[MM],G[NN][NN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	up(i,1,NN-1) up(j,1,NN-1) if(i!=j) G[i][j]=INF;
	cin>>c>>n>>m>>d>>q;
	up(i,1,m) cin>>w[i];
	up(i,1,n){
		int k; cin>>k;
		vector<array<int,2>> st;
		up(j,1,k){
			int a,t;
			cin>>a>>t;
			up(i,0,st.size()-1){
				int id=st[i][0],l=st[i][1];
				if(l+t<G[id][a]) G[id][a]=l+t,G[a][id]=l+t;
			} 
			st.push_back({a,t});
		}
	}
	up(k,1,m){
		up(i,1,m){
			up(j,1,m){
				if(G[i][k]+G[k][j]<G[i][j]){
					G[i][j]=G[i][k]+G[k][j];
					G[j][i]=G[i][k]+G[k][j];
				}
			}
		}
	}
//	up(i,1,m){
//		up(j,1,m) cout<<setw(4)<<G[i][j];
//		cout<<endl;
//	}
	up(i,1,q){
		int x,y; cin>>x>>y;
		cout<<w[x]+G[x][y]+w[y]<<endl;
	}
	return 0;
}
