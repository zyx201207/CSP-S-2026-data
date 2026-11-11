#include<bits/stdc++.h>
using namespace std;

int n;
string c_one,c_two;
string c_three,c_four;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c_one>>c_two>>c_three>>c_four;
	
	if(c_one!=c_three){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	
	for(int i=0;i<2;i++){
		if(c_two[i]!=c_four[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	
	if(('A'<=c_two[2] && c_two[2]<='C') && ('A'<=c_four[2] && c_four[2]<='C')){
		cout<<1;
		if(abs(c_two[2]-c_four[2])<=1) cout<<1;
		else cout<<"0";
	}
	else if(('D'<=c_two[2] && c_two[2]<='F') && ('D'<=c_four[2] && c_four[2]<='F')){
		cout<<"11";
	}
	else{
		cout<<"00";
	}
	return 0;
}
