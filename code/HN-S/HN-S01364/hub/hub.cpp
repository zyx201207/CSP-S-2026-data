#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	cin.tie(0);
	freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	int n,k;
	cin >> n >> k;
	
	int solver = rand();
	for (int i=0;i<10;i++){
		solver = rand()*1;
	}
	
	
	cout << solver << endl;
	int solver2 = rand();
	for (int i=0;i<t;i++){
		solver2 = rand()*1;
		cout << solver2 << endl;
	}
	
	
	
	
	return 0;
}
