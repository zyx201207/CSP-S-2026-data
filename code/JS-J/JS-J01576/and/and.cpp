#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
ll f[200005];
ll ans;
void dfs(int dep,ll sum,int choice){
    if(choice==m){
        ans=max(ans,sum);
        return;
    }
    if(dep>n){
        return;
    }
    dfs(dep+1,sum,choice);
    if(sum==-1){
        sum=a[dep];
    }
    dfs(dep+1,(sum&a[dep]),choice+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll maxsum=0;
    ll special_ans1=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxsum=max(maxsum,a[i]);
        if(special_ans1==-1){
            special_ans1=a[i];
        }else{
            special_ans1=(special_ans1&a[i]);
        }
    }
    //cout<<"ok";

    if(m==1){
        cout<<maxsum;
        return 0;
    }else if(m==2){
        //cout<<"come";
        ll special_ans2=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                special_ans2=max(special_ans2,(a[i]&a[j]));
            }
        }
        cout<<special_ans2;
        return 0;
    }else if(m==n){
        cout<<special_ans1;
        return 0;
    }else{
        dfs(1,-1,0);
        cout<<ans;
    }

    return 0;
}
// orz rp++ csp-j1= made by cici
// hope 50pts orz orz
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
