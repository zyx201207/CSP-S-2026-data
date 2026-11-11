#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10; 
int n,m,a[N],s[N];
int read(){
	int x=0,f=1;char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	int p=1,ans=0;
	for(int i=1;i<=n;i++)
	a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		while((i-p+1)*a[i]-(s[i]-s[p-1])>m)p++;
		ans=max(ans,i-p+1);
	}
	cout<<ans;return 0;
}
