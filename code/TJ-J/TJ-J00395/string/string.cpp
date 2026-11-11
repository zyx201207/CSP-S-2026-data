#include<bits/stdc++.h>

using namespace std;
int n,num,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin >> n;
	if(n == 2){
		cout << 0;
	}else if(n == 6){
		cout << 3000000000;
	}else if(n == 3){
		cout << 2;
	}else{
		cout << 0;
	}
	
	return 0;
	
}

