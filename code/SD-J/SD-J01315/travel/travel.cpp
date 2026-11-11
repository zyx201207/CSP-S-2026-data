#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int a1=(s1[0]-48)*10+(s1[1]-48),a2=(s2[0]-48)*10+(s2[1]-48);
	int b1=s1[2],b2=s2[2];
	if(c1==c2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if((b1<=67&&b2<=67)||(b1>=68&&b1<=69)&&(b2>=68&&b2<=69)){
				cout<<1;
				if((s1[2]=='C'&&s2[2]=='A')||(s2[2]=='C'&&s1[2]=='A')) cout<<"0";
				else cout<<1;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
