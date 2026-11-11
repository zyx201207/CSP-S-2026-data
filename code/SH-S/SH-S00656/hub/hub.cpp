#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,a[100005];
struct NODE{
	int a;
	int b;
}m[100005];
void check(int x){
	
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].b;
	}
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
