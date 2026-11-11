#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500005;
ll m,a[maxn],f[maxn],ans=1,l=0,sum=0,num=0,n;
inline ll read(){
	ll ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) f[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++){
		sum+=f[i-1]*(i-l-1);
		num+=f[i-1];
		while(sum>m&&l<i-1){
			sum-=num;
			num-=f[l];
			l++;
		}
		ans=max(ans,i-l);
	}
	printf("%lld\n",ans);
	return 0;
}