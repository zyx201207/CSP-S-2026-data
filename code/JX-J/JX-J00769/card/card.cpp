#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int long long

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int pos=0;
        for(int j=1;j<=m;j++){
            if(a[j]>=i){
                pos=j;
                break;
            }
        }
        cout<<pos<<' ';
    }
    return 0;
}
