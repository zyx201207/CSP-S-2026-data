#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin >>c1>>c2;
	string s1;
	string s2;
	if(c1==c2){
		cout <<"1";
	}else{
		cout <<"0";
	}
	if('s1'-'s2'<=6||'s2'-'s1'<=6){
    	cout <<"1"<<" ";
	}else{
    	cout <<"0"<<" ";
	}
	return 0;
}
