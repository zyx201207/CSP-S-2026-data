#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],f[2000010];
long long read(){
	long long s=0,b=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s*b;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		long long cnt=0;
		n=read();
		d=read();
		for(int i=1;i<=n;i++)cin>>a[i];
		f[1]=1;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1&&a[i]-a[j]<=d;j--)if(a[i]-a[j]>t/2)f[i]+=f[j];
			if(f[i]==2)cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
