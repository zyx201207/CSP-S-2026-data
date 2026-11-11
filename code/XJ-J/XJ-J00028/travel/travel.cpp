#include<bits/stdc++.h>
using namespace std;
bool o(string a,string b){
	//
	if((a=="D" && b=="F")||(a=="F" && b=="D")){
		return true;
	}
	if((a=="A"&&b=="B")
	||(a=="A"&&b=="C")
	||(a=="B"&&b=="C")
	||(b=="A"&&a=="B")
	||(b=="A"&&a=="C")
	||(b=="B"&&a=="C")){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,c1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2) cout<<1;
	else cout<<0;
	//2
	string r1=s1.substr(0,2),r2=s2.substr(0,2);
	bool ok=false;
	if(r1==r2 && c1==c2){
		ok=true;
		cout<<1;
	}else{
		cout<<0;
	}
	//3
	string idx1=s1.substr(2,1),idx2=s2.substr(2,1);
//	cout<<idx1<<" "<<idx2;
//	string op1="ABC",op2="DF";
	if(o(idx1,idx2) && ok && c1==c2){
		cout<<1;
	}else cout<<0;
	//4
	if(((idx1=="A"&&idx2=="B")
	 ||(idx1=="B"&&idx2=="C")
	 ||(idx1=="B"&&idx2=="A")
	 ||(idx1=="C"&&idx2=="B")
	 ||(idx1=="D"&&idx2=="F")
	 ||(idx1=="F"&&idx2=="D")) && ok && c1==c2){
		cout<<1;
	}else cout<<0;
	return 0;
}
