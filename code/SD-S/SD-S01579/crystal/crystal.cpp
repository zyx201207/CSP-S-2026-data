#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
map<int,int> ma;
int n,m,d,ans;
inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
int f(int x){
	int sum=ma[a[x]],e=m;
	for(int i=x-1;i>=1;i--){
		int v=a[x]-a[i];
		if(e>ma[a[i]]*v)sum+=ma[a[i]],e-=ma[a[i]]*v;
		else{sum+=e/v;break;}
	}
	return sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)ma[a[i]]++;
	d=unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=d;i++)ans=max(ans,f(i));
	cout<<ans;
	return 0;
}
