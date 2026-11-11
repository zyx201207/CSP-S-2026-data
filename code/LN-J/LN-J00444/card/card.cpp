#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],tmp,ans[500005];
int f[300005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)f[j]=0;
        stack<int>s;
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                s.push(a[j]);
                f[a[j]]=1;
            }
            else{
                while(s.top()!=a[j]){
                    s.pop();
                    f[a[j]]--;
                    if(f[a[j]]<0)f[a[j]]=0;
                }
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
