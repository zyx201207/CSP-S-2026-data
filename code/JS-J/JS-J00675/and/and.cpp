#include <bits/stdc++.h>
using namespace std;
int n,m,ans,maxx,sum;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ans=-1;
    maxx=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(maxx<a[i]){
            maxx=a[i];
        }
    }
    if(m==1){
        cout<<maxx<<endl;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(j==i)continue;
                if((a[j]&a[i])>ans) ans=(a[j]&a[i]);
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m==n-1){
        sum=pow(2,30)-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                sum=(sum&a[j]);
            }
            if(sum>ans){
                ans=sum;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    if(m==n){
        ans=pow(2,30)-1;
        for(int i=1;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    cout<<maxx<<endl;
    return 0;
}
