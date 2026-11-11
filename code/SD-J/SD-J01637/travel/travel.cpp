#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int xa,xb;
	string ya,yb;
	cin>>xa>>ya>>xb>>yb;
	int hang1=(ya[0]-'0')*10+(ya[1]-'0');
	int hang2=(yb[0]-'0')*10+(yb[1]-'0');
	string a="1000";
	
	if(xa!=xb){
		cout<<"0000";
	}
	else{
	if(hang1==hang2)a[1]='1';
	if(((ya[2]<='C'&&yb[2]<='C')||((ya[2]=='D'&&yb[2]=='F')||(yb[2]=='D'&&ya[2]=='F')))&&a[1]=='1')a[2]='1';
	if((abs(ya[2]-yb[2])==1||(abs(ya[2]-yb[2])==2&&((ya[2]=='D'&&yb[2]=='F')||(yb[2]=='D'&&ya[2]=='F'))))&&a[2]=='1'&&a[1]=='1')a[3]='1';
	cout<<a;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
