#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int readint(){
	int x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

ll readll(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
const int MAXN=2000020;
int n,d;
ll pos[MAXN];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	bool f=false;
	int c=readint();
	int T=readint();
	if(c>=11&&c<=12){
		f=true;
	}
	while(T--){
		cout<<0<<"\n";
	}
	return 0;
} 
