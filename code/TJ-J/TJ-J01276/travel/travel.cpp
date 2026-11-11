#include <bits/stdc++.h>
using namespace std;
int a1,a2;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]+c1[1]==c2[0]+c2[1]){
		cout<<1;
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<1;
			if((s1[2]>=65 && s1[2]<=67 && s2[2]>=65 && s2[2]<=67)){
				cout<<8;
				if(abs(s1[2]-s2[2])==1)
					cout<<1;
				else 
					cout<<0;
			}
			else if(s1[2]>=68 && s1[2]<=70 && s2[2]>=68 && s2[2]<=70){
					cout<<1<<1;
			}
			else{
				cout<<0<<0;
				return 0;
			}	
		}
		else{
			cout<<0<<0<<0;
			return 0;
		}
}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	return 0;
} 
