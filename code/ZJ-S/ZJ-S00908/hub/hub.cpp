#include<bits/stdc++.h>
#define fff(i, a, b) for(ll i = a; i <= b; ++i)

typedef long long ll;
using namespace std;

ll innum(char x){
	return '0'<= x && x <='9';
}
ll read(){
	ll c = getchar(), res = 0, f = 1;
	for(; !innum(c); c = getchar()) if(c =='-') f = -1;
	for(;  innum(c); c = getchar()) res = res * 10 + c -'0';
	return res * f;
}

const ll N = 1000022;
ll lis[N];
ll n;

int main(){
	freopen("hub.in" ,"r", stdin);
	freopen("hub.out","w", stdout);
	n = read();
	ll rp = 0x3f3f3f3f;
	return 0;
}

/*

zhong yu ba ni pian jin lai le ma
ni hao, wo shi k_mod_zero, yi ming gao yi xue sheng
ai~ ke yi kan dao, wo t4 gen ben bu hui
shou xian, bu yao bao kao yong qiang zhong xue
ran hou, I love vocaloid, <<science>>(MIMI) is amazing
ccf xiao shi hou hui jia fa xian di tie bian cheng dan xiang er dao zhi wu fa hui jia
Oct31 == Dec25 ? hao leng de xiao hua [bing] [bing] [bing]
haha wo you dian xiang bu dao gai shuo xie sen me le





feropen("hub.in" ,"r", stdin);

*/

// RNZAF BIE-4+ BIE-4 BIE-4 [38]
// Im k_mod_zero(1412412) , a kards player
