#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        bool t[300005]={0};
        stack<int> s;
        for(int j=i;j<=n;j++){
            if(t[a[j]]==1&&!s.empty()){
                while(s.top()!=a[j]&&!s.empty()){
                    t[s.top()]=0;
                    s.pop();
                }
                if(s.top()==a[j])s.pop();
            }
            s.push(a[j]);
            t[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(t[j]==1)ans[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
