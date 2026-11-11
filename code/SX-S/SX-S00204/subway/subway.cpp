#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;

int C,n,m,d,q;
int h[N],to[N],ne[N],w[N],idx;

void add(int a,int b,int c)
{
	to[idx]=b;
	ne[idx]=h[a];
	w[idx]=c;
	h[a]=idx++;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	
	
	return 0;
}
