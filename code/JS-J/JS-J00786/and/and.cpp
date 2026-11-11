#include<bits/stdc++.h>
using namespace std;
long long a[2000100];
void merge(int l,int r){
    if(l==r) return;
    int t[200100],mid=(r-l)/2+l;
    merge(l,mid);
    merge(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(l<=mid&&j<=r){
        if(a[i]>=a[j]){
            t[k++]=a[i++];
        }else{
            t[k++]=a[j++];
        }
    }
    while(i<=mid){
        t[k++]=a[i++];
    }
    while(j<=r){
        t[k++]=a[j++];
    }
    for(int i=l;i<=r;i++){
        a[i]=t[i];
    }
}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    merge(1,n);
    long long ans=a[1];
    for(int i=2;i<=m;i++){
        ans=ans&a[i];
    }
    cout<<ans;

    return 0;
}

