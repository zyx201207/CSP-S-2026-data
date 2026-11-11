#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	srand(time(0));
	while (t--){
		cout << rand()%10 + 1 << endl;
	}
}