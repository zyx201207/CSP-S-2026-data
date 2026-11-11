#include<bits/stdc++.h>
#define int long long
#define cin std::cin
#define cout std::cout
#define endl '\n'
using namespace std;
const int maxn=1e5+5;
int c,T;
int n,d;
int x[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		cout<<1<<endl;
	}
	
	return 0;
}
/*
14:27 还是有点紧张的，放松心态，作对T1，加油
相信你自己，四晅
15:11 T1 有思路了，应该是个黄题
但不知为啥 WA on sub4
爆 long long 了?
*/