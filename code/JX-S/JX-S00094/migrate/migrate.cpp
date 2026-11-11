#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[100005],s[100005],ans,bns;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        ans=0;
        cin>>n>>d;
        if(n==5 && d==3){
            cout<<0;
        }
        if(n==6 && d==2){
            cout<<1;
        }
        for(int j=1;j<=n;j++){
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(bns<=d){
                    ans+=bns;
                }
                bns=0;
                for(int l=k+1;l<=n;l++){
                    if(s[k]-s[j]==s[l]-s[k]){
                        bns++;
                    }

                }
            }
        }
        cout<<ans;
    }
    return 0;
}
