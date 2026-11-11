#include<cstdio>
#include<algorithm>
#include<string>
const int maxn=20;
char tmp1[maxn],tmp2[maxn],tmp3[maxn],tmp4[maxn];
std::string a,b,c,d;
int main(){
	//freopen("test1.in","r",stdin);
	//freopen("t.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&tmp1[1],&tmp2[1],&tmp3[1],&tmp4[1]);
	a=&tmp1[1],b=&tmp2[1],c=&tmp3[1],d=&tmp4[1];
	bool q1,q2,q3,q4;
	int x=0,y=0;
	for(int i=0;i<(int)a.size();i++) x=x*10+a[i]-'0';
	for(int i=0;i<(int)c.size();i++) y=y*10+c[i]-'0';
	q1=x==y;
	x=0,y=0;
	for(int i=0;i<(int)b.size();i++) if('0'<=b[i]&&b[i]<='9') x=x*10+b[i]-'0';
	for(int i=0;i<(int)d.size();i++) if('0'<=d[i]&&d[i]<='9') y=y*10+d[i]-'0';
	q2=q1&&(x==y);
	char p='?',q='?';
	for(int i=0;i<(int)b.size();i++) if('A'<=b[i]&&b[i]<='Z') p=b[i];
	for(int i=0;i<(int)d.size();i++) if('A'<=d[i]&&d[i]<='Z') q=d[i];
	bool f1=p=='D'||p=='F',f2=q=='D'||q=='F';
	q3=q2&&(f1==f2);
	q4=q3&&((f1&&f2)||std::abs(p-q)==1);
	printf("%d%d%d%d\n",q1,q2,q3,q4);
	return 0;
}
