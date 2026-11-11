#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[10];
int main(){
	freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	cin>>a>>c[1]>>c[2]>>c[3]>>b>>c[4]>>c[5]>>c[6];
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	if(c[1]!=c[4]||c[2]!=c[5]){
		cout<<"1000";
		return 0;
	}
	if(c[3]=='D'||c[3]=='F'){
		if(c[6]=='A'||c[6]=='B'||c[6]=='C')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(c[3]=='A'||c[3]=='B'||c[3]=='C'){
		if(c[6]=='D'||c[6]=='F')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(c[3]+1!=c[6]&&c[6]+1!=c[3]){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}