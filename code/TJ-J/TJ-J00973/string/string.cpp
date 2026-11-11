#include <bits/stdc++.h>;
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a;string c;
	string l="";
	for(int i=1;i<=n;i++){
		cin >> a >> c;
		l+=a*c;
	}
	
	return 0;
} 
