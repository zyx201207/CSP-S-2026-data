#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000],ans;
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(long long i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    ans = a[0];
    for(long long i = 1;i<m;i++){
        ans = (ans&a[i]);
    }
    cout<<ans;
}
