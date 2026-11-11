#include<bits/stdc++.h>
using namespace std;
int xa,xb,pa,pb,f,za,zb;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	xa=a[0]*10+a[1];
	xb=b[0]*10+b[1];
	pa=c[0]*10+c[1];
	pb=d[0]*10+d[1];
	za=c[2]-'A';
	zb=d[2]-'A';
	if(za==3){
		za++;
	}
	if(zb==3){
		zb++;
	}
	if(xa==xb){
		cout<<"1";
		if(pa==pb){
			cout<<"1";
			if(((za>=0&&za<3)&&(zb>=0&&zb<3))||((za>=4&&za<=5)&&(zb>=4&&zb<=5))){
				cout<<"1";
				if(abs(za-zb)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
		
	return 0;
}
