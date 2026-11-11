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
long long ct[501][501];
int s[500001];
vector<pair<int,int> >cc[500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,f,g;
	long long h;
	read();
	a=read();
	b=read();
	c=read();
	d=read();
	for(int v=1;v<=b;++v){
		s[v]=read();
	}
	for(int v=1;v<=a;++v){
		e=read();
		for(int var=1;var<=e;++var){
			f=read();
			g=read();
			cc[f].push_back({v,g});
		}
	}
	for(int v=1;v<=a;++v){
		for(int var=1;var<=a;++var){
			ct[v][var]=1145141145141919810;
		}
		ct[v][v]=0;
	}
	for(int v=1;v<=b;++v){
		for(pair<int,int> var:cc[v]){
			for(pair<int,int> va:cc[v]){
				ct[var.first][va.first]=min(ct[var.first][va.first],(long long)var.second+va.second);
			}
		}
	}
	for(int v=1;v<=a;++v){
		for(int var=1;var<=a;++var){
			for(int va=1;va<=a;++va){
				ct[var][va]=min(ct[var][va],ct[var][v]+ct[v][va]);
			}
		}
	}
	while(d--){
		e=read();
		f=read();
		h=1145141145141919810;
		if(e==f){
			cout<<s[e]*2<<'\n';
			continue;
		}
		for(pair<int,int> v:cc[e]){
			for(pair<int,int>var:cc[f]){
				h=min(h,v.second+var.second+ct[v.first][var.first]);
			}
		}
		cout<<h+s[e]+s[f]<<'\n';
	}
	return 0;
} 