#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int n,m;
int crystal(int x){
    long long k=0;
    int j=1;
    for(int i=x-1;i>=1;i--){
        k+=a[x]-a[i];
        if(k>m)break;
        j++;
    }
    return j;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int maxn=0;
    for(int i=1;i<=n;i++){
        int t=crystal(i);
        maxn=max(maxn,t);
    }
    cout<<maxn;
    return 0;
}
