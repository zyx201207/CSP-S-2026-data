#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(m==n){
        int b=a[1];
        for(int i=1;i<=n;i++){
            b=b&a[i];
        }
        cout << b;
        return 0;
    }
    if(m==1){
        int maxa=0;
        for(int i=1;i<=n;i++){
            maxa=max(maxa,a[i]);
        }
        cout << maxa;
        return 0;
    }
    if(m==2){
        int maxa=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n&&j!=i;j++){
                maxa=max(maxa,a[i]&a[j]);
            }
        }
        cout << maxa;
        return 0;
    }
    return 0;
}