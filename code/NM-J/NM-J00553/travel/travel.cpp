#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >>c1>>s1>>c2>>s2;
	int n1=(s1[0]-'0')*10+(s1[1]-'0'),n2=(s2[0]-'0')*10+(s2[1]-'0');
	int m1=s1[2]-'A'+1,m2=s2[2]-'A'+1;
	if(c1!=c2){
		cout <<"0000";
	}
	else{
	   if(n1!=n2) cout<<"1000";
	   else{
	   	  if((m1<=3&&m2>3)||(m1>3&&m2<=3)) cout<<"1100";
	   	  else{
	   	  	if(m1-m2==1||m1-m2==-1||(m1==4&&m2==6)||(m1==6&&m2==4)) cout<<"1111";
	   	  	else cout<<"1110";
			 }
	   }	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
