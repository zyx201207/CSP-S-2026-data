#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	bool a=0,b=0;
	if(s1[2]=='D'||s2[2]=='D'){
		a=1;
	}
	if(s1[2]=='F'||s2[2]=='F'){
		b=1;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(!(a^b))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(!(a^b))&&((abs(char(s1[2]-s2[2]))==1)||(a&&b))){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
