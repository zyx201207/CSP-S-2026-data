#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005],pd[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(pd,0,sizeof(pd));
        for(int j=i;j<=n;j++){
            if(pd[a[j]]){
                for(int k=1;k<=m;k++){
                    if(pd[k]<j&&pd[k]>pd[a[j]]){
                        pd[k]=0;
                    }
                }
                //for(int k=1;k<=m;k++){
                //    cout<<pd[k]<<" ";
                //}cout<<endl;
                pd[a[j]]=j;
            }
            else{
                pd[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            //cout<<pd[j]<<" ";
            if(pd[j]>0){
                ans[j]++;
            }
        }
        //cout<<endl;
    }
    for(int j=1;j<=m;j++){
        cout<<ans[j]<<" ";
    }cout<<endl;
    return 0;
}
