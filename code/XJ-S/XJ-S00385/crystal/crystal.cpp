#include <bits/stdc++.h>
using  namespace std;
const long long N=5e5+100;
long long n,m,a[N],ans,cnt,minn,cnt1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=0;
	for (long long i=1;i<=n;i++){
		cnt+=((a[i]-a[i-1])*(i-1-l));
		while (cnt>m && l<i-1){
			ans=max(ans,i-1-l);
			l++;
			cnt-=(a[i]-a[l]);
		}
		minn=min(cnt,m);
		cnt-=minn;
		m-=minn;
	}
	if (ans==0){
		cout<<n;
	}
	else{
		cout<<ans;
	}
	return 0;
}
