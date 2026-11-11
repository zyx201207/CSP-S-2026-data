#include<bits/stdc++.h>
#define int long long
using namespace std;
inline long long read(){
	long long x=0,f=1;
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
int a[500100];
int b[500100];
int c[500100];
int d[500100];
int s[500100];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[a[i]]=i;
		d[i]=1;
	} 
	for(int i=n;i>=1;i--){
		if(b[a[i]]==i) c[i]=i+1;
		else c[i]=b[a[i]]+1;
	}
	for(int i=1;i<=n;i++){
		s[a[i]]+=d[i];
		d[c[i]]+=d[i];
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
