#include<bits/stdc++.h>
using namespace std;
const int Maxn=500005;
long long n,m,a[Maxn],cnt,d[Maxn],ans,s[Maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		s[i]=s[i-1]+d[i];
	}
	long long p1=1,p2=1;
	while(p1<=p2&&p2<=n){
		if(cnt<=m){
			cnt+=d[p2+1]*(p2-p1+1);
			ans=max(ans,p2-p1+1);
			p2++;
		}
		else{
			cnt-=(s[p2]-s[p1]);
			p1++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
