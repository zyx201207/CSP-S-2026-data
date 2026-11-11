#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			int bb=b[2],dd=d[2];
			if((bb=='A'&&dd=='B')||(bb=='A'&&dd=='C')||(bb=='B'&&dd=='C')||(bb=='D'&&dd=='F')||(bb=='B'&&dd=='A')||(bb=='C'&&dd=='A')||(bb=='C'&&dd=='B')||(bb=='F'&&dd=='D')){
				if((bb=='A'&&dd=='B')||(bb=='B'&&dd=='C')||(bb=='D'&&dd=='F')||(bb=='B'&&dd=='A')||(bb=='C'&&dd=='B')||(bb=='F'&&dd=='D'))cout<<"1111";
				else cout<<"1110";
			}else{
				cout<<"1100";
			}
		}else cout<<"1000";
	}else {
		cout<<"0000";
	}
	return 0;
}
