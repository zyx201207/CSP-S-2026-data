#include<bits/stdc++.h>
using namespace std;
long long s[500001];
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
long long qz[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,c,d;
	long long b;
	a=read();
	b=lread();
	for(int v=1;v<=a;++v){
		s[v]=lread();
	}
	sort(s+1,s+a+1);
	for(int v=1;v<=a;++v){
		qz[v]=qz[v-1]+s[v];
	}
	c=1;
	d=0;
	for(int v=1;v<=a;++v){
		while(c<a&&s[c+1]*(c-v+2)-qz[c+1]+qz[v-1]<=b)++c;
		d=max(d,c-v+1);
	}
	cout<<d;
	return 0;
} 