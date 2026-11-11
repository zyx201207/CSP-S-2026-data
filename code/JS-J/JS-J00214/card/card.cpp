#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int c[500005],top=0;
int cnt[500005];
bool b[500005];
int pc[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++){
        top=0;
        memset(b,false,sizeof b);
        memset(pc,0,sizeof pc);
        for(int j=i;j<=n;j++){
            c[++top]=a[j];
            if(b[a[j]]){
                int x=pc[a[j]];
                for(int k=x+1;k<top;k++)b[c[k]]=false;
                top=x;
            }else{
                b[a[j]]=true;
                pc[a[j]]=top;
            }
        }
        for(int j=1;j<=top;j++)cnt[c[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
