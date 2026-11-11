#include <bits/stdc++.h>;
using namespace std;
int n,m,a[500010],sum=0,maxn=-1;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        maxn=max(maxn,a[i]);
    }
    if (m==1){
        cout << maxn;
    }
    else if (m==n){
        int sum = a[1];
        for (int i = 2;i <= n;i++){
            sum&=a[i];
        }
        cout << sum;
    }
    else{
        cout << "nizhou";
    }
    return 0;
}
