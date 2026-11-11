#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
string s1,s2;
long long a,b,aa,bb;
int main(){
	fast;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	aa=s1[0]-'0';
	aa*=10;
	aa+=s1[1]-'0';
	bb=s2[0]-'0';
	bb*=10;
	bb+=s2[1]-'0';
	if(aa!=bb){
		cout<<"1000";
		return 0;
	}
	char c1=s1[2],c2=s2[2];
	if((c1=='A'&&c2=='B')||(c1=='A'&&c2=='C')||(c1=='B'&&c2=='C')||(c1=='D'&&c2=='F')||(c2=='A'&&c1=='B')||(c2=='A'&&c1=='C')||(c2=='B'&&c1=='C')||(c2=='D'&&c1=='F')){
		if((c1=='A'&&c2=='C')||(c2=='A'&&c1=='C')){
			cout<<"1110";
		}
		else{
			cout<<"1111";
		}
	}
	else{
		cout<<"1100";
		return 0;
	}
	return 0;
}
