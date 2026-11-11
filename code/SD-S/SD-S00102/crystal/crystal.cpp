#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+86;
int n,m,ans;
int a[N],cnt[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+a[i];
	}
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<i&&(i-j+1)*a[i]-(cnt[i]-cnt[j-1])>m) j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
3

5 8
-3 -1 2 2 7
4
*/
