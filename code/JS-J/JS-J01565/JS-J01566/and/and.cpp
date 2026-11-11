#include<bits/stdc++.h>
using namespace std;
const int max_n=2.1e5;
int n,m;
struct node{
    int dt,sl;
}a[max_n];
bool cmp(node x,node y){
    x.dt>y.dt;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].dt;
    sort(a+1,a+n+1,cmp);
    int ans=INT_MAX;
    for(int i=1;i<=m;i++) ans&=a[i].dt;
    cout<<ans;
    return 0;
}
