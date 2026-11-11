#include<bits/stdc++.h>
using namespace std;
bool f1,f2,f3,f4;
string c1,s1,c2,s2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
f1=(c1==c2);
f2=(s1[0]==s2[0]&&s1[1]==s2[1]);
f3=(s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C');
f4=(s1[2]-0==s2[2]-1)||(s1[2]-1==s2[2]-0);
if(f1){
	cout<<"1";
	if(f2){
		cout<<"1";
		if(f3){
			cout<<"1";
			if(f4){
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
//🤔🤓😋😡

}
