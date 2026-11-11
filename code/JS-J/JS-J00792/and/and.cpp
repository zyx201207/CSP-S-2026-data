#include<bits/stdc++.h>
using namespace std;
int n,m;long long a[200005],ans=0;
void dfs(long long v,int step,int id){
    if((n-id)<(m-step)){
        return;
    }
    if(step==m){
        ans=max(ans,v);
        return;
    }
    for(int i=id+1;i<=n;i++){
        dfs(v&a[i],step+1,i);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    if(n-m==1){
        long long num=0;
        for(int i=1;i<=n;i++){
            num=0;
            for(int j=1;j<=n;j++){
                if(i!=j)
                {
                    num&=a[j];
                }
            }
            ans=max(num,ans);
        }
        cout<<ans;
    }
    else{
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-m+1;i++){
            dfs(a[i],1,i);
        }
        cout<<ans;
    }
    return 0;
}
