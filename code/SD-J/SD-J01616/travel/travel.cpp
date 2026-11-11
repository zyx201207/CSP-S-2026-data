#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>x1>>r2>>x2;
	string p1,p2;
	for(int i=0;i<=1;i++){
		p1+=x1[i];
		p2+=x2[i];
	}
	if(r1==r2){
		cout<<1;
		if(p1==p2){
			cout<<1;
			if((x1[2]<='C'&&x2[2]<='C')||(x1[2]>='D'&&x2[2]>='D')){
				cout<<1;
				long long d=abs(x1[2]-x2[2]);
				if(d==1){
					cout<<1;
				}else{
					cout<<"0";
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
