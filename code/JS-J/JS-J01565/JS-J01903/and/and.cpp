#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct sz{
    int sw;
    long long dx;
}a[N];
int fj(long long n){
    int sum = 0;
    while(n > 0){
        n /= 2;
        sum++;
    }
    return sum;
}
bool cmp(sz a,sz b){
    if(a.sw != b.sw) return a.sw > b.sw;
    else return a.dx >= b.dx;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i].dx;
        a[i].sw = fj(a[i].dx);
    }
    sort(a + 1,a + n + 1,cmp);
    long long ans = a[1].dx;
    for(int i = 2;i <= m;i++){
        ans = ans & a[i].dx;
    }
    cout << ans;
    return 0;
}
