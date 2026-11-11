#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,ma,s,sum=0,cnt=0,ans,m,a[N],t[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		long long cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&(1<<i))){
				t[++cnt]=a[j];
			}
		}
		if(cnt>=m){
			ans=ans+(1<<i);
			for(int j=1;j<=cnt;j++) a[j]=t[j];
			n=cnt;
		}
	}
	cout<<ans;
	return 0;
}