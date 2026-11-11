#include<bits/stdc++.h>
using namespace std;
int num1,num2;
char a,b,c;
int p1,p2,z1,z2,c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>num1>>a>>b>>c;
	p1=(a-'0')*10+(b-'0');
	z1=c-'A'+1;
	cin>>num2>>a>>b>>c;
	p2=(a-'0')*10+(b-'0');
	z2=c-'A'+1;
	if(z1<=3){
		c1=1;
	}else{
		c1=2;
	}
	if(z2<=3){
		c2=1;
	}else{
		c2=2;
	}
	if(num1==num2){
		cout<<"1";
		if(p1==p2){
			cout<<"1";
			if(c1==c2){
				cout<<"1";
				if(abs(z1-z2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
