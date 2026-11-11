#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;//1是车厢号，2是座位号
	cin>>c1>>c2>>s1>>s2;
		bool z=true;
		if(c1==s1) cout<<1;
		else cout<<0;
		for(int i=0;i<=1;i++){
			if(c1==s1&&c2[i]==s2[i]) z=true;	
		
			else {
			z=false;}
			}
			if(z==true) cout<<1;
			else cout<<0;
			bool x=true;
			for(int i=0;i<=1;i++){
			
			if(c1[2]=='C'&&s1[2]=='D'||c1[2]=='D'&&s1[2]=='C')
			x=false;
			else x=true;}
			if(x==true) cout<<1;
			else cout<<0;
			if((c1[2]=='A'&&s1[2]=='C')||(s1[2]=='A'&&c1[2]=='C'))
			cout<<0;
			else cout<<1;
	return 0;
}