#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n,cmp);
	int l=0,cnt=0;
	for(int i=1;i<n;i++){
		cnt+=(i-l)*(a[i]-a[i-1]);
		while(cnt>m){
			cnt-=(a[i]-a[l]);
			l++;
		}
		ans=max((i-l+1),ans);
	}
	cout<<ans;
	return 0;
}