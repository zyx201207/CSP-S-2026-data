#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register
const int N=5e5+5;
string a1,b1,c1,s1,a2,b2,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2){
		cout<<1;
		b1=s1[0]+s1[1];
		b2=s2[0]+s2[1];
		if(b1==b2){
			cout<<1;
			ll x1=s1[2]-'A'+1,x2=s2[2]-'A'+1;
			if((1<=x1&&x1<=3&&1<=x2&&x2<=3)||(4<=x1&&x1<=5&&4<=x2&&x2<=5)){
				cout<<1;
				if(x1==x2-1||x1-1==x2){
					cout<<1;
				}else{
					cout<<0;
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
