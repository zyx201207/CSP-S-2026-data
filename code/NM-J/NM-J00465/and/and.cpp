#include <bits/stdc++.h>
using namespace std;
int n,m,maxn,a,ans,hzx[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(m==1){
        for (int i = 1;i<=n;i++){
            cin >> a;
            maxn=max(maxn,a);
        }
        cout << maxn;
        return 0;
    }
    if(m==n){
        cin >> a; maxn=a;
        for (int i = 1;i<n;i++){
            maxn&=a;
        }
        cout << maxn;
        return 0;
    }
    for (int i = 1;i<=n;i++){
        cin >> hzx[i];
    }
    for (int i=1;i<=n-m+1;i++){
        for (int j = i+1;j<=n;j++){
            ans=hzx[i]&hzx[j];
            maxn=max(ans,maxn);
        }
    }
    cout << maxn;
    return 0;
}
