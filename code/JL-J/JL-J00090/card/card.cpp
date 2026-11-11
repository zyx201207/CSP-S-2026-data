#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;
int n,m;
int a[N];
int b[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i];
        for(int j=1;j<=n;j++){
            if(b[j]==a[i]){
                b[1]=a[i];
                i=1;
            }
        }
        if()
    }
    return 0;
}
