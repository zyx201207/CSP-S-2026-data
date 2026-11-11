#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	int sz1=s1.size()-1,sz2=s2.size()-1;
	if(sz1==sz2){
		int i=0;
		bool flag=true;
		while(i<sz1){
			if(s1[i]!=s2[i]){
				flag=false;
				break;
			}
			i++;
		}
		if(!flag){
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"1000";
		return 0;
	}
	if(!(s1[sz1]<='C' && s2[sz2]<='C') && !(s1[sz1]>'C' && s2[sz2]>'C')){
		cout<<"1100";
		return 0;
	}
	if(abs(s1[sz1]-s2[sz2])!=1 || (s1[sz1]=='C' && s2[sz2]=='D') || (s1[sz1]=='D' && s2[sz2]=='C')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}