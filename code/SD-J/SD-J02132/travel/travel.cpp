#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ch1,ch2,ch3,ch4;
	ch1 = s1.substr(0,2),ch2 = s2.substr(0,2);
	ch3 = s1[2],ch4 = s2[2];
	if(c1==c2){
		cout<<1;
		if(ch1==ch2){
			cout<<1;
			if((ch3=="A"&&ch4=="B")||(ch3=="B"&&ch4=="A")||(ch3=="A"&&ch4=="C")||(ch3=="C"&&ch4=="A")||(ch3=="D"&&ch4=="F")||(ch3=="F"&&ch4=="D")||(ch3=="B"&&ch4=="C")||(ch3=="C"&&ch4=="B")){
				cout<<1;
				if((ch3=="A"&&ch4=="B")||(ch3=="B"&&ch4=="A")||(ch3=="D"&&ch4=="F")||(ch3=="F"&&ch4=="D")||(ch3=="B"&&ch4=="C")||(ch3=="C"&&ch4=="B")){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
