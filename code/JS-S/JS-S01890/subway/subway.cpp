#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long a[N],m,n;
long long ans,t[N];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a,a + 1 + n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
