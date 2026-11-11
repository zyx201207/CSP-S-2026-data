#include <bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int a[8];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			a[2]=1;
			if(((s1.substr(2,1)=="A"||s1.substr(2,1)=="B"||s1.substr(2,1)=="C")&&(s2.substr(2,1)=="A"||s2.substr(2,1)=="B"||s2.substr(2,1)=="C"))||((s1.substr(2,1)=="D"||s1.substr(2,1)=="F")&&(s2.substr(2,1)=="D"||s2.substr(2,1)=="F"))){
				a[3]=1;
				if(s1.substr(2,1)=="A"&&s2.substr(2,1)=="B") a[4]=1;
				else if(s1.substr(2,1)=="B"&&s2.substr(2,1)=="A"||s2.substr(2,1)=="C") a[4]=1;
				else if(s1.substr(2,1)=="C"&&s2.substr(2,1)=="B") a[4]=1;
				else if(s1.substr(2,1)=="D"&&s2.substr(2,1)=="F") a[4]=1;
				else if(s1.substr(2,1)=="F"&&s2.substr(2,1)=="D") a[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
} 
