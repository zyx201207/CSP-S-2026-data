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
#define maxn 200005
int n,m,a[maxn],s[maxn],ans,flg=1,fl=1;
void dfs(int i,int j,int sum){
//	printf("%lld %lld %lld\n",i,j,sum);
	if(i==n+1&&j<m)return;
	if(j==m){ans=max(ans,sum);return;}
	dfs(i+1,j,sum);
	dfs(i+1,j+1,sum&a[i]);
}
void solve(){
	for(int i=1;i<=n;i++)ans=max(ans,s[n]&s[i]&s[i-1]);
	printf("%lld",ans);exit(0);
}
void p1(){
	for(int i=1;i<=n;i++)ans=max(ans,a[i]);
	printf("%lld",ans);exit(0);
}
void p2(){
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
	printf("%lld",ans);exit(0);
}
void p3(){
	printf("%lld",n-m);exit(0);
}
bool check(int x){
	for(int i=1;i<=30;i++)if((1<<i)==x)return 1;
	return 0;
}
void p4(){
	sort(a+1,a+1+n);
	printf("%lld",a[n-m+1]);exit(0);
}
void p5(){
	printf("%lld",s[n]);exit(0);
}
signed main(){
	file(and);
	n=rad(),m=rad();
	for(int i=1;i<=n;i++){
		a[i]=rad();
		if(a[i]!=i-1)flg=0;
		if(!check(a[i]+1))fl=0;
	}
	s[1]=a[1];for(int i=2;i<=n;i++)s[i]=s[i-1]&a[i];
	if(m==1)p1();
	if(m==2)p2();
	if(m==n)p5();
	if(m==n-1)solve();
	if(flg)p3();
	if(fl)p4();
	for(int i=1;i<=n-m+1;i++)dfs(i+1,1,a[i]);
	printf("%lld\n",ans);
//	printf("%lld",clock());
//all=1~5(DFS)+6(p1)+7(p5)+8~10(p2)+11~12(solve)+13(p3)+14~15(p4)
	return 0;
}
