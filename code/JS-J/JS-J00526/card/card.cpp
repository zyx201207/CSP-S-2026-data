#include<bits/stdc++.h>
using namespace std;
int m,n;
const int maxn=5e5+10;
int a[maxn],b[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i<=m){
        ans+=b[i];
        cout<<ans<<' ';
        }
        else break;
    }
    return 0;
}
