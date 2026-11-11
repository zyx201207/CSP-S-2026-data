#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char n[11]={};
	for(int i=1;i<=10;i++){
		cin>>n[i];
	}
	int nx,ny,mx,my;
	nx+=(n[3]-'0')*10+(n[4]-'0')-1;
	mx+=(n[8]-'0')*10+(n[9]-'0');
	ny=n[5]-'A';
	my=n[10]-'A';
	if(n[1]=n[6]&&n[2]==n[7]) cout<<1;
	else cout<<0;
	if((n[1]=n[6]&&n[2]==n[7])&&nx==mx) cout<<1;
	else cout<<0;
	if((((n[5]=='A'||n[5]=='B'||n[5]=='C')&&(n[10]=='A'||n[10]=='B'||n[10]=='C'))||((n[10]=='F'||n[10]=='D')&&(n[5]=='F'||n[5]=='D')))&&((n[1]=n[6]&&n[2]==n[7])&&nx==mx)) cout<<1;
	else cout<<0;
	if((((n[5]=='A'||n[5]=='B'||n[5]=='C')&&(n[10]=='A'||n[10]=='B'||n[10]=='C'))||((n[10]=='F'||n[10]=='D')&&(n[5]=='F'||n[5]=='D')))&&(((nx-mx<=1)&&(nx-mx>=1))&&((ny-my<=1)&&(ny-my>=1)))) cout<<1;
	else cout<<0;
    fclose(stdin);
    fclose(stdout);
}
