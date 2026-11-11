#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=-1;
    if(m==n){
        int x=1;
        for(int i=1;i<=n;i++){
            x&=a[i];
        }
        cout<<x;
    }
    if(m==n-1){
        int x=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    x&=a[j];
                }
            }
            maxn=max(maxn,x);
            x=1;
        }
        cout<<maxn;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    return 0;
}