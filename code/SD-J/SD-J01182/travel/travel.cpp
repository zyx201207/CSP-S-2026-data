#include<bits/stdc++.h>
using namespace std;
int xa,ya;
char xb[3],yb[3];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%s%d%s",&xa,xb,&ya,yb);
	bool a=(xa==ya),b=((xb[0]==yb[0])&&(xb[1]==yb[1]));
	bool c=(xb[2]>='D'&&yb[2]>='D')||(xb[2]<='C'&&yb[2]<='C');
	bool d=(c&&(abs(xb[2]-yb[2])==1));
	printf("%d%d%d%d\n",a,a&&b,a&&b&&c,a&&b&&d);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
