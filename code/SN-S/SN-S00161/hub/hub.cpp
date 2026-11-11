#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,ans;
vector<int> v[1000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		cout<<(n/2-m)/3+1<<"\n";
	}
	return 0;
}

