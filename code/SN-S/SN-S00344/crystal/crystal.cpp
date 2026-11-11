// __       ___________________________________
// \ \     / /____  ____|  _______ \_____  ____|
//  \ \   / /    | |    | |______| |    | |
//   \ \ / /     | |    |         /     | |
//   /  ^ \      | |    |  ______ \     | |
//  / /  \ \     | |    | |______| |    | |
// /_/    \_\    |_|    |_________|     |_|
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define lowbit(x) (x & -x)
#define INF 0x3f3f3f3f3f3f3f3fll
#define inf 0x3f3f3f3f
#define FINF 0xcfcfcfcfcfcfcfcfll
#define finf 0xcfcfcfcf
using namespace std;
const int maxn=1e6+5;
const int maxm=1e6;
const int mod=998244353;
int n,m,t,k;
int a[maxn];
int ans;
signed main()
{
	//°§±ø±ØÊ¤
	freopen("crystal.in","r",stdin);
	freopen("crystal.in","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen("jmcakioi.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=0;
	int sum=0;
	int cnt=1;
	ans=1;
	for(int i=2;i<=n;i++){
		int u=a[i]-a[i-1];
		sum+=cnt*u;
		cnt++;
		while(sum>m&&l<i)sum-=(a[i]-a[l]),cnt--,l++;
		ans=max(ans,cnt);
//		cout<<cnt<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}
