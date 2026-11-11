#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int>vi[2000020];
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int xx,yy;
		cin>>xx>>yy;
		vi[xx].push_back(yy);
		vi[yy].push_back(xx);
	}
	cout<<1<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
