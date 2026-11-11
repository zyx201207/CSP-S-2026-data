#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int n,m;
		n=s1[0]*10+s1[1];
		m=s2[0]*10+s2[1];
		if(n==m){
			cout<<"1";
			if(((s1[2]==65||s1[2]==66||s1[2]==67)&&(s2[2]==65||s2[2]==66||s2[2]==67))||((s1[2]==68||s1[2]==70)&&(s2[2]==68||s2[2]==70))){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else cout<<"0000";
	return 0;	
}
