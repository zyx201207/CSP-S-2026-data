#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int C,n,m,d,Q;
int c[514514];
int mp[514][514];
int e[5][514514];
vector<pair<int,int> >zd[514514];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>c[i];
	for(int i=1,len;i<=n;i++){
		cin>>len;
		for(int j=1,v,w;j<=len;j++){
			cin>>v>>w;
			if(20<=C and C<=21) e[i][v]=w;
			zd[v].push_back(make_pair(i,w));
		}
		for(int j=1;j<=n;j++) mp[i][j]=1e12;
		mp[i][i]=0;
	}
	if(20<=C and C<=21){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=m;k++){
					mp[i][j]=mp[j][i]=min(mp[i][j],e[i][k]+e[j][k]);
				}
			}
		}
	}
	else{
		for(int i=1;i<=m;i++){
			for(int j=0;j<zd[i].size()-1;j++){
				for(int k=j+1;k<zd[i].size();k++){
					int u=zd[i][j].first,v=zd[i][k].first;
					int w=zd[i][j].second+zd[i][k].second;
					mp[u][v]=mp[v][u]=min(mp[u][v],w);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			int t=mp[i][k];
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],t+mp[k][j]);
			}
		}
	}
	for(int i=1,x,y,ans;i<=Q;i++){
		cin>>x>>y;
		ans=1e18;
		for(int j=0;j<zd[x].size();j++){
			for(int k=0;k<zd[y].size();k++){
				int u=zd[x][j].first,v=zd[y][k].first;
				int wq=zd[x][j].second,wp=zd[y][k].second;
				ans=min(ans,wq+wp+mp[u][v]);
			}
		}
		cout<<c[x]+ans+c[y]<<endl;
	}
	return 0;
}
//m*d^2=200000000
//  n^3=125000000
// q*d^2=40000000
//
//1~3 m*d^2+n^3+q*d^2
//4~6 m*d^2+n^3+q*d^2
//7~8 m*d^2+n^3+q*d^2
//9~11 m*d^2+n^3+q*d^2
//
//400000


//53min;
//O(m*d^2+n^3+q*d^2)looks wrong,but it passed every sample
//I just solve T2? Unbelievable!
//63min
//added task20 and task21, I'm going to T3
//least 40,most 100pts
