#include<bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
bool vis[4];
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		vis[0]=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if((r2[0]-'0')*10+(r2[1]-'0')==(x2[0]-'0')*10+(x2[1]-'0')){
		vis[1]=1;
	}else{
		cout<<"1000";
		return 0;
	}
	if(((r2[2]>='A'&&r2[2]<='C')&&(x2[2]>='A'&&x2[2]<='C'))||(r2[2]=='D'&&x2[2]=='F')||(r2[2]=='F'&&x2[2]=='D')){
		vis[2]=1;
	}else{
		cout<<"1100";
		return 0;
	}
	if((r2[2]=='D'&&x2[2]=='F')||(r2[2]=='F'&&x2[2]=='D')||(r2[2]-1==x2[2]&&r2[2]!='D')||(r2[2]+1==x2[2]&&r2[2]!='C')){
		vis[3]=1;
	}
	for(int i=0;i<4;i++){
		cout<<vis[i];
	}
	return 0;
} 
