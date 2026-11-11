#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[200010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=a[1];
    if(n==m){
        for(int i=2;i<=n;i++){
            maxn=maxn and a[i];
        }
    }
    else if(m==1){
        for(int i=2;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
    }
    else if(m==2){
    maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int ad=a[i]&a[j];
                maxn=max(maxn,ad);
            }
        }
    }
    cout<<maxn;
    return 0;
}
