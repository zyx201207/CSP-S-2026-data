#include<bits/stdc++.h>
using namespace std;
long long a[10000];
int main(){
    long long n,m;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>t)
            t=a[i];
    }
    cout<<t;
    return 0;
}
