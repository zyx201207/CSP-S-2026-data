#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans[200005];
int main(){
   // freopen("card.in","r",stdin);
   // freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        auto b=a;
        for(int j=i;j<=n;j++){
            for(int g=i;g<=j-1;g++){
                if(b[g]==b[j]){
                    for(int l=g;l<j;l++){
                        b[l]=-l;
                    }
                    //cout<<g<<" "<<j<<endl;
                }
            }
        }
        for(int j=i;j<=n;j++){
            //cout<<b[j]<<" ";
            if(b[j]>=0){
                ans[b[j]]++;

            }
        }


    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
