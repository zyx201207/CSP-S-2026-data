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
#define maxn 500005
int n,m,a[maxn],ans,ans1,flg1=1,flg2=1,d;
int p1_n2(){
	for(int k=1;k<=n;k++){
		int L=k-1,R=k+1,sum=m,cnt=1;
//		printf("::%lld %lld %lld\n",L,R,k);
		for(;;){
			if(a[L]>a[k])L=0;if(a[R]>a[k])R=n+1;
			int l=a[k]-a[L],r=a[k]-a[R];
//			printf("%lld %lld %lld %lld %lld\n",L,R,sum,l,r);
			if(sum<l&&sum<r)break;
			if(sum<l&&R>n)break;
			if(L<1&&sum<r)break;
			if(L<1&&R>n)break;
			if(L>=1&&R<=n){if(l>r)R++,cnt++,sum-=r;else L--,cnt++,sum-=l;}
			else if(L<1&&R<=n)R++,cnt++,sum-=r;
			else if(L>=1&&R>n)L--,cnt++,sum-=l;
		}
//		printf("%lld:%lld\n",k,cnt);
		ans1=max(ans1,cnt);
	}
	return ans1;
}
void dfs(int k,int x,int pos,int sum,int nl){
//	printf("%lld %lld %lld %lld\n",x,pos,sum,nl);
	ans=max(ans,sum);
	if(pos>=2&&a[pos-1]<=x&&nl>=(x-a[pos-1])&&pos-1<k)dfs(k,x,pos-1,sum+1,nl-(x-a[pos-1]));
	if(pos< n&&a[pos+1]<=x&&nl>=(x-a[pos+1])&&pos+1>k)dfs(k,x,pos+1,sum+1,nl-(x-a[pos+1]));
}
void solve(){
	for(int i=1;i<=n;i++)/*printf("%lld:\n",i),*/dfs(i,a[i],i,1,m);
	printf("%lld",max(ans,p1_n2()));
}
void p2(){
	for(int i=1;i<=n;i++){if((i+1)*i/2>m)printf("%lld",i),exit(0);}
}
void p3(){
	for(int i=1;i<=n;i++){if((i+1)*i/2*d>m)printf("%lld",i),exit(0);}
}
signed main(){
	file(crystal);
	n=rad(),m=rad(),a[0]=a[n+1]=INT_MIN;
	for(int i=1;i<=n;i++){
		a[i]=rad();//,printf("%lld ",a[i]);
		if(a[i]!=i)flg1=0;
	}
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){if(a[i]-a[i-1]!=d)flg2=0;}
	if(flg1)p2();
	if(flg2)p3();
	solve();
	return 0;
}
