#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100],sum[500100],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid+1)-sum[i]+sum[mid-1]<=m)r=mid;
			else l=mid+1;
		} 
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
我是上午的SD-J00759，我又来写游记了 
14:30 密码Oct31==Dec25?，这老师还挺有趣味的 
14:31 老师说上午的文件得还在D盘，删了的0分，可我已经删了别人的怎么办
14:32 想出思路，发现上午在这个位置的人不用DEVC++开.in .out .ans，文件被删是他的报应吧
14:40 写完了 
14:43 样例AC 
*/

