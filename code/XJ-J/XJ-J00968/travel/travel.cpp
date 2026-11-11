#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
    string s1,s2,c1,c2,n;
	cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	n += '1';
	}else{
		n += '0';
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		n += '1';
	}else{
		n += '0';
	}
	if((s1[3]!='D' ||s1[3]!='F')&&(s2[3]!='D' ||s2[3]!='F')){
		n += '1';
	}else{
		n += '0';
	}
	cout<<n;
	return 0;
}