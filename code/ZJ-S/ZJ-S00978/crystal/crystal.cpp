#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=5*1e5+5;
int n;
LL m,ans,a[maxn],s[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
LL Lread(){
	LL ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=Lread();
	for(int i=1;i<=n;i++) a[i]=Lread();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
	    int L=1,R=i-1,x=-1;
	    while(L<=R){
	    	int mid=(R-L>>1)+L;
	    	if((a[i]*(i-mid)-s[i-1]+s[mid-1])<=m) x=mid,R=mid-1;
	    	else L=mid+1;
		}
		ans=max(ans,(LL)i-x+1);
	}
	printf("%lld",ans);
	return 0;
}