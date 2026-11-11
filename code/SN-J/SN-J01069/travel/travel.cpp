#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c) cout<<"0000";
	else{
		cout<<1;
		if(b[0]!=d[0]||b[1]!=d[1]) cout<<"000";
		else{
			cout<<1;
			if(b[2]>='D'&&d[2]<'D') cout<<"00";
			else if(b[2]<'D'&&d[2]>='D') cout<<"00";
			else{
				cout<<1;
				if(b[2]<'D'&&d[2]<'D'&&fabs(b[2]-d[2])==1) cout<<'1';
				else if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')) cout<<'1';
				else cout<<'0';
			}
		}
	}
	return 0;
} 
