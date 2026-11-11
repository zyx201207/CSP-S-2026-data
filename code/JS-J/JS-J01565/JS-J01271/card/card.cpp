#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],h[M],ans[M];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    stack<int> s;
    for(int i=1;i<=n;i++){
        memset(h,0,sizeof h);
        for(int j=i;j<=n;j++){
            if(h[a[j]]!=0){
                while(!s.empty() && s.top()!=a[j]){
                    h[s.top()]=0;
                    s.pop();
                }
            }
            else s.push(a[j]);
            h[a[j]]=1;
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
