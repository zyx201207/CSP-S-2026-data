#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.txt","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<"1";
		
	}else{
		cout<<"0000";
		return 0;
	}
	if(a==b){
		cout<<"000";
		return 0;
	}else{
		cout<<"1"; 
	}
	for(int i=1;i<=1;i++){
		if(a[i]=='C'||b[i]=='D'){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}
	cout<<"0";
	return 0;
}

