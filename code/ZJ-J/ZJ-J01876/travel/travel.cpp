#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string x,y;
	cin>>x>>a>>y>>b;
	int c1=(a[0]-'0')*10+a[1]-'0';
	int c2=(b[0]-'0')*10+b[1]-'0';
	if(x==y){
		cout<<1;
		if(c1==c2){
			cout<<1;
			if((a[2]<='C'&&b[2]<='C')||(a[2]>='D'&&b[2]>='D')){
				cout<<1;
				if(abs(a[2]-b[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
