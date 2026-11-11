# include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string s11=s1.substr(0,2);
		string s22=s2.substr(0,2);
		if(s11==s22){
			cout<<"1";
		}
		else{
			cout<<"000";
			return 0;
		}
		s11=s1.substr(2,1);
		s22=s2.substr(2,1);
//		cout<<s11<<" "<<s22;
		if((s11<="C" && s22<="C")){
			cout<<"1";
			if((s11=="A" && s22=="B") || (s11=="B" && s22=="C")){
				cout<<"1";
			}
			else cout<<"0";
		}
		else if((s11=="D" && s22=="F") || (s11=="F" && s22=="D")){
			cout<<"11";
		}
		else cout<<"00";
	}
	else cout<<"0000";
	return 0;
}
