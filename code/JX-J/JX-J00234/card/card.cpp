#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main (){
    freopen ("card.in","r",stdin);
    freopen ("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector <ll> l(n);
    int t[55];
    for (int i=1 ; i<=n ; i++){
    for (int q=0 ; q<n ; q++){
        cin>>l[q];
           for (int j=1 ; j<=q ; j++){
            if (l[q] == l[j]) l.erase(l.begin(),l.begin()+j);
            }
        }
        for (int x=1 ; x<=50 ; x++){
            t[l[x]]++;
        }
    }
    for (int i=1; i<=50 ; i++){
        if (t[i] != 0) cout<<t[i];
    }
    return 0;
}
