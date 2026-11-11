#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];
int s=-1;
int ans=0;
inline void dfs(int i,int sum){
    if(sum==m+1){
        s=max(ans,s);
        return ;
    }
    if(sum==1){
        ans=a[i];
    }
    for(int j=i+1;j<=n;j++){
        ans=ans&a[j];
        dfs(j,sum+1);
    }
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int s1=0;
        for(int i=1;i<=n;i++){
            s1=max(s1,a[i]);
        }
        cout<<s1;
        return 0;
    }
    else if(m==n){
        int s2=a[1];
        for(int i=1;i<=n;i++){
            s2=s2&a[i];
        }
        cout<<s2;
        return 0;
    }
    else if(m==2){
        int s3=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                s3=max(s3,a[i]&a[j]);
            }
        }
        cout<<s3;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        dfs(2,2);
        cout<<s;
        return 0;
    }
    return 0;
}
