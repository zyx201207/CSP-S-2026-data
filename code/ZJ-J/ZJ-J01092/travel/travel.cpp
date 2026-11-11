#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(!(c1==c2)){
		cout<<"0000\n";
	}else{
		cout<<"1";
		if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
			cout<<"000\n";
		}else{
			cout<<"1";
			if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))){
				cout<<"00\n";
			}else{
				cout<<"1";
				if(!((((char)(s1[2]+1)==s2[2])||((char)(s2[2]+1)==s1[2]))&&(!(s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'||s2[2]=='C')))){
					cout<<"0\n";
				}else{
					cout<<"1\n";
				}
			}
		}
	}
	return 0;
}
