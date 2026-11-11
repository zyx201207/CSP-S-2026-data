#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string r,x;
	cin>>a>>r>>b>>x;
	if(a==b){
		cout<<"1";
		if(r==x){
			cout<<"111";
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
