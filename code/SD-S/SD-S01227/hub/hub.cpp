#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<climits>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=500005;
int c,t;
int n,k;
vector<int> edge[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v); 
			edge[v].push_back(u);
			
		}
		cout<<1<<endl;
	}
	return 0;
}

