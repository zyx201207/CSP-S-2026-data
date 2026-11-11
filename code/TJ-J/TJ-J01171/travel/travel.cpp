#include<bits/stdc++.h>
using namespace std;

string m,n,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	if(n==m){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if((x[2]=='A'||x[2]=='B'||x[2]=='C'&&y[2]=='A'||y[2]=='B'||y[2]=='C')||(x[2]=='D'||x[2]=='E'&&y[2]=='D'||y[2]=='E')){
				cout<<1; 
				if(x[2]-1==y[2]||x[2]+1==y[2]){
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
