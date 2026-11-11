#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
        return 0;
    }
    int cnt=a[n-1];
    for(int i=1;i<m;i++){
        cnt= cnt&a[n-i-1];
    }
    cout<<cnt;
    return 0;
}
