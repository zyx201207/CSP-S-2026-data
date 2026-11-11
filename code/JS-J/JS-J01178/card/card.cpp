#include<bits/stdc++.h>
using namespace std;
int n,m;
stack <int> s;
int a[500005];
bool cnt[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            memset(cnt,0,sizeof(cnt));
        for(int j=i;j<=n;j++){
            if(cnt[a[j]]==1){
                while(s.top()!=a[j]){
                    cnt[s.top()]=0;
                    s.pop();
                }
            }else s.push(a[j]),cnt[a[j]]++;
        }
        for(int j=1;j<=m;j++){
            ans[j]+=cnt[j];
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
