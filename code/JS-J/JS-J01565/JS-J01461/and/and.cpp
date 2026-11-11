#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    cout<<a[n-m];
    return 0;
}
