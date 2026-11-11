#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int buf[1<<10];
inline void print(int x,char ch=' '){
	if(x<0) putchar('-'),x=-x;
	int tot=0;
	do{
		buf[++tot]=x%10;
		x/=10;
	}while(x);
	for(int i=tot;i;i--)
		putchar(buf[i]+'0');
	putchar(ch);
}
const int N=2e6+5;
int cid,tid;
int n,d,a[N];
int pre[N],nxt[N];
int dp[N][2];
vector<int> e[N];
int count(int l,int r,int v){
	return upper_bound(e[v].begin(),e[v].end(),r)-lower_bound(e[v].begin(),e[v].end(),l);
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int j=nxt[i],k=nxt[j];
		if(j==k) continue;
		if(pre[k]==j){
			dp[j][0]+=dp[i][0]+1;
			dp[j][1]+=dp[i][1];
		}
		else if(pre[k]==j-1)
			dp[j][1]+=dp[i][0]*(pre[j-1]==i)+1;
		ans+=(dp[i][0]*(pre[j-1]==i)+1)*count(j+1,k,j-1);
		ans+=dp[i][1]*count(j+1,k,j);
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cid=read(),tid=read();
	while(tid--){
		n=read(),d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		
		for(int i=1,l,r;i<=n;i++){
			l=1,r=i;
			while(l<r){
				int mid=(l+r)>>1;
				if(a[i]-a[mid]<=d) r=mid;
				else l=mid+1;
			}
			pre[i]=l;

			l=i,r=n;
			while(l<r){
				int mid=(l+r)>>1;
				if(a[mid+1]-a[i]<=d) l=mid+1;
				else r=mid;
			}
			nxt[i]=r;
		}
		for(int i=1;i<=n;i++){
			dp[i][0]=dp[i][1]=0;
			e[i].clear();
		}
		for(int i=1;i<=n;i++)
			e[pre[i]].push_back(i);
		print(solve(),'\n');
	}
	return 0;
}