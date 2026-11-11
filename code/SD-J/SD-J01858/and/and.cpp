#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,ans,R;
int a[N];
int check(int x){
	int cnt=0;
	for(int i=n;i>=1;i--){
		if(x&a[i]>=x) cnt++;
		if(cnt>=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=a[n];
	while(l<=r){
		int mid=(l+r)>>1;
		ans=mid;
		if(check(mid)){
			l=mid+1;
			
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
