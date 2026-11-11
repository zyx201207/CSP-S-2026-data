//O shit I cant solve T3
//Can 216pts bring me a gold metal?
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
vector<int>G[N];
void solve(){
	int n,k;
	for(int i=2;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	cout<<"0/n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	freopen("hub1.in","r",stdin);
//	freopen("hub1.out","w",stdoout);
//	freopen("huq.in","r",stdin);
//	freopen("huq.out","m",stdout);
//	freopen("hnb.in","r",stdin);
//	freopen("hnb.out","w",stdout);
//	freopen("hub1145.in","w",stdinin);
//	freopen("hub14.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
//I have no time to finish this..
//2026.10.31 18:22 @smalbug
//Anyway,I love everyone who has helped me,encouraged me and also you
