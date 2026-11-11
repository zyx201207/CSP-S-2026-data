#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int ch1,ch2,p1,p2;
char c1,c2;
bool tc(){
	if(ch1==ch2&&(c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')) return 1;
	if(ch1==ch2&&(c1=='D'||c1=='F')&&(c2=='D'||c2=='F')) return 1;
	return 0;        
}
bool xl(){
	if(ch1==ch2&&c1=='A'&&c2=='B') return 1;
	if(ch1==ch2&&c1=='B'&&c2=='C') return 1;
	if(ch1==ch2&&c1=='D'&&c2=='F') return 1;
	if(ch1==ch2&&c2=='A'&&c1=='B') return 1;
	if(ch1==ch2&&c2=='B'&&c1=='C') return 1;
	if(ch1==ch2&&c2=='D'&&c1=='F') return 1;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ch1>>p1>>c1>>ch2>>p2>>c2;
	if(ch1==ch2) cout<<1;
	else cout<<0;
	if(ch1==ch2&&p1==p2) cout<<1;
	else cout<<0;
	if(p1==p2&&tc()) cout<<1;
	else cout<<0;
	if(p1==p2&&xl()) cout<<1;
	else cout<<0;
	return 0;
}
