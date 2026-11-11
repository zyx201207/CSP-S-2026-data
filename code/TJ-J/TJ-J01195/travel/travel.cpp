#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	string c1=s.substr(0,2),c2=s.substr(7,2),s1=s.substr(3,3),s2=s.substr(10);
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if((s1.substr(2)>="A"&&s1.substr(2)<="C"&&s2.substr(2)>="A"&&s2.substr(2)<="C")||(s1.substr(2)>="D"&&s1.substr(2)<="F"&&s2.substr(2)>="D"&&s2.substr(2)<="F")){
				cout<<1;
				string ss=s1.substr(2)+s2.substr(2);
				if(ss[0]>ss[1]) swap(ss[0],ss[1]);
				if(ss=="AB"||ss=="BC"||ss=="DF"){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
