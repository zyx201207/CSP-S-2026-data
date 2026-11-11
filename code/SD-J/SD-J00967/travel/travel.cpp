#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2,s3,q1,q2;
int t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s2>>s3;
	t1=(s1-'0')*10+(s2-'0');
	q1=s3;
	cin>>c2>>s1>>s2>>s3;
	t2=(s1-'0')*10+(s2-'0');
	q2=s3;
	if(c1==c2) printf("1");
	else{
		printf("0000");
		return 0;
	}
	if(t1==t2) printf("1");
	else {
		printf("000");
		return 0;
	}
	if(q1>='D'&&q2>='D'||q1<'D'&&q2<'D') printf("1");
	else {
		printf("00");
		return 0;
	}
	if((char)(q1+1)==q2||(char)(q1-1)==q2) printf("1");
	else printf("0");
	return 0;
}
