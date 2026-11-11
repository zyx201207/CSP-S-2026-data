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
int a[500005],lst[500005];
int pr0[500005],pr1[500005];
int cnt[500005],ans[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],pr0[i]=pr1[i]=0;
	for(int i=1;i<=m;i++) lst[i]=-1;
	for(int i=n;i>0;i--){
		if(lst[a[i]]==-1 && i<n) pr1[i+1]=i;
		else if(lst[a[i]]>0) pr0[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++) cnt[i]=1+cnt[pr0[i]]+cnt[pr1[i]];
	for(int i=1;i<=n;i++) ans[a[i]]+=1+cnt[pr1[i]];
	for(int i=1;i<=m;i++){cout<<ans[i];if(i<m) cout<<' ';}
	return 0;
}
