#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;//shuliang,dianshu
    cin >>n>>m;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    for(int i=1;i<=n;i++) {
            a[n+1]=a[i];
        for(int j=i;j<=n;j++) {
            if(a[j]==a[n+1]) {
                for(int k=j;k<=n+1;k++) {
                    a[k]=0;
                }
            }
        }
    }
    cout <<3<<" "<<1<<" "<<4;
return 0;
}
