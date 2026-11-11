#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200007];
int res=-1e9;
void p(int now,int cho,int zhi){
    if(cho==0){
        res=max(zhi,res);
        return ;
    }
    for(int i=now+1;i<=n-cho+1;i++){
        p(i,cho-1,zhi&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(a[i],ans);
        }
        cout<<ans;
    }
    else if(m==2){
        int ans=-1e9;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[2];
        }
        cout<<ans;
    }
    else{
        p(0,m,1073741823);
        cout<<res;
    }
    return 0;
}
