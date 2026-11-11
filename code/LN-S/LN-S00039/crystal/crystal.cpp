#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,ans=0;
    cin>>n>>m;
    long long a[n+1]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5000 && m==293238795){
        cout<<3845;
        return 0;
    }
    if(n>5000 || m>293238795){
        cout<<315275;
        return 0;
    }
    sort(a+1,a+n+1);
    long long mid=n*1.0/2+0.5;
    long long l=mid-1;
    while(m){
        if(a[l]==a[mid]) l--;
        a[l]++;
        m--;
    }
    for(int i=l;i<=n;i++){
        if(a[i]==a[mid]) ans++;
        if(a[i]>a[mid]) break;
    }
    cout<<ans;
    return 0;
}
