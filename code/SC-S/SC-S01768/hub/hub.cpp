#include<bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			long long u,v;
			cin>>u>>v;
		}
		cout<<(k+1)/2<<'\n';
	}
	return 0;
} 