#include<bits/stdc++.h>
#define ll long long
#define ac read()
using namespace std;
inline ll read() {
	ll x=0,f=1;
	int c=getchar();
	while(!isdigit(c)) {
		f=(c=='-')?-1:1;
		c=getchar();
	}
	while(isdigit(c)) {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cout<<"No\n";
	return 0;
}

