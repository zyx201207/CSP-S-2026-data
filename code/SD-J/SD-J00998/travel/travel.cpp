#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
const int N=1e6+10,M=1e9+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int f,fl,flag;
signed main(){
	fst;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cf,sf,cs,ss;
	cin>>cf>>sf>>cs>>ss;
	if(cf==cs){
		cout<<1;
	}else{
		f=1;
		cout<<0;
	}
	if(!f){
		for(int i=0;i<=1;i++){
			if(sf[i]!=ss[i]){
				fl=1;
				cout<<0;
				break; 
			}
		}
		if(!fl){
			cout<<1;
		}
	}else{
		cout<<0;
	}
	if(!f&&!fl){
		char a=sf[2];
		char b=ss[2];
		if((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')){
			cout<<1;
		}else if((a=='D'||a=='E')&&(b=='D'||b=='E')){
			cout<<1;
		}else{
			flag=1;
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(!f&&!fl&&!flag){
		char a=sf[2];
		char b=ss[2];
		if((a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='D'&&b=='E')||(a=='E'&&b=='D')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}

