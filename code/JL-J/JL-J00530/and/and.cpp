
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max1=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }for(int i=1;i<n;i++){
        if((a[i]&m)>(a[i+1]&m))
            max1=(a[i]&m);
        else max1=(a[i+1]&m);
    }cout<<max1;
}
