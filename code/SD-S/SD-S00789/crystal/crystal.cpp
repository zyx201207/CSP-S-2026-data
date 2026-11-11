//Created by Luogu User:951440
#include<bits/stdc++.h>
using namespace std;
int ans;
long long n,m;
long long a[600000];
long long d[600000];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++) {
		d[i]=a[i]-a[i-1];
		d[i]+=d[i-1];
	}
	int l=1;
	long long dis=0;
	for(int i=2; i<=n; i++) {
		dis+=(d[i]-d[i-1])*(i-l);
		while(dis>m && l<=i) {
			dis-=d[i]-d[l];
			l++;
		}
		if(dis<=m)
			ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
//完蛋了呀，眼瞎把加1看成了加减1，浪费我80分钟
