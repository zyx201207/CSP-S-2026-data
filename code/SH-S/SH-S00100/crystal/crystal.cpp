#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+3;
int n,m,a[N],s[N];
bool check(int x){
	int minn=m+1;
	for(int i=1,j=x;j<=n;i++,j++)
		minn=min(minn,x*a[j]-s[j]+s[i-1]);
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	int l=2,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
} 
