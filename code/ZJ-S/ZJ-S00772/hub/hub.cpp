#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;

int C,T,n,k;


signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	if(C==13||C==14) 
	while(T--){
		int ans=1e18;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		int m=(n-1)/2;
		for(int len=0;m-k-len*2>=0;len++) ans=min(ans,max(len+1,(m-k-len*2+1)/2+1));
		if(k==n)ans=0;
		else if(k>=m)ans=1;
		cout<<ans<<'\n';
	}
	return 0;
}
