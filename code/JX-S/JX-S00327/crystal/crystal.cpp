#include <bits/stdc++.h>
using namespace std;
int n,m,q=0;

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[n] = {0};
    for(int i=0;i<n;i++){
        cin >> a[n-i];
    }
    for(int i=1;i<=n;i++){
        q=0;
        for(int j = i;j<=n;j++){
            if(a[i]<0){
                a[i]=-a[i];
                m-=a[i];
            }
            q+=a[i]-a[j];
            if(q==m){
                cout << n-i+1;
                return 0;
            }
        }
    }


    return 0;
}
