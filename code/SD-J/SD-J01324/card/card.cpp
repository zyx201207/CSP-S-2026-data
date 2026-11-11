#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int lst[N],f[N],a[N],n,m,sum[N],pre[N],dp[N],top;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(lst[a[j]]){
				top=lst[a[j]];
			}
			else f[++top]=a[j];
			lst[a[j]]=top;
			
		}
		for(int i=1;i<=top;++i)dp[f[i]]++;
		for(int i=1;i<=m;++i)lst[i]=0;
		top=0;
	}
	for(int i=1;i<=m;++i)cout<<dp[i]<<' ';
//	priority_queue<pair<int,int>>q;
//	q.push({0,N});
//	for(int i=n;i;--i){
//		if(lst[a[i]]){
//			pre[i]=lst[a[i]];
//		}
//		lst[a[i]]=i;
//	}
//	for(int i=0;i<=m;++i)lst[i]=0;
//	for(int i=1;i<=n;++i){
//		lst[pre[i]]=i;
//	}
//	for(int i=1;i<=n;++i){
//		while(!q.empty()&&q.top().second<=i)q.pop();
//		if(lst[i]<=q.top().first)dp[i]=i-q.top().first+dp[lst[i]];
//		else dp[i]=i-q.top().first;
//		if(pre[i])q.push({i,pre[i]});
//		if(pre[i])f[i]=0;
//		else if(lst[i]<=q.top().first)f[i]+=i-q.top().first+dp[lst[i]];
//		else f[i]+=i-q.top().first;
//	}
//	for(int i=1;i<=n;++i){
//		sum[a[i]]+=f[i];
//	}
//	for(int i=1;i<=m;++i){
//		cout<<sum[i]<<' ';
//	}
	return 0;
} 


