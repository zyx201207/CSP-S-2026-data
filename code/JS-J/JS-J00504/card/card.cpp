#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,m,a[N],ans[N];
bool inq[N],ta=1;
stack <int> q,ety;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) ta=0;
    }
    if(ta){
        for(int i=1;i<=n;i++){
            ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++){
        q=ety;
        memset(inq,0,sizeof(inq));
        for(int j=i;j<=n;j++){
            if(inq[a[j]]){
                 while(!q.empty()&&q.top()!=a[j]){
                    inq[q.top()]=0;
                    q.pop();
                }
            }else{
                q.push(a[j]);
                inq[a[j]]=1;
            }
        }
        for(int j=1;j<=m;j++)
            if(inq[j]) ans[j]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
