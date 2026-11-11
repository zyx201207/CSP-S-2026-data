#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
const int MAXN=2e5+5;
int a[MAXN];
int ans;
bool vis[MAXN];

void dfs(int idx,int c){
    if(idx==m){
        ans = max(ans,c);
        //cout<<ans<<" ";
        return;
    }
    int temp=c;
    for(int i = 0;i<n;i++){
        if(!vis[i]){
            c&=a[i];
            vis[i]=1;
            dfs(idx+1,c);
            vis[i]=0;
            c = temp;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++) cin>>a[i];
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
    }
    else if(n==m){
        int cur = a[0];
        for(int i = 1;i<n;i++){
            cur = cur&a[i];
        }
        cout<<cur;
    }
    else if(m==2){
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i==j) continue;
                else ans = max(ans,i&j);
            }
        }
        cout<<ans;
    }
    else if(n==m+1){
        int suf[MAXN]={},pref[MAXN]={};
        pref[0]=a[0];
        for(int i = 1;i<n;i++){
            pref[i] = pref[i-1]&a[i];
        }
        suf[n-1] = a[n-1];
        for(int j = n-2;j>=0;j--){
            suf[j] = suf[j+1]&a[j];
        }
        int ans = suf[1];
        for(int i = 1;i<n-1;i++){
            int cur = pref[i-1]&suf[i+1];
            ans = max(ans,cur);
        }
        ans = max(ans,pref[n-1]);
        cout<<ans;
    }
    else{
        for(int i = 0;i<n;i++){
            vis[i]=1;
            dfs(1,a[i]);
            vis[i]=0;
        }
        //for(int i = 0;i<n;i++) cout<<vis[i]<<" ";
        //cout<<endl;
        cout<<ans;
    }
}
