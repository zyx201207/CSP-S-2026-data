#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
int a[N];
void dfs(int pos,int cnt,int s,int &ans){
    if(cnt==0){
        ans=max(ans,s);
        return ;
    }
    //cout<<pos<<' '<<cnt<<"\n";
    //cout<<n<<"\n";
    if(pos>n){
        return ;
    }
    dfs(pos+1,cnt,s,ans);
    dfs(pos+1,cnt-1,(s==0?a[pos]:s&a[pos]),ans);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int ma=0;
        for(int i=1;i<=n;i++){
            ma=max(ma,a[i]);
        }
        cout<<ma;
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }else if(m==2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else if(m==n-1){
        vector<int>pre(n+5,0),suf(n+5,0);
        pre[1]=a[1];
        suf[n]=a[n];
        for(int i=2;i<=n;i++){
            pre[i]=pre[i-1]&a[i];
        }
        for(int i=n-1;i>=1;i--){
            suf[i]=suf[i+1]&a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==1){
                ans=max(ans,suf[i+1]);
            }else if(i==n){
                ans=max(ans,pre[i-1]);
            }else{
                ans=max(ans,pre[i-1]&suf[i+1]);
            }
        };
        cout<<ans;
    }else{
        int ans=0;
        dfs(1,m,0,ans);
        cout<<ans;
    }

    return 0;
}
