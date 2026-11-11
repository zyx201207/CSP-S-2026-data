#include<bits/stdc++.h>
#define int long long
using namespace std;
deque<int> q;
deque<int> l;
int ans[300005],a[500005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(ans,0,sizeof(ans));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        bool is[300005];
            memset(is,0,sizeof(is));

        while(!q.empty()) q.pop_front();
        while(!l.empty()) l.pop_front();
        for(int j=i;j<=n;j++){
            if(!is[a[j]]){
                q.push_back(a[j]);
                is[a[j]]=1;
            }
            else{
                bool get=0;
                for(auto val:q){
                    if(val==a[j]){get=1;}
                    if(get==0) {
                        l.push_back(val);
                        q.pop_front();
                    }
                    if(get==1){
                        q.pop_front();
                    }
                }
                for(int val:l){
                    q.push_front(val);
                }
                q.push_back(a[j]);
            }
            if(q.front()==q.back()){
                q.pop_front();
            }

        }

        for(auto val:q){
            ans[val]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
