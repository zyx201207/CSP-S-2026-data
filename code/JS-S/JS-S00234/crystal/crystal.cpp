#include <bits/stdc++.h>
using namespace std;

long long n,m,cnt;
long long a[500005],c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(m--){
        a[1]++;
        sort(a+1,a+n+1);
    }
    for(int i=1;i<=n;i++){
        c[a[i]]++;
    }
    int maxn=-1;
    for(int i=1;i<=n;i++){
        if(c[i]>maxn) maxn=c[i];
    }
    cout<<maxn;
    return 0;
}
