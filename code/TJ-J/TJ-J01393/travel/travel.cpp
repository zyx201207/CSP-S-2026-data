#include<bits/stdc++.h>
using namespace std;
string r,x;
int rz,xz;
bool flag=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	a=(r[0]-'0')*10+(r[1]-'0');
	b=(x[0]-'0')*10+(x[1]-'0');
	cin>>rz>>r>>xz>>x;
	for(int i=1;i<=18;i++){
		if((a==i&&b==i+1)||(b==i&&a==i+1)){
			flag=1;
			break;
		}
	}
	string r_1,x_1;
	r_1[0]=r[0];
	r_1[1]=r[1];
	x_1[0]=x[0];
	x_1[1]=x[1];
	if(rz==xz){
		cout<<1;
		if(r_1==x_1){
			cout<<1;
			if((r[2]=='C'&&x[2]=='D')||(x[2]=='C'&&r[2]=='D')){
				cout<<0;
				if(flag)
					cout<<1;
				else cout<<0;
				}
			else cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	
	if(flag)cout<<1;
	else cout<<0;
	return 0;
}
