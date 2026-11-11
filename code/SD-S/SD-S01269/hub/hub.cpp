#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lowbit(x) ((x)&(-x))
using namespace std;
template<typename T>inline void read(T &n);
// I AK IOI
// 我常常追忆过去。
// The last CSP-S
// OI生涯(2022.9-2026.11.28)
// https://github.com/zshebjtzs 
// 期望得分：60+84+40+0=184 
// T1二分实在调不出来，弃了 
// Oct31==Dec25?
// Ren%Jie^Di&Ling&&&***

int main(){
	ios::sync_with_stdio(0);
//	freopen("debug.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}
template<typename T>inline void read(T &n){
	n=0;T f=1;
	char c;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c<'0'||c>'9');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}

