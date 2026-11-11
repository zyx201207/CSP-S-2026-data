#include <bits/stdc++.h>
using namespace std;

struct p{
	int n;
	char c;
}s[100000];
long long n,dif = 0,siz = 0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 0;i < n;++i){
		long long t;
		char tmp;
		cin >> t >> tmp;
		s[siz].n = t;
		s[siz++].c = tmp;
	}
	int pi = -1,pj = siz-pi-1;
	while(pi < pj){
		if(s[pi].n <= 0) ++pi;
		if(s[pj].n <= 0) --pj;
		if(pi >= pj) break;
		if(s[pi].c != s[pj].c) ++dif;
		--s[pj].n;
		--s[pi].n;
	}
	cout << dif;
	return 0;
} 
