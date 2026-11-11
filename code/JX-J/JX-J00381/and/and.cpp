#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxn=0;
    for(int i=1;i<=n;i++){
        long long cnt=1;
        long long x=a[i];
        for(int j=i+1;j<=n&&cnt<m;j++){
            x=(x&a[j]);
            cnt++;
        }
        maxn=max(maxn,x);
    }
    cout<<maxn;
    return 0;
}

