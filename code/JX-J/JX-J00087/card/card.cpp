#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int t[N];
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int  i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        stank<int>s;
        for(int j=i;j<=n;j++){
            int u=s.size();
            if(t[a[j]]==1){
                while(s.top()==a[j])s.pop();
                s.pop();
            }
            s.push(a[j]);
            t[a[j]]=1;
        }
        for(auto x:s)ans[s]++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
