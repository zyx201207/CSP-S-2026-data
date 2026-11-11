#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		string s1="";
		s1=s1+a2[0]+a2[1];
		string s2="";
		s2=s2+b2[0]+b2[1];
		if(s1==s2){
			cout<<1;
			if('A'<=a2[2] and a2[2]<='C' and 'A'<=b2[2] and b2[2]<='C'){
				cout<<1;
				int num=a2[2]-b2[2];
				num=abs(num);
				if(num==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if('D'<=a2[2] and a2[2]<='F' and 'D'<=b2[2] and b2[2]<='F'){
				cout<<"11";
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