#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	
	long long n,a,m,b;
	cin >> n >> a >> m >> b;
	if( n == m){
		cout <<"1";
	}else{
		
		
		cout << "0";
	}
	if( a == b){
		cout << "1";
		
	}else{
		
		cout << "0";
	}
	if(a == b){
		
		cout <<"1";
	}
	else{
		
		cout <<"0";
		
	}
	if( a+1&&a-1 == b){
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	
	return 0;
	

}
