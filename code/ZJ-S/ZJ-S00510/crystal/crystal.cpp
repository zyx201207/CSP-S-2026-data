#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mm,a[500010],ans,sum,kkk,ssum[500010],f[500010];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;mm=m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		for(int i=2;i<=n;++i){
			m=mm,sum=0;
			for(int j=i;j>=1;--j){
				if(m<a[i]-a[j]) break;
				m-=a[i]-a[j],sum++;
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}else{
		memset(f,0x3f3f,sizeof f);f[1]=0;
		int i;
		for(i=2;i<=n;++i){
			if(f[i-1]+(a[i]-a[i-1])*(i-1)>m) break;
			else f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
		}
		cout<<i-1;
	}
	return 0;
}
