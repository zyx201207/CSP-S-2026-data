#include<bits/stdc++.h>
using namespace std;
#define file(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define int ll
#define ll long long
#define rad read<int>
#define gc getchar
template<typename T>T read(){
	T ret=0;bool f=0;char ch;
	for(;!isdigit(ch=gc());f=!f?(ch=='-'):f);
	for(;isdigit(ch);ch=gc())ret=(ret<<3)+(ret<<1)+(ch^48);
	return f?-ret:ret;
}
#define maxn 2000005
int c,t,n,d,s,ans,cnt,x[maxn],jl;
void dfs_wei(int pos,int sum){
	if(pos==s)jl=max(jl,sum);
	int w=-1;
	for(int i=s;i>=pos+1;i--)if(x[i]-x[pos]<=d){w=i;break;}
	if(w!=-1)dfs_wei(w,sum+1);
}
void dfs(int pos,int sum){
	if(pos==s&&sum==jl)ans++;
	for(int i=pos+1;i<=s;i++)if(x[i]-x[pos]<=d)dfs(i,sum+1);else break;
}
signed main(){
	file(migrate);
	c=rad(),t=rad();
	while(t--){
		n=rad(),d=rad(),cnt=0;
		for(int i=1;i<=n;i++)x[i]=rad();
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)if(x[j]-x[i]>d){
			s=j,ans=0,jl=0;
//			printf("%lld %lld:\n",i,j);
			dfs_wei(i,0),dfs(i,0);
			if(ans==2)cnt++;
//			printf(":%lld\n",ans);
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
