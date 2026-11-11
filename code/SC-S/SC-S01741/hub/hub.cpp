#include <bits/stdc++.h>
using namespace std;
int c,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(time(0));
	cin>>c>>T;
	while(T--){
		cout<<rand()%3;
	}
	return 0;
}