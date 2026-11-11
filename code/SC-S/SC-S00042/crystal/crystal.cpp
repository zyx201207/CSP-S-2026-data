#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e18;
int n,m,a[500005],b[500005],ans=0;
bool check(int x){
	int tail=0;
	for(int i=1;i<=n;i++){
		if(x>=a[i]) b[++tail]=x-a[i];
	}
	sort(b+1,b+tail+1);
//	for(int i=1;i<=tail;i++){
//		cout<<b[i]<<" ";
//	}
//	cout<<"\n";
	int sum=0;
	for(int i=1;i<=tail;i++){
//		cout<<sum<<" ";
		if(sum+b[i]>m){
			return false;
		}
		sum+=b[i];
		ans=max(ans,i);
	}
//	cout<<"\n";
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=-INF,r=INF;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
