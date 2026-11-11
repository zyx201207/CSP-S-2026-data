#include<bits/stdc++.h>
using namespace std;
bool mi[3005];
int a[200005],x[200005],sum[3005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++){
        int k=1;
        memset(a,0,sizeof(a));
        memset(mi,0,sizeof(mi));
        for(int j=i;j<=n;j++){
            if(mi[x[j]]==0){
                a[k]=x[j];
                k++;
                mi[x[j]]=true;
            }
            else{
                int f=k-1;
                while(a[f]!=x[j]){
                    mi[a[f]]=0;
                    a[f]=0;
                    f--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            sum[j]+=mi[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
    return 0;
}
