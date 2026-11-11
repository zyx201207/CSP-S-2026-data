#include<bits/stdc++.h>
using namespace std;

int a[10000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,c=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m+i;j++){
            c=max(c,a[j]&a[j+1]);
        }
    }
    cout << c;
    return 0;

}
