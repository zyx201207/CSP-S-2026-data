#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t;
ll n,d,a[N];
ll read(){
	ll res=0,f=1;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*f;
}
void write(ll x){
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void solve2(){
	n=read(),d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ll D=a[2]-a[1];
	ll MAX=a[n]-a[1];
	if(d<=D||d>=MAX){
		write(0),putchar('\n');
		return;
	}
	else{
		int Ans=n-(d/D)*2+1;
		if(Ans<0)Ans=0;
		write(Ans),putchar('\n');
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c==11||c==12){
		while(t--)solve2();
	}
	return 0;
}
