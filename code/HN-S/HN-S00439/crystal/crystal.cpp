#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int maxn=1;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int p=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(s[i]-s[mid-1]+m>=(i-mid+1)*a[i]){
				p=min(p,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		maxn=max(maxn,i-p+1);
	}
	cout<<maxn;
	return 0;
} 
