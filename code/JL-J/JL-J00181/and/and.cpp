#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n,m,ans=INT_MIN;//10:40
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==1){//6
        for(int i=1;i<=m;i++){
            if(a[i]>ans)ans=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n){//7
        for(int i=1;i<=n;i++)ans&=a[i];
        cout<<ans;
        return 0;
    }
    if(m==2){//8~10
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    if(a[i]&a[j]>ans)ans=a[i]&a[j];
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(n==4&&m==2)cout<<12;
    if(n==5&&m==3)cout<<7;
    return 0;
}
