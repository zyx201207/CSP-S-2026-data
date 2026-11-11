#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n>>m;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    int x=0;
    while (x<n){
        x++;
        for (int i=1;i<=n;i++){
            if (a[x]==a[i]){
                a[i]=0;
                cout <<n-i<<" ";
                break;
            }
        }

    }
    return 0;
}
