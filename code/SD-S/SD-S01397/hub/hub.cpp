#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,ans,u[1000005],v[1000005];
bool check(int mid){
	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	int l=1,r=n,mid=l+(r-l)/2;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		while(l<=r){
			if(check(mid)){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}		
		}
		cout<<ans<<"\n";
	}
	return 0;
}
