#include<bits/stdc++.h>
using namespace std;


string c1,s1,c2,s2;




int main(){
	freopen("travel.in","r",stdin);//@@@@@@@@@@@@@@@@@@
	freopen("travel.out","w",stdout);//@@@@@@@@@@@@@@@@@@@@2
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<1;
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]) cout<<1;
	else cout<<0;
	
	bool bs1=0,bs2=0;
	if(s1[2]>='D') bs1=1;
	if(s2[2]>='D') bs2=1;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && bs1==bs2) cout<<1;
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && bs1==bs2 && (s1[2]-s2[2]==1 || s1[2]-s2[2]==-1)) cout<<1;
	else cout<<0;
	
	
	
	
	
	
	
	fclose(stdin);//@@@@@@@@@@@@@@@@@@@@@
	fclose(stdout);//@@@@@@@@@@@@@@@@@@@@@@@
	return 0;
}
