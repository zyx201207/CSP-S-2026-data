#include <bits/stdc++.h>
using namespace std;
int n,m;
long long aa[500005],ans;
/*long long dfs(int x){
    int ans=0;
    if(x==0){
        for(int i=1;i<=depth;i++){
            if(i==1)ans=b[1];
            else ans=ans&b[2];
        }
        return ans;
    }
    for(int i=1;i<=n;i++){

    }
    return dfs(x-1);
}*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>aa[i];
    }


    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j)
                    ans=max(aa[i]&aa[j],ans);
            }

        }// 1 10 100 100  4
    }
    else if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(i!=j!=k)ans=max(ans,aa[i]&aa[j]&aa[k]);
                }
            }

        }
    }
    else if(m==4){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    for(int l=1;l<=n;l++)
                        if(i!=j!=k!=l)ans=max(ans,aa[i]&aa[j]&aa[k]&aa[l]);
                }
            }

        }
    }
    else if(m==1){
        for(int i=1;i<=n;i++)ans=max(ans,aa[i]);
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    for(int l=1;l<=n;l++)
                        for(int m=1;m<=n;m++)
                            if(i!=j!=k!=l!=m)ans=max(ans,aa[i]&aa[j]&aa[k]&aa[l]&aa[m]);
                }
            }

        }
    }
    cout<<ans;
}
