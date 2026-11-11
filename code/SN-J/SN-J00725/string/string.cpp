// 刘梓航 西安市铁一中学 SN-J00725 
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define mod 998244353
#define INF 1'000'000'000'000'000'000ll
#define bcstr basic_string
#define i128 __int128
using namespace std;
int n;
int a[200005],b[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],b[i]=a[i];
	int ans=0,p=1,q=n;
	while(p<=n && q>0){
		int t=min(a[p],b[q]);
		ans+=(c[p]!=c[q]?t:0);
		a[p]-=t,b[q]-=t;
		if(a[p]==0) p++;
		if(b[q]==0) q--;
	}
	cout<<(ans>>1);
	return 0;
}
