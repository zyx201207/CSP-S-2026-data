#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],s[N],ans=INT_MIN;
bool CCCP(int x,int y){
    return x>y;
}
int main(){
    //best wishes to____
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,CCCP);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        //cout<<"________"<<i<<"\n\n\n";
        long long l=i,r=n;
        while(l<r){
            long long mid=(l+r+1)/2;
            //cout<<l<<" "<<r<<" "<<mid<<"\n";
            //cout<<(s[mid]-s[i-1])<<"\n";
            //cout<<(a[i]*(mid-i+1)-(s[mid]-s[i-1]))<<"\n";
            if((a[i]*(mid-i+1)-(s[mid]-s[i-1]))<=m) l=mid;
            else r=mid-1;
            //cout<<l<<" "<<r<<"\n";
        }
        //cout<<"*"<<l-i+1<<"\n";
        ans=max(ans,l-i+1);
    }
    cout<<ans;
}
