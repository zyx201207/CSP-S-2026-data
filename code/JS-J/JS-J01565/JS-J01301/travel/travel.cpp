#include<bits/stdc++.h>
using namespace std;
int s1,s2,s3,s4;
char c1,c2;
int read(bool b){
	int s=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	if(b){c2=c1;c1=c;}
	return s;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s1=read(0);
	s2=read(1);
	s3=read(0);
	s4=read(1);
	if(c1=='F')c1='E';
	if(c2=='F')c2='E';
	cout<<(s1==s3)<<(s1==s3&&s2==s4)<<(s1==s3&&s2==s4&&((c1<'D'&&c2<'D')||(c1>'C'&&c2>'C')))<<(s1==s3&&s2==s4&&((c1<'D'&&c2<'D')||(c1>'C'&&c2>'C'))&&abs(c1-c2)==1);
	return 0;
}
