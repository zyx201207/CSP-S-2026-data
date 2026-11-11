#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int h1,h2;
char z1,z2;
int flg1,flg2,flg3,flg4;
char s[50];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c1=read();scanf("%s",s+1);h1=(s[1]-'0')*10+s[2]-'0';z1=s[3];
	c2=read();scanf("%s",s+1);h2=(s[1]-'0')*10+s[2]-'0';z2=s[3];
	if(c1!=c2) printf("0000\n");
	else if(c1==c2&&h1!=h2) printf("1000\n");
	else if(c1==c2&&h1==h2&&((z1<=67&&z2>67)||(z1>67&&z2<=67))) printf("1100\n");
	else if(c1==c2&&h1==h2&&z1+1!=z2&&z2+1!=z1) printf("1110\n");
	else printf("1111\n");
	return 0;
}