#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
const int N=2e6+10;
vector<int> G[N];
long long c,t,n,d,xx[N],nxt[N],pre[N],vis[N],ans[N][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>xx[i];
		for(int i=1;i<=n;i++)ans[i][0]=ans[i][1]=0;
		for(int i=1;i<=n;i++)G[i].clear();
		long long pos=1;
		for(int i=1;i<n;i++){
			if(pos<i)pos=i; 
			while(pos<n && xx[pos+1]-xx[i]<=d){
				pos++;
			}
			nxt[i]=pos;
		}
		pos=n;
		for(int i=n;i>1;i--){
			if(pos>i)pos=i;
			while(pos>1 && xx[i]-xx[pos-1]<=d)pos--;
			pre[i]=pos;
		}
		long long cur;
		long long allans=0;
		for(int i=n;i>=1;i--){
			cur=nxt[i];
			if(cur>=n)continue;	
			long long lcur=nxt[cur];
			if(lcur==cur || cur==i)continue;
			long long pos1=upper_bound(xx+cur+1,xx+lcur+1,d+xx[cur-1])-xx;
			ans[i][0]+=lcur-pos1+1;
			pos1=upper_bound(xx+cur+1,xx+lcur+1,d+xx[cur-1])-xx;
			long long pos2=upper_bound(xx+cur+1,xx+lcur+1,d+xx[cur-2])-xx;
			if(pos1-pos2>0)ans[i][1]+=pos1-pos2;
			if(pre[cur-1]!=i)allans+=ans[i][1],ans[i][1]=0;
			if(cur-pre[lcur]==0){
				ans[i][1]+=ans[cur][1];
				ans[i][0]+=ans[cur][0];
			}
			else if(cur-pre[lcur]==1){
				ans[i][1]+=ans[cur][0];
				if(pre[cur-1]!=i)allans+=ans[i][1],ans[i][1]=0;
			}
		}
		for(int i=1;i<=n;i++)allans+=ans[i][1];
		cout<<allans<<'\n';
	}
	return 0;
} 
