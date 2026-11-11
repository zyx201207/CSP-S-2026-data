#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=3e5+5,N=5e5+5;
int n,m,a[N];
ll cnt[M]={0};
bool pd[M]={0};
queue<int> q,nq;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool f=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!(a[i]>=a[i-1])) f=1;
    }
    if(f==0){
        int l=1,r=2;
       while(1){
            while(a[r]==a[r-1]&&r<=n) r++;
            cnt[a[l]]+=r-l;
            l=r;
            r++;
            if(l>n) break;
        }
        for(int i=1;i<=m;i++){
            cnt[i]+=cnt[i-1];
            cout<<cnt[i]<<' ';
        }
        return 0;
    }
    for(int j=1;j<=n;j++){
        memset(pd,0,sizeof(pd));
        for(int i=j;i<=n;i++){
            if(pd[a[i]]==0){
                q.push(a[i]);
                pd[a[i]]=1;
            }
            else {
                while(1){
                    int t=q.front();
                    nq.push(t);
                    q.pop();
                    if(t==a[i]){
                        break;
                    }
                }
                while(!q.empty()){
                    int t=q.front();
                    pd[t]=0;
                    q.pop();
                }
                pd[a[i]]=1;
                q.swap(nq);
            }
        }
        for(int i=1;i<=m;i++){
            if(pd[i]==1) cnt[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
