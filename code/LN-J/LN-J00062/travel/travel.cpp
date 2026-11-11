#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string x,n,y,m;
	cin>>x>>n>>y>>m;
	if(x==y){
        cout<<"1";
        if((n[0]-'0')*10+(n[1]-'0')==(m[0]-'0')*10+(m[1]-'0')){
        cout<<"1";
		if(n[2]>='A'&&n[2]<='C'&&m[2]>='A'&&m[2]<='C'){
		cout<<"1";
		if(n[2]+1==m[2]||n[2]-1==m[2]){
			cout<<"1";
		}
		else{
			cout<<"0";
			}
	}
	else if(n[2]=='D'||n[2]=='F'&&m[2]=='D'||m[2]=='F'){
		cout<<"1";
		}
	else{
		cout<<"00";
	}
	}

	else{
		cout<<"000";
	}
	}
	else{
		cout<<"0000";
	}


return 0;
}
