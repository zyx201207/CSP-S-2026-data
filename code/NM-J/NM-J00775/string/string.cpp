#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[10000000],i;
    char c;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i]>>c;
    }
    sort(a+1,a+n+1);
    cout<<a[2];
    return 0;
}