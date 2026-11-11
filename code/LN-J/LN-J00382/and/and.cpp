#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum=INT_MAX;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int i=0;
    while(m--){
        sum=sum&a[n-i];
        i++;
    }
    cout<<sum;
    return 0;
}
