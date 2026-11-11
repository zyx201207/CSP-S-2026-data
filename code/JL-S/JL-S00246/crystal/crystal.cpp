#include<bits/stdc++.h>
using namespace std;
int a[600000],n,m,sum,mid,l,r,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    mid=(n+1)/2;
    r=mid+1;
    l=mid-1;
    while(m>=0){
        if(a[mid]-a[l]<=a[r]-a[mid]&&l>=0){
            l--;
            m-=a[mid]-a[l];
        }
        else{

            r++;
            m-=a[r]-a[mid];
        }
    }
    ans=r-l-1;
    cout<<ans;
    return 0;
}
