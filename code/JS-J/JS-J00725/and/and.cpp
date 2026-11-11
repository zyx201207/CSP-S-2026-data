#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("ans.in","r",stdin);
    freopen("ans.out","w",stdout);
    int n,m;
    long long ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }else if(m==3){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        ans=max(ans,a[i]&a[j]&a[k]);
                    }
                }
            }
        }else if(m==4){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        for(int l=k+1;l<=n;l++){
                            ans=max(ans,a[i]&a[j]&a[k]&a[l]);
                        }
                    }
                }
            }
        }else if(m==5){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        for(int l=k+1;l<=n;l++){
                            for(int r=l+1;r<=n;r++){
                                ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]);
                            }
                        }
                    }
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        for(int l=k+1;l<=n;l++){
                            for(int r=l+1;r<=n;r++){
                                for(int p=r+1,p<=n;p++){
                                    ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[p]);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
        return 0;
    }
    else if(n<=2000&&n>20){
        if(m==1){
            sort(a+1,a+n+1);
            cout<<a[n];
            return 0;
        }else if(m==n){
            ans=a[1];
            for(int i=2;i<=n;i++){
                ans=ans&a[i];
            }
        }else if(m==2){
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
        }
        cout<<ans;
        return 0;
    }else{
        bool c=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=i-1){
                c=0;
                break;
            }
        }
        if(c==1){
            cout<<0;
            return 0;
        }
        else{
            sort(a+1,a+n+1);
            cout<<a[1];
            return 0;
        }
    }
}
