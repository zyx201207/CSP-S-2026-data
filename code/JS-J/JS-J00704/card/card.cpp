#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int in[300005];
int ans[300005];
int c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    //
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int x=0;
        int c[500005]={0};
        for(int j=i;j<=n;j++){
            if(in[a[j]]==0)x++,c[x]=a[j],in[a[j]]++;
            else{
                int temp=0;
                for(int k=1;k<=n;k++){
                    if(c[k]==a[j]){
                        temp=k;
                        break;
                    }
                }
                for(int k=temp;k<=n;k++){
                    if(in[c[k]]>0)in[c[k]]--;
                    c[k]=0;
                    if(x>0)x--;
                }
                x++,c[x]=a[j];
                in[a[j]]++;
            }
        }
        for(int j=1;j<=m;j++){
            if(in[i]>0)ans[i]++;
            in[i]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
