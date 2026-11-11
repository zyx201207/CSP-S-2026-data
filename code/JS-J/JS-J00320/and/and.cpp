#include<bits/stdc++.h>
using namespace std;

long long a[200010];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,k=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxv=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=maxv) maxv=a[i];
    }
    cout<<maxv<<endl;
    return 0;
}