#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=514514,inf=10000007998244353;

int n,m;
int a[N],sum[N];

//希望不要乱码
//OvO
//感觉自己要退役了, coded by binary_carrots , uid = 1350062 (应该没记错吧...)

bool check(int l,int r){
	return (r-l+1)*a[r]-(sum[r]-sum[l-1])<=m;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
//	freopen("test.txt","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=1;
	int ans=0;
	while(r!=n) {
		while(r<n&&check(l,r+1)) r++;
		ans=max(r-l+1,ans);
		l++;
	}
	cout<<ans;
	return 0;
}
//期望得分 144pts
//难受 
//Wo yao shang mi huo xing wei da shang
//我要上迷惑行为大赏 ! 
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
