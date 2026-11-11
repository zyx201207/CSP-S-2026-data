#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int toint(char s){
	return (s-'A'+1);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	mp['A']=0;
	mp['B']=0;
	mp['C']=0;
	mp['D']=1;
	mp['E']=1;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			if(mp[s1[2]]==mp[s2[2]]){
				cout<<"1";
				if(abs(toint(s1[2])-toint(s2[2]))==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}else{
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
