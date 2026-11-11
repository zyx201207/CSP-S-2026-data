
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1];
    if(m==1){
        cout<<a[1];
        return 0;
    }else if(m==2){
        int ma=-2e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    ma=max(ma,a[i]&a[j]);
                }
            }
        }
        cout<<ma;
        return 0;
    }else if(m==n){
        for(int i=1;i<=n;i++)
        {
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    else{
        for(int i=1;i<=m;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
}
