#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
vector<int>v[2000005];
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(n==k)cout<<0<<"\n";
		else if(n==k+1)cout<<1<<"\n";
		else if(n>=k+2)cout<<2<<"\n";
	}
	return 0;
}
