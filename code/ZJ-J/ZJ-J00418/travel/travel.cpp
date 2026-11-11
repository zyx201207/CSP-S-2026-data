#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c1=" "+c1;
	c2=" "+c2;
	s1=" "+s1;
	s2=" "+s2;
	if(c1[1]==c2[1] && c1[2]==c2[2]){
		cout<<1;
		if(s1[1]==s2[1] && s1[2]==s2[2]){
			cout<<1;
			int t1,t2;
			t1=s1[3]-'A'+1;
			t2=s2[3]-'A'+1;
			if((t1<=3 && t2<=3) || (t1>=4 && t2>=4)){
				cout<<1;
				if(abs(t1-t2)==1){
					cout<<1;
				}
				else{
					cout<<"0";
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