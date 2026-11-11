#include<bits/stdc++.h>
using namespace std;
long long n,m,q,l,r,w,ans,mod,a[508888],s[508888];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	    l=1,r=i,w=i;
		while(l<r){
			mod=l+(r-l)/2;
//			if(a[i]*(s[i]-l)<=m&&(s[i]-l<=m)) l=mod;
            if( ( (w-mod+1)*a[w])>(m+s[w]-s[mod-1]) ) l=mod+1;
			else r=mod;
		}
		q=i-l+1;
		ans=max(ans,q);
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
