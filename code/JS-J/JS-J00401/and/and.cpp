#include "bits/stdc++.h"
using namespace std;
const int N=2e5+5;
int n,m;
struct node{
    long long smax,sum;
}a[N];
long long ans;

int fun(long long x){
    long long ans=0,i=1;
    while(x){
        if(x&1)ans=i;
        i++;
        x/=2;
    }
    return ans;
}

bool cmp(node a,node b){
    if(a.smax!=b.smax)
        return a.smax>b.smax;
    return a.sum>b.sum;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].sum;
        a[i].smax=fun(a[i].sum);
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1].sum;
    for(int i=1;i<=m;i++)
        ans=ans&a[i].sum;
    cout<<ans;
    return 0;
}
