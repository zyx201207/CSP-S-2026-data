#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n,a[10000],b[1000000],sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[i-1]){
            swap(a[i],a[i-1]);
        }
    }
    for(int i=1;i=m;i++){
        b[i]=a[i];
        if(i>1) sum=b[i]&b[i-1];
    }
    cout<<sum;
    return 0;
}
