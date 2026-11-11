#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		a=s1[2]-'A',b=s2[2]-'A';
		if(abs(a-b)<=2){
			if(a==3){
				if(b==4)cout<<1;
				else{
					cout<<0<<0;
					return 0;
				}
			}
			else if(b==3){
				if(a==4)cout<<1;
				else{
					cout<<0<<0;
					return 0;
				}
			}
			else cout<<1;
			if(abs(a-b)==1)cout<<1;
			else cout<<0;
		}
		else{
			cout<<0<<0;
			return 0;
		}
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}

	return 0;
}
