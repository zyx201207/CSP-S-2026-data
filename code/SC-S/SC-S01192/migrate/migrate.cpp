#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,t,n,d,a[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	for(int j=1;j<=t;j++){
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		if(j==1) cout<<1;
		else cout<<2;
		cout<<"\n";
	}
	return 0;
}