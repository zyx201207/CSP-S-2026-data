#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],qa[500010],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        qa[i]=a[i];
        qa[i]+=qa[i-1];
    }
    long long l=1,r=n,mid;
    bool flag=0;
    while(l<=r){
        flag=0;
        mid=(l+r)/2;
        for(int i=1;i<=n-mid+1;i++){
            if(a[i+mid-1]*mid-qa[i+mid-1]+qa[i-1]<=m){
                flag=1;
                break;
            }
        }
        if(flag){
            ans=max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
