#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
typedef long long L;
string c1,s1,c2,s2;
char mp[10]={0,1,2,3,0,4};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	} else {
		cout<<"0000"; 
		return 0; 
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	} else {
		cout<<"000"; 
		return 0; 
	}
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')
	||(s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')){
	 	cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(mp[s1[2]-'A'+1]==mp[s2[2]-'A']){
		cout<<1;
	}
	else{
		cout<<"0";
	}
	return 0;
}
