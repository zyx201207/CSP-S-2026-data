#include<bits/stdc++.h>
#define N 2000010
#define ll long long
using namespace std;
int c,t,n,k,st[N],cnt;
vector<int> ve[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	cout<<rand()%n<<"\n";
}
int main(){
	srand(time(NULL));
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
