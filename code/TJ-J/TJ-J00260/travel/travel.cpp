#include<bits/stdc++.h>
using namespace std;
string ca,sa,cc,sc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cc>>sc;
	if(ca==cc){
		cout<<1;
		if(sa[0]+sa[1]==sc[0]+sc[1]){
			cout<<1;
			if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C'&&sc[2]=='A'||sc[2]=='B'||sc[2]=='C'&&sa[2]!=sc[2]){
				cout<<1;
				if(sa[2]-sc[2]==1||sc[2]-sa[2]==1){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else if(sa[2]=='D'||sa[2]=='F'&&ca[2]=='D'||ca[2]=='F'&&sa[2]!=sc[2]){
				cout<<1;
				if(sa[2]-sc[2]==1||sc[2]-sa[2]==1){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<0;
				cout<<0;
				return 0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
			return 0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	return 0;
} 
