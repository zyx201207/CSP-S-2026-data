#include<bits/stdc++.h>
using namespace std;
string a2,b2,k;
int a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	bool f=1;
	if(a2[1]==b2[1]&&a2[0]==b2[0]) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')
	&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')
	||(a2[2]=='D'||a2[2]=='F')
	&&(b2[2]=='D'||b2[2]=='F')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(f&&(a2[2]+1==b2[2]||a2[2]-1==b2[2])) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
