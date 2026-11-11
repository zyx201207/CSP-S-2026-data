#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
int a[500010],m,n,t[N],diff[500010],l[N],cnt=0;
int sum[500010],ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+diff[i];
		ans[a[i]]+=i;
		diff[i+1]+=(i-sum[i]);
		diff[l[a[i]]+1]-=(i-sum[i]);
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]-=sum[i]; 
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
