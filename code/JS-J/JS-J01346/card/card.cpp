#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5*100000+10;

stack<int> a,b;
queue<int> num;
int n,m;
int cnt[N];
int ans[N];
bool f[N];

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cnt[i];
    }
    for(int i=n;i>=1;i--){
        a.push(cnt[i]);
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++){
            int x=a.top();
            a.pop();
            if(f[x]==0){
                b.push(x);
                f[x]=1;
            }else{
                while(b.top()!=x){
                    num.push(b.top());
                    b.pop();
                }
                num.push(b.top());
                b.pop();
            }
        }
        while(!num.empty()){
            int x=num.front();
            a.push(x);
            num.pop();
        }
        while(!b.empty()){
            ans[b.top()]++;
            a.push(b.top());
            b.pop();
        }
        memset(f,m,sizeof(0));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

