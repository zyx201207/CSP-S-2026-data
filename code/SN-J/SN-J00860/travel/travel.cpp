#include<bits/stdc++.h>
using namespace std;
string sa,sb,sc,sd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>sb>>sc>>sd;
	if(sa!=sc) cout<<0<<0<<0<<0;
	else{
		cout<<1;
		if(sb[0]+sb[1]!=sd[0]+sd[1])cout<<"000";
		else{
			cout<<1;
			char a=sb[2],b=sd[2];
			if(a=='A'){
				if(b=='B'){
					cout<<11;
				}
				if(b=='C'){
					cout<<10;
				}
				if(b=='D'){
					cout<<0<<0;
				}
				if(b=='F'){
					cout<<0<<0;
				}
			}
			if(a=='B'){
				if(b=='A'){
					cout<<11;
				}
				if(b=='C'){
					cout<<11;
				}
				if(b=='D'){
					cout<<0<<0;
				}
				if(b=='F'){
					cout<<0<<0;
				}
			}
			if(a=='C'){
				if(b=='B'){
					cout<<11;
				}
				if(b=='A'){
					cout<<10;
				}
				if(b=='D'){
					cout<<0<<0;
				}
				if(b=='F'){
					cout<<0<<0;
				}
			}
			if(a=='D'){
				if(b=='B'){
					cout<<0<<0;
				}
				if(b=='A'){
					cout<<0<<0;
				}
				if(b=='C'){
					cout<<0<<0;
				}
				if(b=='F'){
					cout<<11;
				}
			}
			if(a=='F'){
				if(b=='B'){
					cout<<0<<0;
				}
				if(b=='A'){
					cout<<0<<0;
				}
				if(b=='C'){
					cout<<0<<0;
				}
				if(b=='D'){
					cout<<11;
				}
			}
		}
	}
	
	return 0;
}


