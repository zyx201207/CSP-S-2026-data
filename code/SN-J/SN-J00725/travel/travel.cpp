// 刘梓航 西安市铁一中学 SN-J00725 
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define mod 998244353
#define INF 1'000'000'000'000'000'000ll
#define bcstr basic_string
#define i128 __int128
using namespace std;
string sa,sb,ta,tb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>sa>>ta>>sb>>tb;
	int a=ta[0]*1000+ta[1],b=tb[0]*1000+tb[1];
	char ca=ta[2],cb=tb[2];
	int aa=(ca<='C'),bb=(cb<='C');
	cout<<(sa==sb)<<(sa==sb && a==b)<<(sa==sb && a==b && aa==bb)<<(sa==sb && a==b && aa==bb && abs(ca-cb)==1);
	return 0;
}
