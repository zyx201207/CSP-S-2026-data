#include<bits/stdc++.h>
#define INF (INT_MAX)
#define ll long long
using namespace std;

int TotalTime,c;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	//code area
	cin>>c>>TotalTime;
	for(int ttt=0;ttt<TotalTime;ttt++){
		//ÊäÈë 
		int n, d;
		cin>>n>>d;
		vector<ll> x={};
		x.reserve(n);
		for(int i=0;i<n;i++) {
			ll now=0;
			cin>>now;
			x.push_back(now);
		}
		vector<int> helpvec(n,INF);
		vector<vector<int>> DP(n,helpvec);
		int ans=0;
		for(int from=0;from<n;from++){
			for(int to=from;to<n;to++){
				if(abs(x[from]-x[to])<=d) {DP[from][to]=1;continue;}
				int minlength=INF;
				int cnt=0;
				for(int cent=from;cent<to;cent++){
					if(abs(x[cent]-x[to])<=d){
						if(DP[from][cent]+1<minlength){
							cnt=1;
							minlength=DP[from][cent]+1;
						}else if(DP[from][cent]+1==minlength) cnt++;
					}
				}
				DP[from][to]=minlength;
				if(cnt==2) ans++;
			}
		} 
		cout<<ans<<endl;
	}
	
	return 0;
}

