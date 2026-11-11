#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			cout<<1;
			if(((r2[2]=='A'||r2[2]=='B'||r2[2]=='C')&&(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'))||((r2[2]=='D'||r2[2]=='F')&&(x2[2]=='D'||x2[2]=='F'))){
				cout<<1;
				if((r2[2]=='D'||r2[2]=='F')&&(x2[2]=='D'||x2[2]=='F')){
					cout<<1;
				}
				else if((r2[2]=='C'||r2[2]=='A')&&x2[2]=='B'){
					cout<<1;
				}
				else if((x2[2]=='C'||x2[2]=='A')&&x2[2]=='B'){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
