#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long op,t;
long long n,k;
vector<long long>v[N];

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		long long x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	long long w=0;
	while(k){
		k=k/10;
		w++;
	}
//	cout<<w<<'\n';
//	cout<<n<<' '<<pow(2,w-1);
	long long ans=(n/pow(2,w-1))+1;
	cout<<ans;
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>op>>t;
	while(t--){
		solve();
	}
	return 0;
}/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
