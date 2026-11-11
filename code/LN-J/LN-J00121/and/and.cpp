#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("and3.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int val[200000];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    
    if(n<=20){
        int ans=0;
        for(int i=1;i<(1<<n);i++){
            int sum=(1<<30)-1;
            int k=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){k++;sum&=val[j];}
            }
            if(k==m){
                ans=max(ans,sum);
            }
        }
        cout<<ans;
    }
    else if(m==1){
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,val[i]);
        }
        cout<<ans;
    }
    else if(m==n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans&=val[i];
        }
        cout<<ans;
    }
    else if(m==2){
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j)ans=max(val[i]&val[j],ans);
            }
        }
        cout<<ans;
    }
    else if(m==n-1){
        int ans=0;
        vector<int>pre(n);
        vector<int>suf(n);
        for(int i=1;i<n;i++){
            pre[i]&=pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suf[i]&=suf[i+1];
        }
        for(int i=0;i<n;i++){
            if(i==0)ans=max(ans,suf[i+1]);
            else if(i==n-1)ans=max(ans,pre[i-1]);
            else ans=max(ans,pre[i-1]&suf[i+1]);
        }
        cout<<ans;
    }
    else if((n&(n-1))==0){
        if(m*2>n)cout<<0;
        else cout<<n/2;
    }
    else{
        int ans=(1<<30)-1;
        sort(val,val+n,greater<int>());
        for(int i=0;i<m;i++){
            ans&=val[i];
        }
        cout<<ans;
    }
}