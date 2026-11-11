#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,b1,b2;
char ans[4];

int fl=1,fl2=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]) fl=0;
	}

	if(fl==0){
		for(int i=0;i<4;i++){
			ans[i]='0';
		}
		cout<<ans;
		return 0;
		}
	else ans[0]='1';
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]) fl=0;
	}

	if(fl==0){
		for(int i=1;i<4;i++){
			ans[i]='0';
		}
		cout<<ans;
		return 0;
		}
		else ans[1]='1';
		if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D') ans[2]='1';
		else{
			ans[2]='0';
			ans[3]='0';
			cout<<ans;
			return 0;
		}
		if(abs(int(s1[2])-int(s2[2]))==1&&s1[2]<='C'&&s2[2]<='C'||s1[2]=='D'&&s2[2]=='F') ans[3]='1';
		else ans[3]='0';
		cout<<ans;
		return 0;
	}
