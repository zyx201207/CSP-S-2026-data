#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll res=0ll;
	int f=0,ch;
	do{
		ch=getchar();
		if(ch=='-') f=1;
	}while(!isdigit(ch));
	do{
		res=(res<<1)+(res<<3)+(ch&0xf);
		ch=getchar();
	}while(isdigit(ch));
	return f?-res:res;
}
constexpr int N=5e5+5;
int n,i,ans;
ll m,a[N];
ll sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	ans=i=1;
	ll del;
	for(int j=2;j<=n;++j){
		del=a[j]-a[j-1];
		sum+=del*(j-i);
		while(sum>m&&i<j){
			sum-=a[j]-a[i];
			++i;
		}
		ans=max(ans,j-i+1);
	}
	printf("%d",ans);
	return 0;
}