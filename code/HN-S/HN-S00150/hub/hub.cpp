#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;
ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}return x*f;}
const int N=2e6+10;
void solve(){
	ll n=read();ll d=read();
	cout<<n/5<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--){
		solve();
	}
	return 0;
} 
/*
0 1
5 4
1 4 5 6 7
*/ 
