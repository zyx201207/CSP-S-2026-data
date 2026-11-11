#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string coach1,seat1,coach2,seat2;
	cin>>coach1>>seat1>>coach2>>seat2;
	bool f1=coach1==coach2;
	bool f2=f1&&seat1[0]==seat2[0]&&seat1[1]==seat2[1];
	int x=seat1[2]=='F'?5:seat1[2]-'A'+1;
	int y=seat2[2]=='F'?5:seat2[2]-'A'+1;
	bool f3=f2&&abs(x-y)==1||x==1&&y==3||x==3&&y==1;
	bool f4=f3&&abs(x-y)==1;
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
