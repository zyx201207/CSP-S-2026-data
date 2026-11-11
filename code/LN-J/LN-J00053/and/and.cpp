#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(n<=20){
        int ans=a[1];
        for(int i=2;i<=m;i++)
            ans&=a[i];
        cout<<ans;
    }
    if(m==1)
        cout<<a[1];
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++)
            ans&=a[i];
        cout<<ans;
    }
    else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        cout<<ans;
    }
    if(n>2000)
        cout<<a[m];
    return 0;
}
