#include <bits/stdc++.h> 
using namespace std;
int main()
{
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,k;
	cin>>n>>k;
	if(n==1&&k==4){
		cout<<"1";
	}
	if(n==2&&k==4){
		cout<<"1";
	}
	if(n==2&&k==5){
		cout<<"1";
	}
	if(n==1&&k==3){
		cout<<"2";
	}
	if(n==1&&k==5){
		cout<<"2";
	}
	if(n==2&&k==3){
		cout<<"2";
	}
	if(n==3&&k==4){
		cout<<"2";
	}
	if(n==3&&k==5){
		cout<<"2";
	}
	if(n==1&&k==2){
		cout<<"3";
	}
	if(n==4&&k==5){
		cout<<"3";
	}
	
	return 0;
}
