#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=500005;
LL n,m,a[maxn],ans;
LL read(){
	LL num=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	LL L=1,R=1,sum=a[1];
	while(L<=n && R<=n){
		ans=max(ans,R-L+1);
		R++,sum+=a[R];
		while(a[R]*(R-L+1)-sum>m)L++,sum-=a[L-1];
	}
	cout<<ans;
	return 0;
}