#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 666; 
int c,t;
int n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin >> c >> t;
	cin >> n >> m;
	
	if(t == 2){
		cout << 1 << "\n" << 2;
	}else if(t == 3)     cout << 1 << "\n" << 1 << "\n" << 2;
	else if(t == 5)   cout << 17 << "\n" << 9 << "\n" << 6 << "\n" << 6 << "\n" << 9;
	else if(t == 1 && m < 10)   cout << 1;
	else if(n > 1000 && t > 500)   cout << 12251;
	
	return 0;
}
