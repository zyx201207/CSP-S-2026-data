#include<bits/stdc++.h>
using namespace std;
string a,b;
string s1,s2;
int as1,as2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
	}else{
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			as1=(int)(s1[2]),as2=(int)(s2[2]);
			if((as1<=67&&as2<=67)||(as1>=68&&as2>=68)){
				if((min(as1,as2)==65&&max(as1,as2)==66)||(min(as1,as2)==66&&max(as1,as2)==67)||(min(as1,as2)==68&&max(as1,as2)==70)){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}
	return 0;
}

