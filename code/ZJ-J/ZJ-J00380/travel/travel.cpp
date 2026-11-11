#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
using namespace std;
const int INF=2e18,N=1e6+10;
int ache,apai,bche,bpai;
char a,b;
signed main(){
	IOS;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
 	cin>>ache>>apai>>a;
 	cin>>bche>>bpai>>b;
 	if(a>=b) swap(a,b);
 	if(ache!=bche){
 		cout<<"0000";
	}
	else if(apai!=bpai){
		cout<<"1000";
	}
	else if((a=='A'&&b=='D')||(a=='A'&&b=='F')||(a=='B'&&b=='D')||(a=='B'&&b=='F')||(a=='C'&&b=='D')||(a=='C'&&b=='F')){
		cout<<"1100";
	}
	else if((a=='A'&&b=='C')){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
} 
