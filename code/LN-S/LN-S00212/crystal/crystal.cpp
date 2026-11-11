#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],d[N],ans=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		long long cnt=0,k=1;
		for(int j=i-1;j>=1;--j){
			cnt+=(a[i]-a[j]);
			if(cnt>m){
				cnt-=a[i]-a[j];
				break;
			}
			++k;
		}
		ans=max(ans,k);
	}
	cout<<ans;
	return 0;
}
