#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if('F'>=a[2]&&'D'<=a[2]&&'F'>=b[2]&&'D'<=b[2]){
		cout<<"11";
	}
	else if('C'>=a[2]&&'A'<=a[2]&&'C'>=b[2]&&'A'<=b[2]){
		cout<<"1";
		if(a[2]-b[2]==1||a[2]-b[2]==-1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"00";
	}
	return 0;
}