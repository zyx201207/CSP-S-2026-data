#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,m;
int a[N];
int ans;

bool check(int k){
	int len=0,x=0;
	for(int i=1;i<=k-1;i++){
		len+=a[i]; 
	}
	for(int i=k;i<=n;i++){
		len+=a[i]; len-=a[i-k];
		x=k*a[i];
		if(m>=abs(x-len)) return 1;
	}
	return 0;
} 

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) {
			ans=max(ans,mid);
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
