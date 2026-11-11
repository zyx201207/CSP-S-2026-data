#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n,ans=0,len;
    cin>>n;
    char a[n];
    long long b[n];
    for(int i=0;i<n;i++){
       cin>>b[i]>>a[i];
    }
    long long l=0,r=n-1,ll=b[0],rl=b[n-1];
    while(l<r){
       len=min(ll,rl);
       if(a[l]!=a[r]){
           ans+=len;
       }
       if(len==ll){
           rl-=len;
           l++;
           ll=b[l];
       }else{
           ll-=len;
           r--;
           rl=b[r];
       }
    }
    cout<<ans;
    return 0;
}
