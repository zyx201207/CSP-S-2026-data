#include<bits/stdc++.h>
using namespace std;
string a,b;
char x[10],y[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>x[1]>>x[2]>>x[3]>>b>>y[1]>>y[2]>>y[3];
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		for(int i=1;i<=2;i++){
			if(x[i]!=y[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		if((x[3]<='C'&&y[3]<='C')||(x[3]>='D'&&y[3]>='D')){
			cout<<"1";
			if((x[3]-y[3]==1||y[3]-x[3]==1)||(x[3]=='D'&&y[3]=='F')||(x[3]=='F'&&y[3]=='D')){
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
	
	return 0;
}