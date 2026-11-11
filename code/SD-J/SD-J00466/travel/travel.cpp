#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	bool flag1=false,flag2=false,flag3=false,flag4=false;
	if(c1==c2){
		flag1=true;
	}
	
	int pai1=(s1[0]-'0')*10+(s1[1]-'0');
	int pai2=(s2[0]-'0')*10+(s2[1]-'0');
	if(flag1&&pai1==pai2){
		flag2=true;
	}
	
	char zuo1=s1[2];
	char zuo2=s2[2];
	bool o=(zuo1=='A'||zuo1=='B'||zuo1=='C')&&(zuo2=='A'||zuo2=='B'||zuo2=='C');
	bool p=(zuo1=='D'||zuo1=='F')&&(zuo2=='D'||zuo2=='F');
	if(flag2&&(o||p)){
		flag3=true;
	}
	
	if(flag3){
		if(zuo1=='A'&&zuo2=='B') flag4=true;
		else if(zuo1=='B'&&zuo2=='C') flag4=true;
		else if(zuo1=='D'&&zuo2=='F') flag4=true; 
	} 
	
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}//Please.
