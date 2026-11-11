#include<bits/stdc++.h>
using namespace std;
int a,b;
string q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>q>>b>>w;

	if(a==b){
		cout<<1;
	} 
	else{
		cout<<"0000";
		return 0;
	} 
	if(w[0]*10+w[1]==q[0]*10+q[1]){
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	if(q[2]<68&&w[2]<68){
		if(q[2]==66||w[2]==66){
			cout<<"11";
		}
		else{
			cout<<"10";
		}
	}
	else{
		if(int(q[2])+int(w[2])!=137)
		{
			cout<<"00";
		}
		else cout<<"11";
	}
	return 0;
}
