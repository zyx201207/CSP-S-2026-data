#include<bits/stdc++.h>
using namespace std;
using ll=long long;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s2[1]==s1[1]){
			cout<<"1";
			ll t1,t2;
			t1=s1[2]-'A';
			t2=s2[2]-'A';
			if((t1>=0&&t1<=2&&t2>=0&&t2<=2)||(t1>=3&&t1<=5&&t2>=3&&t2<=5)){
				cout<<"1";
				if((t1>=0&&t1<=2&&t2>=0&&t2<=2&&abs(t1-t2)==1)||(t1==3&&t2==5)||(t1==5&&t2==3)){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
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
