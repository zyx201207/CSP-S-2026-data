#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2,s1,s2;
	char k1,k2;
	cin>>c1>>s1>>k1>>c2>>s2>>k2;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(k1>='D'&&k2>='D'){
				cout<<"11";
			}
			else if(k1<='C'&&k2<='C'){
				cout<<1;
				if(abs(k1-k2)<=1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
