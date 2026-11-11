#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,ct,st;
	cin>>c>>s>>ct>>st;
	int a=1,b=0;
		if(c==ct){
		cout<<a;
		} else cout<<b;
		if(s==st){
			cout<<a;
		}	
	return 0;
}
