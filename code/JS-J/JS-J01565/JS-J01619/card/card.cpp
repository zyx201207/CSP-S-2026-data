#include<bits/stdc++.h>
using namespace std;

//48 + 4 + 8

void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    bool f=1;
    for(int i=2;i<=n;i++) f&=(a[i]>=a[i-1]);
    if(f){//4
        vector<int> ans(m+1);
        for(int i=1;i<=n;i++) ans[a[i]]++;
        for(int i=1;i<=m;i++) ans[i]+=ans[i-1];
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
        cout<<endl;return;
    }
    if(n<=5000){//48
        vector<int> ans(m+1),vis(m+1);
        stack<int> c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) vis[j]=0;
            for(int j=i;j<=n;j++){
                if(!vis[a[j]]) {c.push(a[j]),vis[a[j]]=1;continue;}
                while(c.top()!=a[j]) vis[c.top()]=0,c.pop();
            }
            while(c.size()) ans[c.top()]++,c.pop();
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
        cout<<endl;return;
    }
    if(m<=2){//8
        int c1=0,c2=0;
        for(int i=1;i<=n;i++){
            if(a[i]==a[n])
                if(a[i]==1) c1++;
                else c2++;
            else c1++,c2++;
        }
        cout<<c1<<' '<<c2<<endl;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
}
