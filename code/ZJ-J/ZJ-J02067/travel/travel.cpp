#include<bits/stdc++.h>
using namespace std;
string a,b,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>sa>>b>>sb;
	if(a!=b)cout<<"0000";
	else{
		cout<<'1';
		if(sa[0]!=sb[0]||sa[1]!=sb[1])cout<<"000";
		else{
			cout<<'1';
			if((sa[2]<='C'&&sb[2]>='D')||(sa[2]>='D'&&sb[2]<='C'))cout<<"00";
			else{
				cout<<'1';
				if(sa[2]==sb[2]+1||sa[2]==sb[2]-1)cout<<'1';
				else{
					cout<<'0';
				}
			}
		}
	}
	return 0;
}
