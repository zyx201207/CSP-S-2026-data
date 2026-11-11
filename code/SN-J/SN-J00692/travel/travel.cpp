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
int n,m,t,x,y;
char a,b;
int h=0;
map<char,int>mp;
signed main()
{
	//	ios::sync_stdio_with(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=1;mp['B']=2;mp['C']=3;mp['D']=4;mp['F']=5;
	scanf("%lld %lld%c %lld %lld%c",&n,&x,&a,&m,&y,&b);
//	cout<<n<<" "<<x<<" "<<a<<" "<<m<<" "<<y<<" "<<b<<" ";
	if(n==m){
		cout<<1;
	}
	else {
		cout<<"0000"<<endl;
		return 0;
	}
	if(x==y){
		cout<<1;
	}
	else {
		cout<<"000"<<endl;
		return 0;
	}
	int u=mp[a];int v=mp[b];
//	cout<<u<<" "<<v<<endl;
	if((u<=3&&v<=3)||(u>3&&v>3))cout<<1,h=1;
	else cout<<0,h=0;
	if(h){
		cout<<(abs(u-v)<=1);
	}
	else {
		cout<<0;
	}
	
	return 0;
}

