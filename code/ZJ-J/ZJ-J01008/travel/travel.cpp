#include<bits/stdc++.h>
using namespace std;
char x[20],y[20],a[20],b[20];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",x+1,y+1,a+1,b+1);
	int flag=1;
	for(int i=1;i<=2;i++)
	{
		if(x[i]!=a[i]) flag=0;
	}
	printf("%d",flag);
	if(flag==0) printf("0");
	else{
		flag=1;
		for(int i=1;i<=2;i++)
		{
			if(y[i]!=b[i]) flag=0;
		}
		printf("%d",flag);	
	}
	if(flag==0) printf("%d",flag);
	else{
		int xx=0,yy=0;
		if(y[3]>='A' && y[3]<='C') xx=1;
		if(b[3]>='A' && b[3]<='C') yy=1;
		if(xx==yy) flag=1;
		else flag=0;
		printf("%d",flag);
	}
	if(flag==0) printf("%d",flag);
	else{
		if(y[3]+1==b[3] || b[3]+1==y[3]) printf("1");
		else printf("0");
	}
	return 0;
}