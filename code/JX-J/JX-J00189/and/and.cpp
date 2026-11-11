#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,s,a[500001]={},q=0;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    q=a[n-s+1];
    for(int i=n-s+2;i<=n;i++){
        q=q&a[i];
    }
    cout<<q;
    return 0;
}
