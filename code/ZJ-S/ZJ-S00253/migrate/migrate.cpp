#include<bits/stdc++.h>
using namespace std;
long long x[2000001];
int read(){
	char w;
	while(w=getchar(),w<'0'||w>'9');
	long long x=w-'0';
	while(w=getchar(),w>='0'&&w<='9')x*=10,x+=w-'0';
	return x;
}
void print(long long gg){
	string str=to_string(gg);
	for(int i=0;i<str.size();++i)putchar(str[i]);
	putchar('\n');
}
int main(){
 	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		long long n=read(),d=read();
		for(int i=1;i<=n;++i){
			x[i]=read();
		}
		if(d>=x[n]-x[1]){
			putchar('0');
			continue;
		}
		long long q=x[n]-x[n-1];
		long long t=d/q;
		if(q==t*d){
			putchar('0');
			putchar('\n');
			continue;
		}
		if(t*2>n){
			putchar('0');
			putchar('\n');
			continue;
		}
			print(n-(t*2));
	}
}
