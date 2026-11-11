#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	char a1=s1[0],b1=s1[1],a2=s2[0],b2=s2[1];
	if(a1==a2 && b1==b2){
		cout<<"1";
		if((s1[2]<='C' && s2[2]<='C') || (s1[2]>'C' && s2[2]>'C')){
			cout<<"1";
			if(((s1[2]-s2[2]==1 || s1[2]-s2[2]==-1) && (s1[2]<='C' && s2[2]<='C'))||((s1[2]-s2[2]==2 || s1[2]-s2[2]==-2) && (s1[2]>'C' && s2[2]>'C'))){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
}
