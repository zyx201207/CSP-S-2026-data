#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=stoi(s1),b=stoi(s2);
	c=s1[2],d=s2[2];
	if(c1!=c2){
		ans="0000";
		cout<<ans<<endl;
		return 0;
	}
	else{
		ans+="1";
	}
	if(a!=b){
		ans="1000";
		cout<<ans<<endl;
		return 0;
	}
	else{
		ans+="1";
	}
	if((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C')||(c=='D'||c=='F')&&(d=='D'||d=='F')){
		ans+="1";
	}
	else{
		ans="1100";
		cout<<ans<<endl;
		return 0;
	}
	if((abs(c-d)==1&&(c!='C'&&d!='D')&&(d!='C'||c!='D'))||((c=='D'&&d=='F')||(c=='F'&&d=='D'))){
		ans+="1";
		cout<<ans<<endl;
		return 0;
	}
	else{
		ans="1110";
		cout<<ans<<endl;
	}
	return 0;
} 
