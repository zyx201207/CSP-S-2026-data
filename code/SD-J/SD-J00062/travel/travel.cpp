#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//同一车厢 
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){//同排 
			cout<<1;
			if(s1.substr(2,1)=="A"){
				if(s2.substr(2,1)=="B"||s2.substr(2,1)=="C"){
					cout<<1;
					if(s2.substr(2,1)=="B") cout<<1;
					else cout<<0;
				}else{
					cout<<0;
					cout<<0;
				}
			}else if(s1.substr(2,1)=="B"){
				if(s2.substr(2,1)=="A"||s2.substr(2,1)=="C"){
					cout<<1;
					cout<<1;
				}else{
					cout<<0;
					cout<<0;
				}
			}else if(s1.substr(2,1)=="C"){
				if(s2.substr(2,1)=="A"||s2.substr(2,1)=="B"){
					cout<<1;
					if(s2.substr(2,1)=="B") cout<<1;
					else cout<<0;
				}else{
					cout<<0;
					cout<<0;
				}
			}else if(s1.substr(2,1)=="D"){
				if(s2.substr(2,1)=="F"){
					cout<<1;
					cout<<1;
				}else{
					cout<<0;
					cout<<0;
				}
			}else{
				if(s2.substr(2,1)=="D"){
					cout<<1;
					cout<<1;
				}else{
					cout<<0;
					cout<<0;
				}
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
} 
