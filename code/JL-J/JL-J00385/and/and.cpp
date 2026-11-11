#include<bits/stdc++.h>-
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[200001]
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long n=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=n){
            n=a[i];
        }
    }
    cout<<n;
    return 0;
}

