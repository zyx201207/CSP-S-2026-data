#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[500001];
    int b[500001];
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int x=n;
    while(x>0){
        int maxi = a[n-x+1];
        for (int i=n-x+1;i<=n;i++){
            if(a[i] == a[i-1]){
                maxi = a[i];
            }
        }
        for (int i=maxi;i<=m;i++){
            b[i] += 1;
        }
        x--;
    }
    for (int i=1;i<=m;i++){
        cout << b[i] << " ";
    }
    return 0;
}
