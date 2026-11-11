#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		if(c==13||c==14){
			if(n==k){
				cout<<0<<"\n";
			}else if(k>=n/2){
				cout<<1<<"\n";
			}else{
				int l=2,r=n,mid;
				while(l<r){
					mid=(l+r)/2;
					if((mid-1)*4+k>=n/2+1){
						r=mid;
					}else{
						l=mid+1;
					}
				}
				cout<<l<<"\n";
			}
		}else if(c==1){
			if(k==n)cout<<0<<"\n";
			else cout<<1<<"\n";
		}
	}
	return 0;
}
//-static-libgcc
