#include<bits/stdc++.h>
using namespace std;
vector<int> v;
const int N=5;
int main(){
	//黎倚睿 SN-J00848 延安市新区第一中学 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,b1,b2;
	char a[N],b[N];
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	cin>>c2;
		for(int i=0;i<3;i++){
		cin>>b[i];
	}
	if(c1==c2) cout<<"1";
	else{
	cout<<"0000";
	return 0;	
	} 
	if(a[1]==b[1]) cout<<"1";
	else{
	 cout<<"000";
	 return 0;	
	}
	if(a[2]>='A' && a[2]<='C' && b[2]>='A' && b[2]<='C') cout<<"1";
	else if(a[2]>='D' && a[2]<='F' && b[2]>='D' && b[2]<='F') cout<<"1";
	else{
	cout<<"00";
	return 0;	
	} 
	if(a[2]+'1'== b[2]+'0' || a[2]-'1'==b[2]+'0') cout<<"1";
	else cout<<"0";
	return 0;
	}
