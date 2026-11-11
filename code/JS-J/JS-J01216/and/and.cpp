#include<bits/stdc++.h>
using namespace std;
long long p[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>p[i];
    }
    cout<<p[n/2+n%2];
    return 0;
}
