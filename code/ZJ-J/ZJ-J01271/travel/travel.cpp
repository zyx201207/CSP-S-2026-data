#include<bits/stdc++.h>
using namespace std;
int c1,c2,p[131];
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	p['A']=p['B']=p['C']=1;
	p['D']=p['F']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1.substr(0,s1.size()-1)==s2.substr(0,s2.size()-1)){
			if(p[s1[s1.size()-1]]==p[s2[s2.size()-1]]){
				if(p[s1[s1.size()-1]]==2||abs(s1[s1.size()-1]-s2[s2.size()-1])==1){
					cout<<"1111";
				}else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
