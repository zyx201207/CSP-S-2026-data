#include<iostream>
using namespace std;
int n,m;
string a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&n);
	cin>>a;
	scanf("%d",&m);
	cin>>b;
	if(n==m)
	{
		printf("1");
		if(a[0]==b[0]&&a[1]==b[1])
		{
			printf("1");
			if(((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))||((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F')))
			{
				printf("1");
				if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A')||(a[2]=='B'&&b[2]=='C')||(a[2]=='C'&&b[2]=='B')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D'))printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
