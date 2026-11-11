#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1;
	cin>>c1;
	char s11,s12,s13;
	cin>>s11>>s12>>s13;
	int c2;
	cin>>c2;
	char s21,s22,s23;
	cin>>s21>>s22>>s23;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	int a,b;
	a=(s11-'0')*10+(s12-'0');
	b=(s21-'0')*10+(s22-'0');
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	if(s13=='D' || s13=='F') a=2;
	else a=1;
	if(s23=='D' || s23=='F') b=2;
	else b=1;
	if(b!=a){
		cout<<"1100";
		return 0;
	} 
	if(a!=2){
		if((s13=='C' && s23=='A')||(s23=='C' && s13=='A')){
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	return 0;
}
