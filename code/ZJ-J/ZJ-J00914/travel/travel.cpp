#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	int x1=(s2[0]-'0')*10+s2[1]-'0';
	int x2=(s4[0]-'0')*10+s4[1]-'0';
	bool bo=0;
	if(abs(x2-x1)<=17) {
		cout<<1;
		bo=1;
	}
	//cout<<'\n'<<x1<<' '<<x2<<' '<<abs(s2[2]-s4[2])<<'\n';
	if(bo){
		if(s4[2]>='D' && s2[2]>='D')cout<<1;
		else if(s2[2]<='C' && s4[2]<='C') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(abs(x1-x2)==1 && s2[2]==s4[2]) cout<<1;
	else if(x1==x2 && abs(s2[2]-s4[2])==1) cout<<1;
	else cout<<0;
} 
