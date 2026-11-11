#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int sum = 0;
    for(int i = 2;i <= n;i ++){
            int ss = m;
            int s = a[i] * i;
        for(int j = 1;j <= i;j ++){
            ss += a[j];
        }
        if(ss >= s) sum = i;
        else break;
    }
    cout << sum;
    return 0;
}
