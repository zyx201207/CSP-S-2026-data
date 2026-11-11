#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int maxn=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout << maxn;
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout << maxn;
    }
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            int x=a[i];
            for(int j=2;j<=n;j++){
                if(j!=i){
                    x=x&a[i];
                }
            }
            maxn=max(maxn,x);
        }
        cout << maxn;
    }
    else cout << 49152;
    return 0;
}

