#include <iostream>
#include <cstring>
using namespace std;
long long n,m,a[500500],ans[300300],num[500500],last[300300],pos;
bool vis[300300];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            memset(vis,false,sizeof vis);
            memset(last,0,sizeof last);
            memset(num,0,sizeof num);
            pos=0;
            if (vis[a[j]]==false)
               vis[a[j]]=true,last[a[j]]=j,num[++pos]=a[j];
            else{
                for (int k=last[a[j]]+1;k<=j;k++)
                    vis[num[k]]=false,last[num[k]]=0,num[k]=0;
                pos=last[a[j]];
            }
        }
        for (int j=1;j<=pos;j++){
            ans[num[j]]++;
        }
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
