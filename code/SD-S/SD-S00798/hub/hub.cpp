#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int a,b;
			cin>>a>>b;
		}
		int m=n/2;
		cout<<m/4-k/4+2<<"\n";
	}
	return 0;
}
