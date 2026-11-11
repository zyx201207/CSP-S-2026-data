#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
int a[500000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-2;i>=0;i--){
        a[i+1]=a[i+1]-a[i];
    }
    a[0]=0;
    for(int i=1;i<n;i++){
        a[i]+=a[i-1];
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(j-i<=ans) break;
            if(a[j]-a[i]<=m){
                ans=max(ans,j-i+1);
            }
        }
        if(n-1-i<=ans) break;
    }
    cout<<ans;
    return 0;
}
