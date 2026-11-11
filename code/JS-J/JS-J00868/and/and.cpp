#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,m,ans,maxn,kkk=2097151,maxnn,maxnnn;
void dfs(int idx,int cnt,int sum)
{
    if(cnt>m) return;
    if(cnt+(n-idx+1)<m) return;
    if(idx>n){
        //cout<<sum<<endl;
        maxn=max(maxn,sum);
        return;
    }
    //choose
    dfs(idx+1,cnt+1,(sum&a[idx]));

    //not choose
    dfs(idx+1,cnt,sum);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        kkk=kkk&a[i];
        maxnn=max(maxnn,a[i]);
    }
    if(m==n){
        cout<<kkk<<endl;
        return 0;
    }
    if(m==1){
        cout<<maxnn<<endl;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int k1;
                k1=a[i]&a[j];
                maxnnn=max(maxnnn,k1);
            }
        }
        cout<<maxnnn<<endl;
        return 0;
    }
    dfs(1,0,2097151);
    cout<<maxn<<endl;
}
