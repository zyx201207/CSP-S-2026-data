#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],b[2005][2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==1) {
        cout<<a[n];
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            a[i]=a[i-1]&a[i];
        }
        cout<<a[n];
        return 0;
    }

    return 0;
}
