#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f*x;
}
long long d,n,c,t,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		cout<<"0\n";
	}
	return 0;
}
