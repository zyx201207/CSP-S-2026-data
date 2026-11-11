#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],pre[500005],lst[300005],dp[500005],ans[300005];
bool nxt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(lst,-1,sizeof(lst));
	cin>>n>>m;
	for (int i=0;i<n;i++){
		dp[i]=1;
	    cin>>a[i];
	    if (lst[a[i]]!=-1){
			pre[i]=lst[a[i]]+1;
			nxt[lst[a[i]]]=1;
		}
		lst[a[i]]=i;
	}
	ans[a[0]]=max(ans[a[0]],dp[0]);
	for (int i=1;i<n;i++){
		if (nxt[i-1]==0)
		  dp[i]+=dp[i-1];
		if (pre[i]!=0)
		  dp[i]+=dp[pre[i]-1];
		ans[a[i]]=max(ans[a[i]],dp[i]);
	}
	for (int i=1;i<=m;i++)
	  cout<<ans[i]<<' ';
	return 0;
}
