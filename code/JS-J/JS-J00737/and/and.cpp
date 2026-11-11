#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,v;
bool vis[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        ans=-1e18;
        for (int i=0;i<n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
    }
    else if(m==n){
        ans=a[0];
        for (int i=0;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        ans=-1e18;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if(i==j) continue;
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(n<=20){
        long long pre=pow(2,63)-1,now;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(!vis[j]&&now<pre&a[j]){
                    now=max(now,pre&a[j]);
                    v=j;
                }
            }
            vis[v]=true;
            pre=now;
        }
        cout<<now;
    }
    else{
        sort(a,a+n);
        cout<<a[n-m-1];
    }
}
