#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f1=0,f2=0,f3=0,f4=0;
	if(c1==c2){
		f1=1;
		cout<<1;
	}else cout<<0;
	if(f1&&s1.substr(0,2)==s2.substr(0,2)){
		f2=1;
		cout<<1;
	}else cout<<0;
	if(f1&&f2&&((s1.substr(2,1)<="C"&&s2.substr(2,1)<="C")||(s1.substr(2,1)>"C"&&s2.substr(2,1)>"C"))){
		f3=1;
		cout<<1;
	}else cout<<0;
	if(s1.substr(2,1)=="B"||s1.substr(2,1)=="D"||s1.substr(2,1)=="F") f4=1;
	if(s2.substr(2,1)=="B"||s2.substr(2,1)=="D"||s2.substr(2,1)=="F") f4=1;
	if(f1&&f2&&f3&&f4){
		cout<<1;
	}else cout<<0;
	return 0;
}
