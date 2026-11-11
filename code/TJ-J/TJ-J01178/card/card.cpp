#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.ot","w",stdout);
	int n,m;
	int pai[100010];
	cin >> n>>m;
	for(int i = 1;i<=n;i++){
		cin >> pai[i];
		if(i % 3 == 0){
			cout<<pai[i];
		}
	}

	return 0;
}
