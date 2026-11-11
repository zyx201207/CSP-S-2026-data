// 刘梓航 西安市铁一中学 SN-J00725 
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define mod 998244353
#define INF 1'000'000'000'000'000'000ll
#define bcstr basic_string
#define i128 __int128
using namespace std;
int n,m;
int a[200005];
bool check(int x){
	int cnt=0;
	for(int i=1;i<=n;i++) if((a[i]&x)==x) cnt++;
	return cnt>=m;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int msk=0;
	for(int i=30;i>=0;i--)
		if(check(msk|(1ll<<i))) msk|=(1ll<<i);
	cout<<msk;
	return 0;
}
