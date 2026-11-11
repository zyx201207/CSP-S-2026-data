#include<bits/stdc++.h>
using namespace std;namespace hxyt1{
//#define int ll
#define ll long long
#define U unsigned
#define file(s) freopen(#s ".in","r",stdin),freopen(#s ".out","w",stdout)
#define rad read<int>
#define gc getchar
template<class T>T read(){char c;bool f=0;T x=0;for(;!isdigit(c=gc());f|=c=='-');for(;isdigit(c);x=x*10+c-48,c=gc());return f?-x:x;}
const int N=2e6+5;int n,f[N],g[N],ans;U ll d,a[N];
void hxyt(){
	file(migrate);
	rad();
	for(int _=rad();_--;){
		n=rad(),d=read<ll>();ans=0;
		for(int i=1;i<=n;i++)a[i]=read<ll>();
		memset(f,0x3f,sizeof f);
		for(int s=1;s<=n;s++){
			f[s]=0;
			g[s]=1;
			U ll sum=1;
			for(int i=s+1,j=s,k=s;i<=n;i++){
				for(;j<i&&a[i]-a[j]>d;j++)sum-=g[j];
				for(;k<i&&f[k+1]==f[j];k++)sum+=g[k+1];
				f[i]=f[j]+1;
				g[i]=sum;
			}
			for(int i=s;i<=n;i++)if(g[i]==2)ans++;
		}
		printf("%d\n",ans);
	}
}}signed main(){return hxyt1::hxyt(),0;}


