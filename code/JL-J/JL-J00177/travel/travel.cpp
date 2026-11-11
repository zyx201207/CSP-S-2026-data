#include<bits/stdc++.h>
using namespace std;
int a[]={1,1,1,2,0,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,y1,y2;
	cin>>x1>>x2>>y1>>y2;
	if(x1==y1){cout<<1;}
	else{cout<<"0000";return 0;}
	bool bk=0;
	for(int i=0;i<2;i++){if(x2[i]!=y2[i])bk=1;}
	if(!bk)cout<<1;
	else{cout<<"000";return 0;}
	if(a[x2[2]-'A']==a[y2[2]-'A'])cout<<1;
	else{cout<<"00";return 0;}
	if(x2[2]=='F')x2[2]='E';
	if(y2[2]=='F')y2[2]='E';
	int xnum=int(x2[2]-'A'),ynum=int(y2[2]-'A');
	if(abs(xnum-ynum)==1)cout<<1;
	else cout<<0;
}
