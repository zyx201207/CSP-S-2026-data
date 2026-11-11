#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1.length()!=c2.length()) cout<<0<<0<<0<<0;
	else{
		bool flag=1;
		for(int i=0;i<c1.length();i++){
			if(c1[i]!=c2[i]){
				flag=0;
				cout<<0<<0<<0<<0;
				return 0;
			}
		}
		if(flag){
			cout<<1;
			for(int i=0;i<s1.length();i++){
				if(s1[i]<='9'&&s1[i]>='0'){
					if(s1[i]!=s2[i]){
						cout<<0<<0<<0;
						return 0;
					}
				}
			}
			cout<<1;
			char xx=s1[2],yy=s2[2];
			if(xx>='A'&&xx<='C'&&yy<='C'&&yy>='A'){
				cout<<1;
			}
			else if((xx=='D'||xx=='F')&&(yy=='D'||yy=='F')){
				cout<<1;
			}
			else{
				cout<<0<<0;
				return 0;
			}
			if(xx=='A'&&yy=='B'){
				cout<<1;
			}
			else if(xx=='B'&&yy=='A'){
				cout<<1;
			}
			else if(xx=='B'&&yy=='C'){
				cout<<1;
			}
			else if(xx=='C'&&yy=='B'){
				cout<<1;
			}
			else if(xx=='D'&&yy=='F'){
				cout<<1;
			}
			else if(xx=='F'&&yy=='D'){
				cout<<1;
			}
			else cout<<0;
		}
	}
	return 0;
}
