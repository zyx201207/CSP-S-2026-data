#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x==y){
		cout<<"1";
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<"1";
			int l,r;
			if(a[2]=='A')l=1;
			else if(a[2]=='B')l=2;
			else if(a[2]=='C')l=3;
			else if(a[2]=='D')l=5;
			else if(a[2]=='F')l=6;
			
			if(b[2]=='A')r=1;
			else if(b[2]=='B')r=2;
			else if(b[2]=='C')r=3;
			else if(b[2]=='D')r=5;
			else if(b[2]=='F')r=6;
			if((l<=3&&r<=3)||(l>=5&&r>=5)){
				cout<<"1";
			}else{
				cout<<"0";
			}
			if(abs(l-r)==1){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

