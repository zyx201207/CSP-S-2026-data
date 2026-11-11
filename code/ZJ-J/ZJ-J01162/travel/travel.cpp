#include<bits/stdc++.h>
//#define int long long
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		string x,y,e,f;
		x+=b[0],y+=d[0],e+=b[2],f+=d[2];
		x+=b[1],y+=d[1];
		if(x==y){
			cout<<"1";
			if(("A"<=e&&e<="C"&&"A"<=f&&f<="C")||("D"<=e&&e<="F"&&"D"<=f&&f<="F")){
				cout<<"1";
				if((e=="A"&&f=="B")||(e=="B"&&f=="C")||(e=="B"&&f=="A")||(e=="C"&&f=="B")||(e=="D"&&f=="F")||(e=="F"&&f=="D")){
					cout<<"1";
				}
				else cout<<"0";
			}
			else {
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

