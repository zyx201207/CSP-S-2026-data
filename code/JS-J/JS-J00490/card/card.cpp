#include<bits/stdc++.h>
#define int long long
#define N 200007 
using namespace std;
int n,ans=1,m,mx;
map<int,int> q;
int a[N],c[N]={0};
int b[N]={-1};
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    if(m==1){
        if(n%2==1)cout<<n/2+1;
        else cout<<n/2;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[n])ans++; 
        }
        if(a[n]==1) cout<<n<<ans;
        else cout<<ans<<n;
    }else{
        for(int j=1;j<=n;j++)
        for(int k=j;k<=n;k++){
            if(!q.find(a[k])->second) q.insert(a[k],k);
            else {
                for(int i=1;i<=q.size();i++){
                   // int v=q[i].second,u=q[i].first;
                    if(q[i]<=k&&q[i]>q.find(a[k])->first) q.erase(i);
                }
                q.insert(a[k],k);
                for(int i=1;i<=q.size();i++){
                    c[q[i]]++;
                }
            }
        }
        for(int i=1;i<=q.size();i++){
            cout<<c[i];
        }
    }
    return 0;  
}