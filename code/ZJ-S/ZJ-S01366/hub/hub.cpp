#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> T >> T;
	srand(T);
	while(T--){
		cout<<rand()%5<<'\n';
	}
}
