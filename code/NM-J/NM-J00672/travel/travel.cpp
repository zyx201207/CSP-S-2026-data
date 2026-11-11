#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int f=0;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) {cout<<1;f=1;}
	    else {cout<<0;f=0;}
	if(f==0) cout<<0;
	if(f==1) if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	    else {cout<<0;f=0;}
	if(f==0) cout<<0;
	if(f==1) if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')) cout<<1;
	              else if((b[2]=='D'||b[2]=='F')&&d[2]=='D'||d[2]=='F') cout<<1;
	    else {cout<<0;f=0;}
	if(f==0) cout<<0;
	if(f==1) {if(b[2]=='A'&&d[2]=='B') cout<<1;
	              else if(b[2]=='B'&&d[2]=='A') cout<<1;
				      else if(b[2]=='B'&&d[2]=='C') cout<<1;
					      else if(b[2]=='C'&&d[2]=='B') cout<<1;
						      else if(b[2]=='D'&&d[2]=='F') cout<<1;
							      else if(b[2]=='F'&&d[2]=='D') cout<<1;
								      else cout<<0;}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
