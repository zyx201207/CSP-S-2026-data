#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3fll
#define FINF 0xcfcfcfcfcfcfcfcfll
#define inf 0x3f3f3f3f
#define finf 0xcfcfcfcf
#define lowbit(x) (x & -x)
using namespace std;
const int maxn=2e5+5;
const int maxm=1e6;
const int mod=998244353;
int n,m,t;
string s;
// 10:24
// 555终于来看T2了555
// 我听说luogu有大佬会做迷惑行为大赏，大哥哥可以把我放进去吗qwq
// qwq
// T1好难啊，做了2hqwq
// T2不会啊qwq 
// *******
// 不对好像不能** *** 
// 哦只要拆成两个就行了，那没事了
// ***的*活了 
// 不是谁家好人JT2放S能当T1了啊真的是
// 服了
// 红橙黄？吧可能是
// 也有可能是红红红？
// 其实T4也就是个ABC D，不过我有点唐
// 哎不对是不是暴露串了，算了无所谓了 
// 不对是不是可以全跑一遍除以2啊 

//咋是12点下考
//毁了 
//ffffffffffk
signed main()
{
	//	ios::sync_stdio_with(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string5.in","r",stdin);
//	freopen("jmcakioi.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;char u;
		cin>>k>>u;
		for(int i=1;i<=k;i++)s+=u;
	}
	m=s.length();
	s=" "+s;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m-i+1])t++;
	}
//	cout<<s<<endl; 
	cout<<t<<endl;
	
	return 0;
}

