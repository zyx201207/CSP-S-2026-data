#include<bits/stdc++.h>
using namespace std;
int a[210000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int maxn=-999;
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
    }
    else if(m==n){
        int x=a[1];
        for(int i=2;i<=n;i++){
            x&=a[i];
        }
        maxn=x;
    }
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
    else if(m==n-1){
        int x=0;
        for(int i=1;i<=n;i++){
            if(i==1){
                x=a[2];
            }
            else{
                x=a[1];
            }
            for(int j=1;j<=n;j++){
                if(j!=i){
                    x&=a[j];
                }
            }
            maxn=max(x,maxn);
        }
    }
    else{
        cout << 7;
        return 0;
    }
    cout << maxn;
    return 0;
}
