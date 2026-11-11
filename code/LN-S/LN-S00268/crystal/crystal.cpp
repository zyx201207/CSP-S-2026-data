#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],b[500005],m,s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    sort(a+1,a+n+1);
    long long v=m,ma=0,ans=0;
    for(int i=n;i>=1;i--){
        v=m;
        ma=0;
        for(int j=i;j>=1;j--){
            if(v>=a[i]-a[j])
                ma++,v-=a[i]-a[j];
            else
                break;
        }
        ans=max(ma,ans);
    }
    cout<<ans;
    return 0;
}
