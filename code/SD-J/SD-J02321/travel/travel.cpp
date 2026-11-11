#include<bits/stdc++.h>
using namespace std;
string lmy;
string yxt;
string xx;
string yy;
bool vis[100];
bool vv[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>lmy;
	cin>>xx;
	cin>>yxt;
	cin>>yy;
	if(lmy == yxt){
		vis[1] = 1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(vis[1] == 1 and xx[0] == yy[0] and xx[1] == yy[1]){
		vis[2]=1;
		cout<<1;
	}else{
		cout<<0;
	}
	if(vis[1] == 1 and vis[2] == 1 and ((xx[2]>='A' and xx[2]<='C' and yy[2]>='A' and yy[2]<='C' ) or (xx[2]=='D' and yy[2]=='F') or(xx[2]=='F' and yy[2]=='D'))){
		vis[3]=1;
		cout<<1;
		if(xx[2]=='D' and yy[2]=='F'){
			vv[1]=1;
		}
		if(xx[2]=='F' and yy[2]=='D'){
			vv[1]=1;
		}
	}else{
		cout<<0;
	}
	if(vis[1] == 1 and vis[2] == 1 and vis[3]==1 ){
		if(vv[1]==1){
			cout<<1;
		}
		else{
			if((xx[2]=='A' and yy[2]=='B') or (xx[2]=='B' and yy[2]=='C')){
				 cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
} 
