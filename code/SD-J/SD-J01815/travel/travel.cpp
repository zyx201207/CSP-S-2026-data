#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	int x=a[0]-'0',y=a[1]-'0',u=c[0]-'0',v=c[1]-'0';
	if(x*10+y==u*10+v){
		cout<<1;
		x=b[0]-'0';
		y=b[1]-'0';
		u=d[0]-'0';
		v=d[1]-'0';
		if(x*10+y==u*10+v){
			cout<<1;
			x=b[2]-'A';
			y=d[2]-'A';
			if(x>y)swap(x,y);
			if((x==0&&y==3)||(x==1&&y==3)||(x==2&&y==3)||(x==0&&y==4)||(x==1&&y==4)||(x==2&&y==4))cout<<"00";
			else{
				cout<<1;
				if(y-x==1)cout<<1;
				else cout<<0;
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
