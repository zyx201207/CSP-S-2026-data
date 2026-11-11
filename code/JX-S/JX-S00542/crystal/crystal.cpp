#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long check(int mid){
    long long x=m,ans=1;
    for(int i=mid-1;i>=1;i--){
        if(x>=a[mid]-a[i]){
            x-=a[mid]-a[i];
            //cout<<a[mid]-a[i]<<" "<<x<<" ";
            ++ans;
            //cout<<ans<<endl;
        }else break;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long mas=0;
    for(int i=1;i<=n;i++){
        mas=max(mas,check(i));
    }
    cout<<mas;
    return 0;
}
