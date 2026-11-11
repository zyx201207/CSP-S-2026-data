#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005],ans[300005],b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++){
            for(int k=1;k<=cnt;k++){
                if(b[k]==a[j]){
                    cnt--;
                    for(int t=k;t<=j;t++){
                        b[t]=0;
                        cnt--;
                    }
                }
            }
            a[j]=b[cnt+1];
        }
        for(int j=1;j<=cnt;j++){
            ans[b[cnt]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
