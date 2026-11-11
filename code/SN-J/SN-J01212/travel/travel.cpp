#include <bits/stdc++.h>
using namespace std;
string c1_g,s1_g,c2_g,s2_g;
string ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1_g>>s1_g>>c2_g>>s2_g;
	
	if(c1_g!=c2_g){
		cout<<"0000\n";
		return 0;
	}
//	cout<<s1_g.substr(0,2);
	if(s1_g.substr(0,2)!=s2_g.substr(0,2)){
		cout<<"1000\n";
	}else{
		string a=s1_g.substr(2),b=s2_g.substr(2);
//		cout<<a<<" "<<b<<"\n";
		if((a>="A"&&a<="C"&&b>="A"&&b<="C")||(a>="D"&a<="F"&&b>="D"&&b<="F")){
			if(abs(a[0]-b[0])==1){
				cout<<"1111\n";
			}else{
				cout<<"1110\n";
			}
		}else{
			cout<<"1100\n";
		}
	}
	return 0;
} 
