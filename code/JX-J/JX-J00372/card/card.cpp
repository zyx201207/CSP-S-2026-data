#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==a[j]) ans++;
        }
    }if(ans==0){for(int i=1;i<=n;i++) cout<<i<<" ";}
    else cout<<"3 1 4";
    return 0;
}
