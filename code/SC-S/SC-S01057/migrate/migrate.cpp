#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
long long lread(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int gs1[2000001];
int gs2[2000001];
long long s[2000001];
int xg[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,d,e,f,g;
	long long c;
	long long da;
	read();
	a=read();
	while(a--){
		b=read();
		c=lread();
		for(int v=1;v<=b;++v){
			s[v]=lread();
			gs1[v]=0;
			gs2[v]=0;
		}
		d=1;
		for(int v=1;v<=b;++v){
			while(d<b&&s[d+1]-s[v]<=c){
				++d;
			}
			xg[v]=d;
		}
		d=1;
		for(int v=1;v<=b;++v){
			while(d<b&&s[d+1]-s[v]<=c)++d;
			if(d==v)continue;
			++gs1[d];
			if(v==1||s[d]-s[v-1]>c){
				gs1[d]=gs1[d]+gs1[v];
			}
		}
		d=b;
		for(int v=b;v;--v){
			while(d>1&&s[v]-s[d-1]<=c)--d;
			if(d==v)continue;
			++gs2[d];
			if(v==b||s[v+1]-s[d]>c){
				gs2[d]=gs2[d]+gs2[v];
			}
		}
		d=1;
		e=1;
		da=0;
		for(int v=1;v<=b;++v){
			++gs1[v];
			++gs2[v];
		}
		for(int v=1;v<=b;++v){
			if(xg[v]<=v+1)continue;
			while(d<=b&&s[d]-s[xg[v]-2]<=c)++d;
			while(e<b&&s[e+1]-s[xg[v]-1]<=c)++e;
			if(d>e)continue;
			if(v==1||s[xg[v]-1]-s[v-1]>c){
				if(e==b||s[e+1]-s[xg[v]]>c){
					da=da+(long long)gs2[e]*gs1[v]+(long long)gs1[v]*(e-d);
				}
				else{
					da=da+(long long)gs1[v]*(e-d+1);
				}
			}
			else{
				if(e==b||s[e+1]-s[xg[v]]>c){
					da=da+gs2[e]+(e-d);
				}
				else{
					da=da+(e-d+1);
				}
			}
		}
		cout<<da<<'\n';
	}
	return 0;
} 