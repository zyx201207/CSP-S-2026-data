#include <bits/stdc++.h>
using namespace std;
int n,m,ans[300010];
int a[500010];
int f[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=500){
        for(int k=1;k<=n;k++){
            for(int i=k;i<=n;i++){
                int flag=0;
                for(int j=k;j<=i;j++){
                    if(a[j]==a[i]&&j!=i&&f[a[j]]>=1){
                        for(int p=j+1;p<i;p++){
                            if(f[a[p]]>=1)
                                f[a[p]]--;
                        }
                        break;
                        flag=1;
                    }
                }
                if(flag==0)
                    f[a[i]]++;
            }
            for(int i=k;i<=n;i++){
                if(f[a[i]]>=1){
                    ans[a[i]]++;
                    f[a[i]]=0;
                }
                else{
                    f[a[i]]=0;
                }
            }
        }
    }
    else{
        for(int k=1;k<=n;k++){
            for(int i=k;i<=n;i++){
                int flag=0;
                for(int j=i;j>=k;j--){
                    if(a[j]==a[i]&&j!=i&&f[a[j]]>=1){
                        for(int p=j+1;p<i;p++){
                            if(f[a[p]]>=1)
                                f[a[p]]--;
                        }
                        break;
                        flag=1;
                    }
                    else if(a[j]<=a[i]){
                        break;
                    }
                }
                if(flag==0)
                    f[a[i]]++;
            }
            for(int i=k;i<=n;i++){
                if(f[a[i]]>=1){
                    ans[a[i]]++;
                    f[a[i]]=0;
                }
                else{
                    f[a[i]]=0;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
