#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){int x = 0,zt = 1;char ch = getchar();while(ch<48||ch>57){if(ch==45)zt = -1;ch = getchar();}while(48<=ch&&ch<=57){x = (x<<3)+(x<<1)+(ch^48);ch = getchar();}return x*zt;}
const int N = 1e6 + 10;
int n,m;
signed main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	n = read();m = read();
	cout<<n+m;
	return 0;
}