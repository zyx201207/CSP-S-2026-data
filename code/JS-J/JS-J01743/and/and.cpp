#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int n,m;
int ans=-1;
void dfs(int id,int sheng,int ad){
    if(sheng==0){
        ans=max(ans,ad);
        return;
    }
    for(int i=id+1;i<=n-sheng+1;i++){
        dfs(i,sheng-1,(ad&a[i]));
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

        int mm=0;
        for(int i=1;i<=n;i++){
            mm=max(mm,a[i]);
        }
        cout<<mm;
        return 0;

    }else if(m==2){

        int mm=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mm=max(mm,a[i]&a[j]);
            }
        }
        cout<<mm;
        return 0;

    }else if(m==n){

        int aans=a[1];
        for(int i=2;i<=n;i++){
            aans = aans&a[i];
        }
        cout<<aans;
        return 0;

    }else {

        for(int i=1;i<=n-m+1;i++){
            dfs(i,m-1,a[i]);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
