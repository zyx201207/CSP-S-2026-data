#include<bits/stdc++.h>
using namespace std;
int m,n,ans=1,cnt=0;
int a[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=n-i;j>i+1;j--){
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=n&&cnt<=m;i++){
        if(a[i]<a[i+1]){
            a[i]++;
            cnt++;
        }
        else if(a[i]>=a[i+1]) ans++;
    }
    cout<<ans;
    return 0;
}
