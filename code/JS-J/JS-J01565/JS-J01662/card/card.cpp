#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool v[300005];
int now[300005];
int top;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        top=0;
        for(int j=i;j<=n;j++){
            if(v[a[j]]){
                int x=0;
                for(int i=1;i<=top;i++){
                    if(x){
                        v[now[i]]=0;
                        now[i]=0;
                    }
                    if(now[i]==a[j]){
                        x=i;
                    }
                }
                top=x;
            }else{
                v[a[j]]=1;
                now[++top]=a[j];
            }
        }
        for(int i=1;i<=m;i++){
            if(v[i]){
                ans[i]++;
                v[i]=0;
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
