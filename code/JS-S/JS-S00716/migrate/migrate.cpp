#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e2+5;
int c,t,n,rt[N],cnt,mn;
ll d,ans,x[N];
void dfs(int frm,int to,int pos,int step){
    if(pos==to)
        if(step<mn)mn=step,cnt=1;
        else if(step==mn)cnt++;
    if(step>=mn)return;
    for(int i=min(to,rt[pos]);i>pos;i--){
        dfs(frm,to,i,step+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(rt,0,sizeof(rt));
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(x[j]-x[i]<=d)rt[i]=j;
                else break;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                cnt=0,mn=1e9,dfs(i,j,i,0),ans+=(cnt==2);
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
