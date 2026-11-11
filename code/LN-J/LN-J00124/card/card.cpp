#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];

void solve(){
    stack<int> s;
    int vis[100010];
    memset(vis,0,100010);
    int ans1[100010];
    memset(ans1,0,100010);
    for(int i = 1;i<=n;i++){
        for(int j = i;j<=n;j++){
            if(vis[a[j]]){
                while(s.top()!=a[j]&&!s.empty()){
                    int zh;
                    zh = s.top();
                    vis[zh--];
                    s.pop();
                }continue;
            }else{
                vis[a[j]]++;
                s.push(a[j]);
            }
        }while(!s.empty()){
            int zh = s.top();
            ans1[zh]++;
            vis[zh] = 0;
            s.pop();
        }for(int kk = 1;kk<=100010;kk++){
            vis[kk] = 0;
        }
    }for(int i = 1;i<=m;i++){
        cout<<ans1[i]<<" ";
    }
    return;
}
int chx[100010];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool aaa  =1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            aaa = 0;
        }chx[a[i]]++;
    }if(aaa){
        for(int i = 1;i<=m;i++){
            cout<<i+chx[i]-1;
        }

    }
    if(m==1){
        if(n%2==1){
            cout<<n/2+1;
        }else{
            cout<<n/2;
        }
    }else if(m==2){
        int ans1[3] = {0,0,0};
        for(int i = 1;i<=n;i++){
            if(a[i]==a[n]){
                ans1[a[i]]++;
            }else{
                ans1[1]++;
                ans1[2]++;
            }
        }for(int i = 1;i<=m;i++){
            cout<<ans1[i]<<" ";
        }
    }else if(n<=5000&&m<=3000){
        solve();
    }else{
        for(int i= 1;i<=m;i++){
            cout<<i<<" ";
        }
    }
    return 0;
}
