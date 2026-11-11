#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s;
int l=13,a,b;
int w,x,y,z;
int ax,by;
bool yn(){
	if(a>=1&&a<=3)ax=1;
	if(b>=1&&b<=3)by=1;
	if(a+b==1)return 0;
	return 1; 
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	getline(cin,s);
	a=(s[0]-'0')*10+s[1],b=(s[7]-'0')*10+s[8];
	if(a==b)w=1;
	a=(s[3]-'0')+s[4],b=(s[10]-'0')+s[11];
	if(a==b)x=1;
	a=s[5]-'A'+1,b=s[12]-'A'+1;
	if(x&&yn())y=1;
	ax=by=0;
	if(y&&(a-b==1||a-b==-1))z=1;
	printf("%d%d%d%d\n",w,x,y,z);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
