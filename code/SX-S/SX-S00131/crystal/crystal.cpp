#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,a[500005],ans=2;
signed main(){
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	sort(a+1,a+n+1);
	int t=1;
	while(m-=t){
		ans++;
		t++;
	}
	cout<<ans;
	return 0;
}
