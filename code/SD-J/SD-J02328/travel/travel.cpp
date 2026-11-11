#include<cstdio>
using namespace std;
int n1,m1,n2,m2;char c1,c2;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&n1,&m1,&c1,&n2,&m2,&c2);
	if(n1!=n2)printf("0000");
	else if(m1!=m2)printf("1000");
	else if(!('A'<=c1&&c1<='C'&&'A'<=c2&&c2<='C'||'D'<=c1&&c1<='F'&&'D'<=c2&&c2<='F'))printf("1100");
	else if(!(c1-c2==1||c1-c2==-1||c1-c2==2&&(c1=='D'||c2=='D')))printf("1110");
	else printf("1111");
	return 0;
}

