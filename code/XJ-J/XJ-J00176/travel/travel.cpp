#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool q=1,w=1,e=1,r=1;
	cin>>a>>b>>c>>d;
	for(int i=0;i<=1;i++) if(a[i]!=c[i]) q=0;
	if(q==0)  cout<<"0000";
	else{
		for(int i=0;i<=1;i++) if(b[i]!=d[i]) w=0;
		if(w==0) cout<<"1000";
		else{
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F')||(d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F')) e=0;
			if(e==0) cout<<"1100";
			else{
				if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A') cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0; 
 } 
