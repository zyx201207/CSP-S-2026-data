#include<bits/stdc++.h>
using namespace std;
long long an, n, a[200005];
char c[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(), cout.tie();
    freopen("string.in","r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i] >> c[i];
    for (int i = 1, j = n; i < j;){
        if(c[i]!=c[j])
            an += min(a[i], a[j]);
        if(a[i]>a[j]){
            a[i] -= a[j];
            j--;
        }else if(a[i]<a[j]){
            a[j] -= a[i];
            i++;
        }else
            i++, j--;
    }
    cout << an;
    return 0;
}