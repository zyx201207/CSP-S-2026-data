#include<bits/stdc++.h>
#define IOS cin.tie(0)->sync_with_stdio(0)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define DEP(i,a,b) for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define RAP(i,a) for(auto i=(a).begin();i!=(a).end();i++)
#define MOD(a) (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=(mod+(a)+(b))%mod
#define SUB(a,b) (a)=(mod+(a)-(b))%mod
#define MUL(a,b) (a)=(1ll*(a))*((b)%mod)%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define INF 2000000000
using namespace std;
namespace WuJy{
	bool chkin(char x,char y,char l,char r){
		return l<=x&&x<=r&&l<=y&&y<=r;
	}
	void main(){
		string c[2],s[2];
		REP(i,0,1)cin>>c[i]>>s[i];
		if(c[0]!=c[1])return cout<<"0000",void();
		cout<<"1";
		int num[2];
		REP(i,0,1)num[i]=(s[i][0]-'0')*10+s[i][1]-'0';
		if(num[0]!=num[1])return cout<<"000",void();
		cout<<"1";
		if(!chkin(s[0][2],s[1][2],'A','C')&&
		   !chkin(s[0][2],s[1][2],'D','F'))
		   	return cout<<"00",void();
		cout<<"1"<<(abs(s[0][2]-s[1][2])==1);
	}
}
signed main(){
	IOS;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)WuJy::main();
	return 0;
}
