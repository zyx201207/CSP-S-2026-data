
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],k,k2[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]==a[i+1]){
            k++;
        }
    }
    if(k==n-1){
        cout<<a[1];
        return 0;
    }
    k=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==a[j]){
                k2[k]=a[i];
                k++;
            }
        }
    }
    sort(k2+1,k2+1+k);
    cout<<k2[k-1];
    return 0;
}
