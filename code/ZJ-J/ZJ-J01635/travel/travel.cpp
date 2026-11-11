#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,x,y;
char s[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",s+1);
	for(int i=1;i<=2;i++)n=(n<<1)+(n<<3)+(s[i]&15);
	scanf("%s",s+1);
	for(int i=1;i<=2;i++)a=(a<<1)+(a<<3)+(s[i]&15);
	x=(s[3]=='A'?1:(s[3]=='B'?2:(s[3]=='C'?3:(s[3]=='D'?4:5))));
	scanf("%s",s+1);
	for(int i=1;i<=2;i++)m=(m<<1)+(m<<3)+(s[i]&15);
	scanf("%s",s+1);
	for(int i=1;i<=2;i++)b=(b<<1)+(b<<3)+(s[i]&15);
	y=(s[3]=='A'?1:(s[3]=='B'?2:(s[3]=='C'?3:(s[3]=='D'?4:5))));
	printf("%d%d%d%d\n",n==m,n==m&&a==b,n==m&&a==b&&((x<=3&&y<=3)||(x>=4&&y>=4)),n==m&&a==b&&((x<=3&&y<=3)||(x>=4&&y>=4))&&(x+1==y||y+1==x));
//	printf("%d %d %d %d %d %d\n",n,a,x,m,b,y);
	return 0;
}