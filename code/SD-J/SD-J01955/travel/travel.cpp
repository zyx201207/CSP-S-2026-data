//I love CCF.
//Please give me more points.
#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;

	if(c1==c2){
		cout<<"1";
		string d1="",d2="";
		for(int i=0;i<s1.size()-1;i++){
			d1+=s1[i];
		}
		for(int i=0;i<s2.size()-1;i++){
			d2+=s2[i]; 
		}
		if(d1==d2){
			cout<<"1";
			if(s1[s1.size()-1]>='A'&&s1[s1.size()-1]<='C'){
				if(s2[s2.size()-1]>='A'&&s2[s2.size()-1]<='C'){
					cout<<"1";
					if(s1[s1.size()-1]-s2[s2.size()-1]==1||s1[s1.size()-1]-s2[s2.size()-1]==-1){
						cout<<"1";
					}
					else{
						cout<<"0";
					}
				}
				else{
					cout<<"00";
				}
			}
			else{
				if(s2[s2.size()-1]>='E'&&s2[s2.size()-1]<='F'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
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
