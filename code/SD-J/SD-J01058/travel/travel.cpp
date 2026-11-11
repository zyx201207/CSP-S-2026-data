#include<bits/stdc++.h>
using namespace std;
bool a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	string aa,bb;
	aa+=s1[0];aa+=s1[1];bb+=s2[0];bb+=s2[1];
	if(aa!=bb){
		cout<<"1000";
		return 0;
	}
	aa=s1[2];bb=s2[2];
	if(aa=="F"){
		if(bb=="D"){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
		}
	}else if(aa=="D"){
		if(bb=="F"){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1100";
		}
	}
	if("A"<=aa&&aa<="C"){
		if(bb>="D"){
			cout<<"1100";
			return 0;
		}
		if(aa=="A"){
			if(bb=="B"){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1100";
			}
		}
		if(aa=="B"){
			cout<<"1111";
			return 0;
		}
		if(aa=="C"){
			if(bb=="B"){
				cout<<"1111";
				return 0;
			}else{
				cout<<"1100";
			}
		}
	}
	return 0;
} 
