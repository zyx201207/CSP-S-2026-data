#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int s11,s21;
char s12,s22; 
string s1="ABC",s2="DF";
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s11>>s12>>c2>>s21>>s22;
	if(c1==c2){
		cout<<1;
		if(s11==s21){
			cout<<1;
			if(s1.find(s12)<=2&&s1.find(s22)<=2){
				cout<<1;
				if(abs(s22-s12)==1){
					cout<<1; 
				}else{
					cout<<0;
				}
			}else if(s2.find(s12)<=1&&s2.find(s22)<=1){
				cout<<1;
				if(abs(s22-s12)==1){
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

