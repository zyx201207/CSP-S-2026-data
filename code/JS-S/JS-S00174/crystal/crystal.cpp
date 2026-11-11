#include <bits/stdc++.h>
using namespace std;
int a[1000000000000000001];
long long m=100000000001;
int main(){
    int n,m,s=0,t=0;
    int ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]>s/5&&a[i]-s/5<m);{
            t=i;
            m=a[i];
        }
        if(a[i]<s/5&&s/5-a[i]<m);{
            t=i;
            m=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]>a[t]) a[i]-=a[t];
        else a[i]=a[t]-a[i];
    }
    sort(a,a+n);
    if(a[1]<=a[n]){
        for(int i=2;i<=n;i++){
            if(m>=a[i]){
                m-=a[i];
                ans++;
            }
            else break;
        }
    }
    else{
        for(int i=n-1;i>=1;i--){
            if(m>=a[i]){
                m-=a[i];
                ans++;
            }
            else break;
        }
    }
    cout<<ans;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    return 0;
}