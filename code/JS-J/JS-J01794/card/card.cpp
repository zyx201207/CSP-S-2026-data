#include <bits/stdc++.h>
using namespace std;
int a[300005],cnt[300005],ans;
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ans=0;
        for(int j=i;j<=m;j++){
            if(cnt[a[j]]==2){
                while(q.front()!=a[j]){
                    q.pop();
                }
            }
            q.push(a[j]);
            cnt[a[j]]++;
        }
        while(!q.empty()){
            if(q.front()==i){
                ans++;
                break;
            }
        }
        cout<<ans;
    }

    return 0;
}
