#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,h1,h2;
	cin>>c1>>s1>>c2>>s2;
	h1=s1[0]+s1[1];
	h2=s2[0]+s2[1];
	if(c1==c2) {
		cout<<1;
		if(h1==h2) {
			cout<<1;
			if(s1[2]<='C'&&s2[2]<='C'){
				cout<<1;
				if(int(s1[2]-s2[2])==1||int(s1[2]-s2[2])==-1)
					cout<<1;
				else cout<<0;
			}
			else if(s1[2]>='D'&&s2[2]>='D'){
				cout<<1<<1;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
		
	}
	else cout<<0<<0<<0<<0;
	
	return 0;
}
