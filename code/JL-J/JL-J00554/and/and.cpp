#include<bits/stdc++.h>
using namespace std;
const int q=2e5+10;
long long a[q],a1[q],n,m,a2,max1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            a1[a2]=a[i]&a[j];
            max1=max(max1,a1[a2]);
        }
    }
    cout<<max1;
    return 0;
}
