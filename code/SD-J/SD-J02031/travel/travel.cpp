#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b;
	string q,w;
	cin>>a>>q>>b>>w;
	if(a!=b){
		cout<<"0000";
		return 0;
	}
	else if(q[0]==w[0]&&q[1]==w[1]){
		if((q[2]<'D'&&w[2]<'D')||(q[2]>='D'&&w[2]>='D')){
			if(abs(q[2]-w[2])==1){
				cout<<"1111";
			}
			else{
				cout<<"1110";
			}
		}
		else{
			cout<<"1100";
		}
	}
	else{
		cout<<"1000";
	}
	return 0;
}
