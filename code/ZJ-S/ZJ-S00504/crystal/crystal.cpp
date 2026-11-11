#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N];
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int head=1,ans=0;
	for (int i=1;i<=n;i++){
		while (a[i]*(i-head+1)-s[i]+s[head-1]>m){
			head++;
		}
		ans=max(ans,i-head+1);
	}
	cout<<ans<<'\n';
	return 0;
}
