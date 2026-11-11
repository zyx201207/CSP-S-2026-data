#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
    	cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string x=c2.substr(0,2),y=s2.substr(0,2);
	//已判断是在同一车厢
	if(x==y){
	    cout<<"1";
    }else{
    	cout<<"000";
    	return 0;
	}
	//已判断是在同一排 
	string n=c2.substr(2,1),m=s2.substr(2,1);
	if(n!="D"&&n!="F"&&m!="D"&&m!="F"||n!="A"&&n!="B"&&n!="C"&&m!="A"&&m!="B"&&m!="C"){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	//已判断是在同一侧
	if(n=="A"&&m=="C"||n=="C"&&m=="A"){
		cout<<"0";
	} else{
		cout<<"1";
	}
	return 0;
}
