#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
int n,a[N],m,mx,ans,t,cf[35],nw;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}cf[0]=1;
	for(int i=1;i<=30;i++){
		cf[i]=cf[i-1]*2;
	}nw=30;
	while(cf[nw]>mx)nw--;
	while(nw>=0){
		t=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=cf[nw]){
				t++;
			}
		}
		if(t>=m){
			ans+=cf[nw];
			for(int i=1;i<=n;i++){
				if(a[i]>=cf[nw]){
					a[i]-=cf[nw];
				}else{
					a[i]=0;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]>=cf[nw]){
					a[i]-=cf[nw];
				}
			}
		}nw--;
	}cout<<ans;
	return 0;
}
