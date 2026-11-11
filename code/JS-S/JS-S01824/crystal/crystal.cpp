#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={},x=0;
int ans=0,maxans=0;
bool flag=true;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int d=a[2]-a[1];
    for(int i=1;i<=n;i++){
        if(a[i+1]-a[i]!=d){
            flag=false;
            break;
        }
    }
    if(flag){
        for(int i=1;i<=n;i++){
            if(m*2<i*i*d+i*d){
                cout<<i+1;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        x=0,ans=1;
        for(int j=i-1;j>=1&&x<=m;j--){
            if(a[i]-a[j]<=m-x){
                x+=a[i]-a[j];
                ans++;
            }
        }
        if(ans>maxans) maxans=ans;
    }
    cout<<maxans;
    return 0;
}
