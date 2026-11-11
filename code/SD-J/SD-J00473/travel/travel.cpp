#include<bits/stdc++.h>
using namespace std;
//typedef long long LL;
//const int N=1e5+5;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int t=0;
	if(c1==c2){
		printf("1");
		t++;
	}
	else printf("0");
	if(t==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		printf("1");
		t++;
	}
	else printf("0");
	if(t==2&&(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]=='F')){
		printf("1");
		t++;
	}
	else printf("0");
	if(t==3&&!((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D'))&&((int)s2[2]==(int)s1[2]-1||(int)s2[2]==(int)s1[2]+1)) printf("1");
	else printf("0");
	return  0;
} //·´ÎÚÍĞ°î 
