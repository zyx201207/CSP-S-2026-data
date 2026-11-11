#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int bi[N][50],sum[50],ans[50];
int a[N];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int flag=33;
    for(int i=1;i<=n;i++){
        bitset <32> b=a[i];
        for(int j=0;j<=32;j++){
            bi[i][32-j]=b[j];
            sum[32-j]+=bi[i][32-j];
            if(sum[32-j]>=m)
                flag=min(flag,32-j);
        }
    }
    ans[flag]=1;
    queue <int> q;
    for(int i=1;i<=n;i++)
        if(bi[i][flag])
            q.push(i);
    for(int i=flag+1;i<=32;i++){
        int x=q.size(),j=1,cnt=0;
        while(!q.empty()&&j<=x){
            int u=q.front();
            q.pop();
            if(bi[u][i]){
                cnt++;
                q.push(u);
            }
            j++;
        }
        if(cnt>=m)
            ans[i]=1;
    }
    int tot=0;
    for(int i=0;i<=32;i++){
        tot*=2;
        tot+=ans[i];
    }
    cout<<tot;
    return 0;
}
