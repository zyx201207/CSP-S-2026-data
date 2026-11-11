#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;//Trick||Treat!
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		char a=s1[0]+s1[1],b=s2[0]+s2[1];
	
		if(a==b){
			cout<<'1';
		
			char c=s1[2],d=s2[2];
			if((c>='A'&&c<='C')&&(d>='A'&&d<='C')){
				cout<<'1';
				if(c+1==d||d+1==c)
				cout<<'1';
				else cout<<'0';
			}
		
			else if((c=='D'||c=='F')&&(d=='D'||d=='F')){
				cout<<"11";
			}
		
			else{
				cout<<"00";
			} 
		}
	
		else cout<<"000";
	}
	else{
		cout<<"0000";
	} 
	return 0;
	
 } 