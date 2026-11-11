#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n;
		for(int i=1;i<=n-1;i++){
			int a,b;
			cin>>a>>b;
		}
		if(k==n-1 || k==n-2) cout<<1<<"\n";
		else cout<<(n-k)/3<<"\n";
	}
	return 0;
}

