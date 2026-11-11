#include<bits/stdc++.h>
using namespace std;
int a[200005],ans=0,m,k;
bool cmp(int a,int b){
    return a>b;
}
void dfs(int cnt,int sum,int x){
    if(cnt==m+1){
        if(x==k+1){
            ans=max(ans,sum);
            //cout<<sum<<endl;
        }
        return ;
    }
    for(int i=0;i<=1;i++){
            //cout<<i;
        if(i==0){
            dfs(cnt+1,sum,x);
        }
        if(i==1){
            //cout<<x<<endl;
            if(x==1){
                dfs(cnt+1,a[cnt],x+1);
                //cout<<sum<<endl;
            }
            else{
                dfs(cnt+1,sum&a[cnt],x+1);
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //int m,k;
    cin>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    if(k==1){
        for(int i=1;i<=m;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    else{
        if(k==2){
            for(int i=1;i<=m;i++){
                for(int j=i+1;j<=m;j++){
                    ans=max(ans,(a[i]&a[j]));
                }
            }
            cout<<ans;
            return 0;
        }
        else{
            if(k==m){
                ans=a[1];
                for(int i=2;i<=m;i++){
                    ans&=a[i];
                }
                cout<<ans;
                return 0;
            }
            else{
                if(m>2000){
                    sort(a+1,a+m+1,cmp);
                    ans=a[1];
                    for(int i=2;i<=k;i++){
                        ans&=a[i];
                    }
                    cout<<ans;
                    return 0;
                }
                else{
                    dfs(1,1,1);
                    cout<<ans;
                    return 0;
                }
            }
        }
    }
    return 0;
}
