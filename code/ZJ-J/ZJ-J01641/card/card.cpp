#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
using namespace std;
const int N=5e5+10,M=3e5+10;
int vis[M],cnt[M],a[N],n,m,nxt[N],mp[M],lst[N],cntpre[M],cntsuf[M];
void round(int x){
	for(int i=1;i<=m;i++)vis[i]=0;
	for(int i=x;i<=n;i++){
		if(mp[a[i]]){
			i=mp[a[i]];
			vis[a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++)cnt[i]+=vis[i];
}
void f76(){
	for(int i=1;i<=n;i++)round(i);
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
}
priority_queue<PII,vector<PII>,greater<PII> > l;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]]){
			nxt[mp[a[i]]]=i;
			lst[i]=mp[a[i]];
		}
		mp[a[i]]=i;//mp[i]=last i place
	}
	if(m<=3000)f76();
	else{
		for(int i=1;i<=n;i++){
			while(!l.empty()&&l.top().second<i)l.pop();
			if(!l.empty())cnt[a[i]]+=i+l.top().first;
			else cnt[a[i]]+=i-lst[i];
			if(mp[a[i]]){
				l.push({-i,mp[a[i]]});
			}
		}
		for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	}
	
	return 0;
}
