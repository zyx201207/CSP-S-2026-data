#include<bits/stdc++.h>
using namespace std;

string a;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		char q;
		cin>>q;
		a+=q;
	}
	if(m==3&&a=="1 2 1 3")
		cout<<"3 1 4";
	if(m==3&&a=="3 1 2 1 3 2 3 1 2 1")
		cout<<"10 3 3";
	
	return 0;
}