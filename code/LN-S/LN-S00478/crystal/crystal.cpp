#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long cnt=0,ans=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cnt=a[n/2+1];
    for(int i=1;i<=n;i++){
        while(m>0&&a[i]<cnt){
            a[i]+=1;
            m--;
        }
        if(m<0)continue;
    }
    for(int i=1;i<=n;i--){
        if(a[i]==a[i+1]){
            ans++;
        }
    }
    if(ans>1)cout<<ans;
    else cout<<0;
    return 0;
}
