#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			char c1=s2[2],c2=s4[2];
			if(c1>c2)swap(c1,c2);
			if(c1<='C'){
				if(c2<='C'){
					if(c2==c1+1)cout<<"1111";
					else cout<<"1110";
				}
				else{
					cout<<"1100";
				}
			}
			else{
				if(c2>'C'){
					if(c2==c1+1)cout<<"1111";
					else cout<<"1110";
				}
				else{
					cout<<"1100";
				}
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
/*
02 01A 02 01B
*/
//rp+=inf 
