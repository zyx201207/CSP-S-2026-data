#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
/*
如果刚好有两条最短路径，那么就是答案 
值域是1e18
dp，从前面能飞过来的挑最短的飞，并且记录能到达这个点的方案数 
On^3
优化到n^2，要维护一个动态区间 
记录区间内dp值，dp存储两个值，最小次数，多少情况 
双指针 
特殊性质A 
48pts
*/
const int N=2e6+5;
int c,T;
int n,d;
int a[N],t[N];
pii f[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		if(c==11||c==12){
			int p=a[2]-a[1];
			if(d<p*2)cout<<0<<"\n";
			else cout<<max(n-(d/p*2-1),0ll)<<"\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++)f[j]={0,0},t[j]=0;
			f[i]={0,1};
			int l=i,r=i;
			priority_queue<int,vector<int>,greater<int> >mi;
			mi.push(0);
			t[0]++;
			for(int j=i+1;j<=n;j++){
				while(l<=r&&a[l]+d<a[j]){
					t[f[l].first]-=f[l].second;
					l++;
				}
				while(!mi.empty()&&t[mi.top()]==0)mi.pop();
				if(mi.empty())break;
				f[j]={mi.top()+1,t[mi.top()]};
				r++;
				if(t[f[r].first]==0)mi.push(f[r].first);
				t[f[r].first]+=f[r].second;
				if(f[r].second==2)ans++;
//				cout<<i<<" "<<r<<":"<<f[r].first<<" "<<f[r].second<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
