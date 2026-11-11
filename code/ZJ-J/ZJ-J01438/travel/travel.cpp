#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if((s2[0]==s4[0])&&(s2[1]==s4[1])){
			cout<<1;
			if(((int(s2[2])>=65)&&(int(s2[2])<=67)&&(int(s4[2])>=65)&&(int(s4[2])<=67))||((int(s2[2])>=68)&&(int(s2[2])<=70)&&(int(s4[2])>=68)&&(int(s4[2])<=70))){
				cout<<1;
				if(abs(int(s2[2])-int(s4[2]))==1) cout<<1;
				else{
					if((abs(int(s2[2])-int(s4[2]))==2)&&((int(s2[2])==68&&int(s4[2])==70)||(int(s4[2])==68&&int(s2[2])==70))){
						cout<<1;
					}else cout<<0;
				}
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
