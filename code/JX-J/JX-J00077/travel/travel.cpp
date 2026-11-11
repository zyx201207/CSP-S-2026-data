#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
string cc1,cc2;
int ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cc1+=s1[0];
	cc1+=s1[1];
	cc2+=s2[0];
	cc2+=s2[1];
	ss1=int(s1[2]);
	ss2=int(s2[2]);
	if(c1==c2){
		ans+="1";
		if(cc1==cc2){
			ans+="1";
			int t=int('C');
			if((ss1<=t&&ss2<=t)||(ss1>t&&ss2>t)){
				ans+="1";
				//cout<<ss1-ss2<<endl;
				if(ss1-ss2==1||ss1-ss2==-1){
					ans+="1";
				}else{
					ans="1110";
				}
			}else{
				ans="1100";
			}
		}else{
			ans="1000";
		}
	}else{
		ans="0000";
	}
	cout<<ans;
	return 0;
}
