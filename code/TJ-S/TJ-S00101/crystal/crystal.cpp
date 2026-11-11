#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int n;
long long m,a[N],s[N],tans;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i],a[i]+=1e12;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=1,r=i,ans=1;
		while(l<=r){
			long long mid=(l+r)>>1;
			long long val=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(val<=m)ans=i-mid+1,r=mid-1;
			else l=mid+1;
		}
		tans=max(tans,ans);
	}
	cout<<tans;
	return 0;
}

