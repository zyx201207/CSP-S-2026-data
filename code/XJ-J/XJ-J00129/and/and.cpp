#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,q;

    cin>>n>>q;
    long long a[100001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int z=a[n-1];
    for(int j=n-1;j>=n-q;j--){
        z=a[j]&z;
    }
    cout<<z;
    return 0;
}
