#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin >> c >> T;
	srand(time(0));
	for(int i=1;i<=T;i++)cout << rand()*rand()%rand() << "\n";
}
