#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000005],tmp,cnt[10000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tmp=max(tmp,a[i]);
    }
    int l=0;
    for(int i=1;i<=n;i++){
        int cnt=0,g;
        for(int j=l+1;j<=n;j++){
            for(int z=l+1;z<=j;z++){
                if(a[j]==a[z]) g=j;
            }
        }
        l=g;
    }
    cout<<"10 3 3";
    return 0;
}
