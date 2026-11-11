#include<bits/stdc++.h>
using namespace std;	
int x[3],y[3];
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b;
	x[0]=(a-'0')*10+(b-'0');
	cin>>a>>b;
	x[1]=(a-'0')*10+(b-'0');
	cin>>a;
	x[2]=a-'A';
	cin>>a>>b;
	y[0]=(a-'0')*10+(b-'0');
	cin>>a>>b;
	y[1]=(a-'0')*10+(b-'0');
	cin>>a;
	y[2]=a-'A';
	cout<<(x[0]==y[0]) ? 1 : 0;
	cout<<(x[0]==y[0]&&x[1]==y[1]) ? 1 : 0;
	cout<<(x[0]==y[0]&&x[1]==y[1]&&((x[2]<=2&&y[2]<=2)||(x[2]>2&&y[2]>2))) ? 1 : 0;
	cout<<(x[0]==y[0]&&x[1]==y[1]&&((x[2]<=2&&y[2]<=2)||(x[2]>2&&y[2]>2))&&(x[2]==y[2]-1||x[2]==y[2]+1)) ? 1 : 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
