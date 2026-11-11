#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int l=1,r=1;r<=n;++r){
		cnt+=(r-l)*(a[r]-a[r-1]);
		while(m<cnt){
			cnt-=a[r]-a[l];
			++l;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
