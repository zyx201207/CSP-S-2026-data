#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500010],temp[500010],cnt[500010];
int flag;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;++i) cin>>a[i];
	long long d=a[2]-a[1];
	for (int i=2;i<=n;++i){
		if (a[i]-a[i-1]!=d) flag=1;
	}
	if (!flag){
		for (int i=1;i<=n;++i){
			if (i*(i-1)*d/2>m){
				cout<<i-1;
				break;
			}
		}
	}
	else{
		for (int i=1;i<=n;++i) temp[i]=a[i];
		sort(temp+1,temp+n+1);
		long long len=unique(temp+1,temp+n+1)-temp-1;
		for (int i=1;i<=n;++i) {a[i]=lower_bound(temp+1,temp+len+1,a[i])-temp;++cnt[a[i]];}
		for (int i=1;i<=len;++i){
			long long res=0,t=m;
			for (int j=i;j>=1;--j){
				if ((temp[i]-temp[j])*cnt[j]<=t){
					res+=cnt[j];
					t-=(temp[i]-temp[j])*cnt[j];
				}
				else{
					res+=t/(temp[i]-temp[j]);
					break;
				}
			}
			ans=max(ans,res);
		}
		cout<<ans;
	}
} 
