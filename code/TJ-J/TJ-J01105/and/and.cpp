#include<bits/stdc++.h>
using namespace std;
int n, m, a[100000005], ans;
bool cmp(int x, int y){
     return x > y;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    ans = a[0];
    for(int i = 1;i < m;i++){
        ans &= a[i];
    }
    cout << ans;
	return 0;
}
