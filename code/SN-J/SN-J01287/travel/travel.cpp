#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 != c2) cout<<"0000";
	else{
		string x = s1.substr(0,2);
		string y = s2.substr(0,2);
		if(x!=y) cout<<"1000";
		else{
			char a=s1[2],b=s2[2];
			int f=0;
			if(a>b){
				f=1;
				swap(a,b);
			}
			if(a<='C' && b>='D') cout<<"1100";
			else{
				if(f==1) swap(a,b);
				if(a=='A' && b=='B') cout<<"1111";
				else if(a=='B' && b=='C') cout<<"1111";
				else if(a=='D' && b=='F') cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
} 
