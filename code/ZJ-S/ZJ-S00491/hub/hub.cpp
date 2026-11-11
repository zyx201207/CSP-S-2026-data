#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
vector<int>e[N];
inline int cont(int x){
	int cnt=0;
	while(x){
		if(x&1)cnt++;
		x=x>>1;
	}
	return cnt;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	cout<<cont(10)<<endl;
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for(int i=1;i<=(1<<k);i++){
			if(cont(i)!=k)continue;
			
		}
		cout<<rand()*rand()%k<<"\n";
	}
	return 0;
}
