#include<bits/stdc++.h>
using namespace std;
//Password: Trick||Treat! 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	bool x1=(c1==c3),x2=(x1 and (c2.substr(0,2)==c4.substr(0,2)));
	cout<<x1;
	cout<<x2;
	bool x3=x2;
	char cf2=c2[2],cf4=c4[2];
	if(cf2=='F')cf2='E';
	if(cf4=='F')cf4='E';
	if((cf2<='C' and cf4<='C') or (cf2>='D' and cf4>='D')){
		x3=(x3 and true);
	}else{
		x3=false;
	}
	cout<<x3;
	bool x4=x3;
	if(abs(cf2-cf4)==1){
		x4=(x4 and true);
	}else x4=false;
	cout<<x4;
	fclose(stdin);fclose(stdout);
	return 0;
} 

