#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) s[i]=a[i]-a[i-1];
	ans=s[2];
	for(int i=1;i<=n;i++){
		int cnt=s[i],cmp=0;
		for(int j=i;j>=1;j--){
			cmp++;
			if(cnt>m) break;
			cnt=cnt*2+s[j];
		}
		ans=max(cmp,ans);
	}
	cout << ans;
	return 0;
}