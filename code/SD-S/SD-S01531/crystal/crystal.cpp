#include<bits/stdc++.h>
using namespace std;
const long long N=500010;
long long ans=1;
long long n,m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	long long l=1;
	for(int i=1;i<=n;i++){
		while(b[i]-b[l-1]+m<a[i]*(i-l+1)) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
} 
