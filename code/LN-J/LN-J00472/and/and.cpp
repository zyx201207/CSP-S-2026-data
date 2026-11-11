#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,ans=0;
    cin>>n>>m;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    long long sum;
    if(m==1){
        cout<<ans;
    }
    else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(m==3){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    ans=max(ans,a[i]&a[j]&a[k]);
                }
            }
        }
        cout<<ans;
    }
    else if(m==4){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    for(int g=k+1;g<=n;g++){
                        ans=max(ans,a[i]&a[j]&a[k]&a[g]);
                    }
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


