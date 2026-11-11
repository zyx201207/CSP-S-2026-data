#include<bits/stdc++.h>
using namespace std;
struct node{
    long long u;
    char v;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i].u>>a[i].v;
    }
    long long ans=0;
    long long r=n,l=1;
    while(l<r){
        if(a[l].u==0){
            l++;
        }
        if(a[r].u==0){
            r--;
        }
        if(a[l].v==a[r].v){
            long long minn=min(a[l].u,a[r].u);
            a[l].u-=minn;
            a[r].u-=minn;
        }
        else{
            long long minn=min(a[l].u,a[r].u);
            a[l].u-=minn;
            a[r].u-=minn;
            ans+=minn;
        }
    }
    cout<<ans;
    return 0;
}
