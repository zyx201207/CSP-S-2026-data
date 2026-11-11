#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string t,tt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>t>>c>>d>>tt;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(t=="F"&&tt=="D"||t=="D"&&tt=="F"||t=="A"&&tt=="B"||t=="A"&&tt=="C"||t=="B"&&tt=="C"||t=="B"&&tt=="A"||t=="C"&&tt=="A"||t=="C"&&tt=="B"){
				cout<<1;
				if(t=="F"&&tt=="D"||t=="D"&&tt=="F"||t=="A"&&tt=="B"||t=="B"&&tt=="C"||t=="B"&&tt=="A"||t=="C"&&tt=="B"){
					cout<<1;
				}
				else{
					cout<<"0";
				}
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
