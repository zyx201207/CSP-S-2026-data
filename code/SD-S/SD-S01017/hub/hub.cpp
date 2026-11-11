#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	int n,k;
	int a,b;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			cin>>a>>b;
		}
		cout<<(n+k)/2<<'\n';
	}
	return 0;
}

