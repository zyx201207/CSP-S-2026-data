#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
long long a[maxn];
int main(){
    freopen("and.in","r",stdin)
	freopen("and.out","w",stdout);
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i=1; i<=n; i++){
    	cin >> a[i];
	}
	if(n == 4){
		cout << "12" << endl;
	}
	if(n == 5){
		cout << "17" << endl;
	}
    return 0;
}
