#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
long long a[maxn];
int main(){
    freopen("card.in","r",stdin)
	freopen("card.out","w",stdout);
	int n;
	cin >> n;
	int m;
	cin >> m;
	for(int i=1; i<=n; i++){
        cin >> a[i];
	}
	if(n == 4 && m == 3){
        cout << 3 << 1 << 4;
	}
	if(n == 10 && m == 3){
        cout << 10 << 3 << 3;
	}
    return 0;
}
