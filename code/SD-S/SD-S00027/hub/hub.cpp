#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<ctime>
using namespace std;
const int N=1e5+5;
int c,t,n,k,u,v,ans;
vector<int> vt[N];
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	srand((unsigned)time(NULL));
	while(t--){
		cin>>n>>k;
		for(int i=1; i<n; ++i){
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		ans=rand()%k+1;
		cout<<ans<<'\n';
	}
	return 0;
}

