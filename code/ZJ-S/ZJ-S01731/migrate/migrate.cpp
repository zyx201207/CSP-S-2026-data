#include<bits/stdc++.h>
#define int __int128
//#define int long long
using namespace std;
inline int read( ){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
#define rd read()
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>10)write(x/10);
	putchar(x%10+'0');
}
const int N=2e6+5;
int c,T;
int n,d;
int a[N];
struct node{
	int i,v;
};
queue<node>q;
int f[N];
int dp[N];
int mark[N];
int cnt[N];
signed main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	srand((unsigned)time(0));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    c=rd;T=rd;
    while(T--){
    	n=rd;d=rd;while(!q.empty())q.pop();
    	for(int i=1;i<=n;i++)a[i]=rd;
    	for(int i=1;i<=n;i++)f[i]=n;
    	for(int i=1;i<=n;i++){
    		while(!q.empty()&&q.front().v<a[i]){
    			f[q.front().i]=i-1;q.pop();
			}
			q.push((node)<%i,a[i]+d%>);
		}
		for(int i=1;i<=n;i++)dp[i]=0;
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=n-1;i>=1;i--){
			cnt[i]=cnt[f[i]]+1;
		}
		for(int i=n-1;i>=1;i--){
			int R=f[f[i]];
			if(f[i]>=R)continue;
			for(int j=R;j>f[i];j--)mark[j]=0;
			for(int j=f[i]-1;j>i;j--){
		        int L=f[j];
		        if(L==f[i])continue;
				mark[L]++;
		    }
		    for(int j=R-1;j>f[i];j--)mark[j]+=mark[j+1];
		    for(int j=R;j>f[i];j--){
			    if(mark[j]==1){dp[i]++;if(f[j]>f[f[i]]){dp[i]+=cnt[j];}}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans+=dp[i];
		write(ans);putchar('\n');
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/