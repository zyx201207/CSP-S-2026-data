#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],op,cnt,ans,ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cnt=1;
	ans=1;
	for(int i=2;i<=n;++i)
	{
		op+=(a[i]-a[i-1])*ans;
		ans++;
		while(op>m)
		{
			op-=a[i]-a[cnt];
			ans--;
			cnt++;
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
