#include<bits/stdc++.h>
using namespace std;

const int N=2*1e5+10;
int n,m,ans;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        int jbans=a[1];
        for(int i=2;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(j!=i){
                    jbans=jbans&a[j];
                }
            }
            ans=max(ans,jbans);
        }
        int ans2=a[2];
        for(int j=3;j<=n;j++){
            ans2=ans2&a[j];
        }
        ans=max(ans,ans2);
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    ans=max(ans,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int t=k+1;t<=n;t++){
                        ans=max(ans,a[i]&a[j]&a[k]&a[t]);
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==5){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int t=k+1;t<=n;t++){
                        for(int x=t+1;x<=n;x++){
                            ans=max(ans,a[i]&a[j]&a[k]&a[t]&a[x]);
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==6){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int t=k+1;t<=n;t++){
                        for(int x=t+1;x<=n;x++){
                            for(int y=x+1;y<=n;y++){
                                ans=max(ans,a[i]&a[j]&a[k]&a[t]&a[x]&a[y]);
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
    return 0;
}
