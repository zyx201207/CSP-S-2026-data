#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
		cout<<"0000";
	else{
		string t1="";
		string t2="";
		t1+=s2[0];t1+=s2[1];
		t2+=s4[0];t2+=s4[1];
		if(t1!=t2)  cout<<"1000";
		else{
			if(s2[2]>='A' && s4[2]<='C'){
				if(s2[2]=='A' && s4[2]=='C' || s2[2]=='C' && s4[2]=='A')
					cout<<"1110";
				else  cout<<"1111";
			}
			else if(s2[2]>='D' && s4[2]<='F')
				cout<<"1111";
			else  cout<<"1100";
		}
	}
	return 0;
}
