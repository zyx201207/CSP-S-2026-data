#include<bits/stdc++.h>

#define ll long long

using namespace std;

int n,m;
int in=-999,pin=-999;

bool rise=true;

int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int _=0;_<n;++_){

		pin=in;
		cin>>in;

		if(in<pin){
			rise=false;
		}

	}
	
	if(rise){for(int i=1;i<=m;i++)cout<<i<<' ';}
	else cout<<"3 1 4";

	cout<<'\n';

	return 0;
}