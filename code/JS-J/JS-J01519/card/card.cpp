#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],to[300005],cnt[300005]={0};
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<1<<endl;
    }
    for(int i=1;i<=n;i++){
        stack<int>q;
        memset(to,0,sizeof(to));
        for(int j=i;j<=n;j++){
            if(to[a[j]]==0){
                to[a[j]]=1;
                q.push(a[j]);
                //cout<<a[j]<<' '<<to[a[j]]<<endl;
            }
            else{
                to[a[j]]++;
                //cout<<a[j]<<' '<<to[a[j]]<<endl;
                int k=q.top();
                while(k!=a[j]&&!q.empty()){
                    to[k]--;
                    //cout<<k<<' '<<to[k]<<endl;
                    q.pop();
                    k=q.top();
                }
                to[a[j]]--;
                //cout<<a[j]<<' '<<to[a[j]]<<endl;
            }
        }
        while(!q.empty()){
            int k=q.top();
            cnt[k]++;
            q.pop();
            //cout<<k<<' '<<cnt[k]<<endl;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
