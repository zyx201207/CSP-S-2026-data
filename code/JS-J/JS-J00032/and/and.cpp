#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
long long pown (int n,int ci){
    while (ci--){
        if (ci > 1) n *= n;
    }
    return n;
}
int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int start = 1;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort (a + 1,a + n + 1,greater<int>());
    for (int i = 1;i <= n;i++){
        int flag = 1;
        for (int j = 1;j <= 30;j++){
            if (pown(2,j) == a[i]) flag = 0;
        }
        if (flag) break;
        else start++;
    }
    do{
        int sum = a[1];
        for (int i = 1;i <= m;i++){
            sum = sum & a[i];
        }
        ans = max(sum,ans);
    }while(next_permutation(a + start,a + n + 1));
    cout << ans;
    return 0;
}

