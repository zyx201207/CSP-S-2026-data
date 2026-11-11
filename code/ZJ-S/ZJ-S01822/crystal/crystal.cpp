#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int k=i-1,s=m,cnt=1;
		bool flag=1;
		while(k>0&&flag){
			s-=a[i]-a[k];
			if(s<a[i]-a[k-1])flag=0;
			cnt++;
			k--;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
