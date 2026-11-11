#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
struct node{
    int cnt=0;
    int sum;
}c[200005];
bool cmp(node a,node b){
    if(a.cnt!=b.cnt){
        return a.cnt>b.cnt;
    }else if(a.cnt==b.cnt&&a.sum!=b.sum){
        return a.sum>b.sum;
    }
}
int f(int n){
    int ans=0;
    int k=1;
    while(k<=n){
        if(n&k){
            ans++;
        }
        k=k<<1;
    }
    return ans;
}
int main(){
//    freopen("and.in","r",stdin);
//    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i].cnt=f(a[i]);
        c[i].sum=i;
    }
    sort(c+1,c+n+1,cmp);
    int ans=a[c[1].sum];
    for(int i=1;i<=n;i++){
        cout<<a[c[i].sum]<<endl;
    }
    for(int i=2;i<=m;i++){
        ans=ans&a[c[i].sum];
    }
    cout<<ans;
    return 0;
}
