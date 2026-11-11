#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],m;
priority_queue<int>que;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0,tmp=0,anss=0,cnt=0;
	for(int i=1;i<=n;i++){
		ans++;
		while(tmp>m)tmp-=(a[i]-a[++cnt]),ans--;
		anss=max(anss,ans);
		tmp+=(a[i+1]-a[i])*(i-cnt);
	}
	cout<<anss<<'\n';
	return 0;
}
//14:40 thinking end
//14:52 coding&debuging end
