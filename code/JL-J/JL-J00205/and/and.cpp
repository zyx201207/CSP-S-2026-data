#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mn=-1,qw=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<(n-m+1);i++){
        qw=a[i];
        for(int u=i+1;u<m+i+1;u++){
            qw=(qw&a[u]);
            if(qw>mn)
                mn=qw;
        }

    }
    cout<<mn;
    return 0;
}
