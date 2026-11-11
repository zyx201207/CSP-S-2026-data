#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,l1,l2;
	string x,y;
	//scanf("&d &d&c &d &d&c",a,l1,x,b,l2,y);
	cin>>a>>x>>b>>y;
	//cout<<a<<' '<<x<<' '<<b<<' '<<y;
	if(a==b){
		cout<<"1";
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<"1";
			if((x[2]<='C'&&y[2]<='C')||(x[2]>='D'&&y[2]>='D')){
				cout<<"1";
				if(x[2]<='C'&&y[2]<='C'){
					if(x[2]+1==y[2]||y[2]+1==x[2]){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					if(x[2]+1==y[2]||y[2]+1==x[2]){
						cout<<"1";
					}else{
						cout<<"0";
					}
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
