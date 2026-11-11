#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long n,m,a[N],ans=1,c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		c[i]+=c[i-1];
	}
	long long l=1,r=2,cnt=0;
	cnt=c[r]-c[l];
	while(r<=n){
		//cout<<cnt<<' '<<l<<" "<<r<<'\n';
		if(cnt<=m){
			ans=max(ans,r-l+1);
			cnt+=(r-l+1)*(c[r+1]-c[r]);
			r++;
		}
		else{
			cnt-=c[r]-c[l];
			l++;	
		}
	}
	cout<<ans<<'\n';
	return 0;
}
