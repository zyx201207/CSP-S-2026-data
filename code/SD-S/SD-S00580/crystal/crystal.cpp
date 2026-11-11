#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

int n,m;
long long a[N];
long long b[N];
int ans=1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	b[1]=a[2]-a[1];
	for(int i=2;i<=n;i++) {
		int l=0,r=i-1,res;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(b[i-1]-b[mid]-1ll*mid*(a[i]-a[mid+1])<=m) {
				r=mid-1;
				res=i-mid;
			} else l=mid+1;
			
		}
		ans=max(ans,res);
		b[i]=b[i-1]+1ll*i*(a[i+1]-a[i]);
	}
	cout<<ans;	
	return 0;
} 
