#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
mt19937_64 rnd(time(0));
int rand(int l,int r){
	return rnd()%(r-l)+l;
}
void sol() {
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<rand(1,10)<<'\n';
	}
	if(false){
		cout<<"Somewhere,we'll meet again. Hope it'll be my homeward";
	}
	//00000000000000
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sol();
	
	return 0;
}
/*

*/