#include<bits/stdc++.h>
using namespace std;
int a[500005];
int tong[300005];
int gct[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(gct,0,sizeof(gct));
        for(int j=i;j<=n;j++){
            if(gct[a[j]]==0){
                gct[a[j]]++;
                tong[a[j]]++;
            }
            else{
                int k=j;
                j=j-1;
                int x=a[j+1];
                for(;;j--){
                    if(a[j]==x) break;
                    else{
                        tong[a[j]]--;
                        gct[a[j]]--;
                    }
                }
                j=k;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<tong[i]<<" ";
    }
    return 0;
}
