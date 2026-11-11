//code by YeBaiowo
#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
bool r1,r2;
bool flag=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				r1=0;
			}
			else{
				r1=1;
			}
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				r2=0;
			}
			else{
				r2=1;
			}
			if(r1==r2){
				cout<<1;
				if(r1==0){
					if(abs((int)s1[2]-(int)s2[2])==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				if(r1==1){
					cout<<1;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
/*
must rp++ pls!!
T1 probably 100pts
cute owo cute owo cute owo cute owo cute owo
Today may really rp ++ I guess!
*/
