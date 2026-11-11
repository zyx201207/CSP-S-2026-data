#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
bool ans[4]={};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cs1,ss1,cs2,ss2;
	cin>>cs1>>ss1>>cs2>>ss2;
	int c1=0,c2=0;
	for(int i=0;i<cs1.size();i++){
		c1*=10;
		c1+=(cs1[i]-'0');
		c2*=10;
		c2+=(cs2[i]-'0');
	}
	ans[0]=(c1==c2);
	if(!ans[0]){
		ans[1]=0;
		ans[2]=0;
		ans[3]=0;
	}else{
		int s1=0,s2=0;
		for(int i=0;i<2;i++){
			s1*=10;
			s2*=10;
			s1+=(ss1[i]-'0');
			s2+=(ss2[i]-'0');
		}
		ans[1]=(s1==s2);
		if(!ans[1]){
			ans[2]=0;
			ans[3]=0;
		}else{
			ans[2]=((ss1[2]>='A'&&ss1[2]<='C'&&ss2[2]>='A'&&ss2[2]<='C')||(ss1[2]>='D'&&ss1[2]<='E'&&ss2[2]>='D'&&ss2[2]<='E'));
			ans[3]=(ans[2]&&(ss1[2]==ss2[2]+1||ss1[2]==ss2[2]-1));
		}
	}
	for(int i=0;i<4;i++){
		printf("%d",(int)ans[i]);
	}
	return 0;
 } 
