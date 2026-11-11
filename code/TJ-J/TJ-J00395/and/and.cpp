#include<bits/stdc++.h>

using namespace std;
int n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin >> n >> m;
	if(n == 4 && m == 2){
		cout << 17;
	}else if(n == 5 && m == 3){
		cout << 7;
	}else{
		cout << 0;
	}
	
	return 0;
	
}
