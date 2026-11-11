#include<bits/stdc++.h>
using namespace std;
long long a[10000000];
long long z[10000000],ans=0;
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        z[i]=((i-1)*(a[i]-a[i-1])+z[i-1]);
        if(z[i]>m){
            cout<<i-1;
            break;
        }

    }

    return 0;
}
