#include<bits/stdc++.h>
using namespace std;
long long n,m,ans[300005],a[500005];
bool check[300005];
deque<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(check,0,sizeof(check));
        for(int j=i;j<=n;j++){
            if(check[a[j]]){
                while(1){
                    check[q.front()]=false;
                    q.pop_front();
                    if(q.front()==a[j]){
                        q.pop_front();
                        break;
                    }
                }
            }
            q.push_front(a[j]);
            check[a[j]]=true;
        }
        for(int j=1;j<=m;j++) ans[j]+=check[j];
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
