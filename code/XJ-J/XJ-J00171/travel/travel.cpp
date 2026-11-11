#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r,r1,x,x1;
	cin>>r>>r1>>x>>x1;
	if(r!=x){
        cout<<"0000";
    }
    else if(r1[0]!=x1[0]||r1[1]!=x1[1]){
    	cout<<"1000";
	} 
	else if(r1[2]<='C'&&x1[2]>='D'||x1[2]<='C'&&r1[2]>='D'){
		cout<<"1100";
	}
	else if(r1[2]=='B'||x1[2]=='B'||r1[2]=='D'||x1[2]=='D'){
		cout<<"1111";
	}
	else{
		cout<<"1110";
	}
	return 0;
}
