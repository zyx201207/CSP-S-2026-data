#include<bits/stdc++.h>
using namespace std;
int C,T,n,k,u,v;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v;
		int m=(n-1)/2;
		if(k==n) cout<<0<<'\n';
		else if(k>=m) cout<<1<<'\n';
		else if(k==1) cout<<(m+1)/2;
		else{
			m+=1;
			int z=(m+1)/2;
			int y=(z+1)/2;
			cout<<y-k/4+1<<'\n';
		}
	}
	return 0;
}
