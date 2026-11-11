#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n;
long long m,a[N],ans=0;
long long b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	cin>>n>>m;
	for(long long i=1ll;i<=n;i++) cin>>a[i];
	sort(a+1ll,a+n+1ll);
	for(long long i=1ll;i<=n;i++) b[i]=a[i]+b[i-1];
	
	for(long long l=1ll,r=1ll;l<=n&&r<=n;r++){
		if((r-l+1)*a[r]-(b[r]-b[l-1])>m){
			l++;
			continue;
		}
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
	return 0;
} 
