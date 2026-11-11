#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,n,m;
	bool flag=0;
	cin>>n>>a>>m>>b;
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	else {
		cout<<"1";
	}
	if(a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
		if(a[2]<='C'&&b[2]<='C'){
			cout<<"1";
			if(abs(int(a[2]-b[2]))==1){
				cout<<"1";
			}
			else {
				cout<<"0";
			}
			flag=1; 
		}
		else if(a[2]>='D'&&b[2]>='D'){
			cout<<"1";
			if(abs(int(a[2]-b[2]))==2){
				cout<<"1";
			}
			else {
				cout<<"0";
			}
			flag=1;
		}
		if(flag==0){
			cout<<"00";
			return 0;
		}
	}
	else {
		cout<<"000";
	}
	return 0;
} 
