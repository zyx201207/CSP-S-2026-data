#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
int n,m;
long a[MAX];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;

    for(int i = 1;i <= n;i++)
        cin >> a[i];
    if(m == 1){
        long maxx = -1;
        for(int i = 1;i <= n;i++) maxx = max(maxx,a[i]);
        cout << maxx;
        return 0;
    }
    //sort(a + 1,a + n + 1);
    sort(a + 1,a + n + 1,greater<>());
    long ans1 = (a[1] & a[2]);
    for(int i = 3;i <= m;i++){
        ans1 &= a[i];
    }
    cout << ans1;

    return 0;
}


