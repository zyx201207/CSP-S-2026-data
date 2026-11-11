#include<bits/stdc++.h>
using namespace std;
int sz(string a){
	int js;
	js=(a[0]-'0')*10+(a[1]-'0');
	return js;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,zw1,cx2,zw2;
	int p1,p2,l1,l2;
	cin>>cx1>>zw1>>cx2>>zw2;
	p1=sz(zw1);
	p2=sz(zw2);
	l1=zw1[2]-'A'+1;
	l2=zw2[2]-'A'+1;
	if(cx1==cx2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if(l1>=1&&l1<=3&&l2>=1&&l2<=3){
				cout<<1;
			}else if(l1==4||l1==5&&l2==4&&l2==5){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<"00";
		}
		if(p1-p2==1||p2-p1==1){
			if(l1==l2){
				cout<<1;
			}else{
				cout<<0;
			}
		}else if(p1==p2){
			if(l1-l2==1||l2-l1==1&&!(l1<=3&&l2>3)||(l1>3&&l2<=3)){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
return 0;
}
