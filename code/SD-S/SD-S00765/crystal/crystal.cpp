#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N=5e5+10;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	int sum=0,j=n;
	int ans=0;
	for(int i=n;i>=1;i--){
		while(sum<=m&&j>1) j--,sum+=(a[i]-a[j]);
		if(sum>m) sum-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
		while(a[i]==a[i-1]) i--;
		sum-=(a[i]-a[i-1])*(i-1-j+1);
	}
	cout<<ans;
	return 0;
}
