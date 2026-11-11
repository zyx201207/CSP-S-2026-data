#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a>>b;
	if(a<b){
		cout << a;	
	}else{
		cout << b;	
	}
	return 0;
}
