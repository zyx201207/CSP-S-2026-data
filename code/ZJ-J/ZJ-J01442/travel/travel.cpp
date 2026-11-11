#include<bits/stdc++.h>
using ll=long long;
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		char a1=s1[0],a2=s1[1],a3=s1[2],b1=s2[0],b2=s2[1],b3=s2[2];
		if(a1==b1&&b2==a2){
			cout<<1;
			if(a3=='D'||a3=='F'){
				if(b3=='D'||b3=='F'){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
			else if(a3=='A'||a3=='B'||a3=='C'){
				if(b3=='A'||b3=='B'||b3=='C'){
					cout<<1;
					if(a3=='A'){
						if(b3=='B'){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
					if(a3=='B'){
						if(b3=='A'||b3=='C'){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
					if(a3=='C'){
						if(b3=='B'){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
				}
				else{
					cout<<"00";
				}
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