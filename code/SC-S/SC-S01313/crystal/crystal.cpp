#include<bits/stdc++.h>
using namespace std;
const long long N=500000,M=1e+18;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	} 
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

int n,m;
int cf[N+10];
int a[N+10];
int f[N+10]; 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(); m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1,a+n+1);
	int  cha=a[2]-a[1];
	int num=0,ans=0;
	for(int i=1; i<=n; i++){
		num+=i*cha;
		if(num<=m) ans++;
	}
	printf("%d",ans+1);
	
	return 0;
} 