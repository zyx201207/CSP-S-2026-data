#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],num,ans,l;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    l=1,ans=1,num=0;
    for(int i=2;i<=n;i++){
        num=num+(a[i]-a[i-1])*(i-l);
        while(num>m&&l<i){
            num-=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
