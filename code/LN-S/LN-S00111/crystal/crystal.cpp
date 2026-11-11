#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e5+2;
long long a[N],n,m;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    if(n == 1){
        cout << 1;
        return 0;
    }
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i] == a[i-1]) continue;
        long long sum = 0;
        for(int j=i-1;j>=1;j--){
            sum += a[i] - a[j];
        }
        if(sum > m){
            cout << i-1 << '\n';
            return 0;
        }
    }
    cout << n << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}