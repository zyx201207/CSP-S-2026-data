#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
map<char,bool> ck;
bool check(char l,char r){
	if(l>r)swap(l,r);
	if((l=='D')&&(r=='F')){
		return 1;
	}else if(r-l <= 1){
		return 1;
	}return 0;
}
int main(){
	ck['F']=1;
	ck['D']=1;
	ck['A']=0;
	ck['B']=0;
	ck['C']=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(ck[s1[2]]==ck[s2[2]]){
				cout<<"1";
				if(check(s1[2],s2[2])){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	return 0;
}
