#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
const int maxn=2e5+10;
int lowbit(int x){ return x&-x;}
bool b1[maxn][35];
bool used[maxn];
int a[maxn],b[maxn];
int cnt[40];
int bt(int c)
{
	int cnt=0;
	while (c){
		c/=2;
		cnt++;
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	memset(b1,0,sizeof(b1));
	memset(used,0,sizeof(used));
	for (int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for (int i=n;i>=1;i--){
		while (a[i]){
			int lb=lowbit(a[i]);
			b1[i][bt(lb)]=1;
			cnt[bt(lb)]++;
			a[i]-=lb;
		}
	}
	int ans=2147483647,cnt1=0;
	for (int i=31;i>=1;i--){
		if (cnt[i]<m) continue;
		for (int j=n;j>=1;j--){
			if (cnt1==m||used[j]) continue;
			if (b1[j][i]) ans&=b[j];
			else continue;
			cnt1++; used[j]=1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
