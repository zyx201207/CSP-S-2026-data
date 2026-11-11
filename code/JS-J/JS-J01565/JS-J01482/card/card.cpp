#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[j]++;
            if(b[j]==2){
                for(int x=1;x<=m;x++){
                    b[x]=0;
                }
                b[j]=1;
            }
        }
        for(int j=1;j<=m;j++){
            ans[j]+=b[j];
            b[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        if(i!=m){
            cout<<ans[i]<<" ";
        } else {
            cout<<ans[i]<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}