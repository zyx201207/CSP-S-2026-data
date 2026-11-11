#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,t,cnt=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1,l=1;i<=n;i++){
		cnt++;
		t+=cnt*(a[i]-a[i-1]);
		if(t>m){
			ans=max(ans,(long long)i-l);
			while(t>m)t-=a[i]-a[l++],cnt--;
		}
	}
	cout<<ans;
	return 0;
}