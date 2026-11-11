#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc_ getchar()
inline int read(){
	int x=0,f=1;char ch=gc_;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc_;}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc_;}
	return x*f;
}
int c,n,m,d,T,wa[500005];
vector<pair<int,int> > s[500005];
int x,y,dp[500005];
bool b[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();T=read();
	for(int i=1;i<=m;i++){
		wa[i]=read();
	}
	
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int idx=read(),v=read();
			s[idx].push_back(make_pair(m+i,v));
			s[m+i].push_back(make_pair(idx,v));
		}
	}
//	cout<<" q "<<endl;
	while(T--){
		x=read(),y=read();
		memset(dp,0x3f3f,sizeof(dp));
		queue<int> q;
		q.push(x);
		dp[x]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<s[u].size();i++){
				if(u==y)break;
				if(dp[s[u][i].first]>dp[u]+s[u][i].second){
					dp[s[u][i].first]=dp[u]+s[u][i].second;
					q.push(s[u][i].first);
				}   
			}
		}
		cout<<dp[y]+wa[x]+wa[y]<<endl;
	}
	return 0;
} 
/*
我-作为一名oier，已经没有什么事情可以让我睁眼了；
q-第二题没思路； 
我-没事，多想一会儿；
q-（一小时后）暴力骗分来；
我-纳尼？！ 
*/
