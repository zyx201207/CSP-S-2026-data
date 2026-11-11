#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int n,m,a,b;
	cin>>n,m,a,b;
	if(n==a){
		if(m==b){
			cout<<"1000"; 
		}
		if(m!=b){
			cout<<"1100";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}



