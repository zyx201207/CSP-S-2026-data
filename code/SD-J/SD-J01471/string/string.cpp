#include <bits/stdc++.h>
using namespace std;
string s;
long long ans = 0,l = 0,n;
inline void put(int num,string ch){
	while(num--)
		s += ch;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		long long x;
		scanf("%lld",&x);
		string ch1;
		cin >> ch1;
		put(x,ch1);
		l += x;
	}
	if(l % 2 == 1){
		string le;
		for(int i = 1;i <= l / 2;i++)
			le[i] = s[i];
		string ri;
		for(int i = l / 2 + 2;i <= l;i++)
			ri[i] = s[i];
		long long cnt = 0;
		for(int i = 1;i <= l / 2;i++)
			if(le[i] != ri[l / 2 - i + 1])
				cnt++;
		printf("%lld\n",cnt);
	}
	else if(l % 2 == 0){
		string le;
		for(int i = 1;i <= l / 2;i++)
			le[i] = s[i];
		string ri;
		for(int i = l / 2 + 1;i <= l;i++)
			ri[i] = s[i];
		long long cnt = 0;
		for(int i = 1;i <= l / 2;i++)
			if(le[i] != ri[l / 2 - i + 1])
				cnt++;
		printf("%lld\n",cnt);
	}

	return 0;
}
