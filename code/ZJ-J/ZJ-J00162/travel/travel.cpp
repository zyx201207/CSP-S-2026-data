#include<bits/stdc++.h>
#define ll long long
using namespace std;

string c1,c2;
char d1,d2,e1,e2,f1,f2;
string ans="";

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>d1>>e1>>f1;
	cin>>c2>>d2>>e2>>f2;
	
//	cout<<c1<<' '<<d1<<' '<<e1<<' '<<f1;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(d1!=d2||e1!=e2){
		cout<<"1000";
		return 0;
	}
	if(min(f1,f2)=='D'){
		cout<<"1111";
		return 0;
	}
	if(max(f1,f2)<='C'){
		if(abs(f1-f2)==1){
			cout<<"1111";
		}
		else cout<<"1110";
	}
	else cout<<"1100";
}
