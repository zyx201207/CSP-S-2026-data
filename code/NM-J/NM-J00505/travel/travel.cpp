#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool f[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {cout<<1;f[2]=true;}
	      else {cout<<0;f[2]=false;}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f[2]==true) {cout<<1;f[1]=true;}
	                                      else {cout<<0;f[1]=false;}
	if(f[1]==true) {
		              if(s1[2]=='A') 
					   if(s2[2]=='B'||s2[2]=='C') {cout<<1;f[3]=true;}
		              if(s1[2]=='B')
		                    if(s2[2]=='A'||s2[2]=='C') {cout<<1;f[3]=true;}
		              if(s1[2]=='C')
		                    if(s2[2]=='A'||s2[2]=='B') {cout<<1;f[3]=true;}
		              if(s1[2]=='D')
		                    if(s2[2]=='F') {cout<<1;f[3]=true;}
		              if(s1[2]=='F')
		                    if(s2[2]=='D') {cout<<1;f[3]=true;}
		              if(f[3]==false) cout<<0;
                   } 
    else cout<<0;
	if(f[1]==true) {
		              if(s1[2]=='A'&&s2[2]=='B') {cout<<1;f[4]=true;}
		              if(s1[2]=='B'&&s2[2]=='A') {cout<<1;f[4]=true;}
		              if(s1[2]=='B'&&s2[2]=='C') {cout<<1;f[4]=true;}
		              if(s1[2]=='C'&&s2[2]=='B') {cout<<1;f[4]=true;}
		              if(s1[2]=='D'&&s2[2]=='F') {cout<<1;f[4]=true;}
		              if(s1[2]=='F'&&s2[2]=='D') {cout<<1;f[4]=true;}
		              if(f[4]==false) cout<<0;
	               }						     
	           else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
