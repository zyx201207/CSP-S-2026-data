#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<"1";
		string n1="",n2="";
		n1+=s1[0];n1+=s1[1];
		n2+=s2[0];n2+=s2[1];
		if (n1==n2){
			cout<<"1";
			char x1,x2;
			x1=s1[2];x2=s2[2];
			if (((x1>='A' && x1<='C') && (x2>='A' && x2<='C')) || ((x1>='D' && x1<='F') && (x2>='D' && x2<='F'))){
				cout<<"1";
				if ((x1+1==x2)||(x1-1==x2)){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";


	return 0;
}
