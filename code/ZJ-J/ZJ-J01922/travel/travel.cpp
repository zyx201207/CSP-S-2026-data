#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]>='D')){
				if(abs((int)(s1[2]-s2[2]))==1) cout<<"1111"<<endl;
				else cout<<"1110"<<endl;
			}
			else cout<<"1100"<<endl;
		}
		else cout<<"1000"<<endl;
	}
	else cout<<"0000"<<endl;
	return 0;
}
