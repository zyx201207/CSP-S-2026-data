#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ma=0,mi,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            ans=a[i];
        }else{
            ans=ans&a[i];
        }
        if(a[i]>ma){
            mi=i;
            ma=a[i];
        }
    }
    if(m==1){
        cout<<a[mi];
    }else{
        cout<<ans;
    }
    return 0;
}
