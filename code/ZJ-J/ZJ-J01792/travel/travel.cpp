#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a1,a2,a3,a4;
	if(c1==c2){
		a1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a2=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				a3=1;
				if(abs(s1[2]-s2[2])==1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
					a4=1;
			}
		}
	}
	cout<<a1<<a2<<a3<<a4;
	return 0;
}//100
