#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	int b;
	string x,y;
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<"1";
		if(x[0]==y[0]){
			if(x[1]==y[1]){
				cout<<1;
			}
			else{
				cout<<"000";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
		int f=0,s=0;
		if(x[2]=='A'||x[2]=='B'||x[2]=='C'){
			f=0;
		}
		else f=1;
		if(y[2]=='A'||y[2]=='B'||y[2]=='C'){
			s=0;
		}
		else s=1;
		if(f==s){
			cout<<1;
		}
		else{
			cout<<"00";
			return 0;
		}
		if((int(x[2])==(int(y[2])-1))||(int(x[2])==(int(y[2])+1))){
			cout<<1;
		}
	}
    else{
		cout<<"0000";
	}
	return 0;
}
