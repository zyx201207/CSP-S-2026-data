#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],b[200005],c[200005],ans[100005],first[200005],dif;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    bool flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flag=0;
    }
    if(flag){
        for(int i=1;i<=n+1;i++){
            if(a[i]!=a[i-1]) ans[a[i-1]]+=(i-1);
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                b[j]=a[j];
            }
            for(int j=1;j<=m;j++){
                first[j]=0;
            }
            for(int j=i;j<=n;j++){
                if(first[b[j]]==0){
                    first[b[j]]=j;
                }
                else{
                    for(int k=first[b[j]];k<j;k++){
                        first[b[k]]=0;
                        b[k]=0;
                    }
                    first[b[j]]=j;
                }
            }
            //cout<<"me:";
            for(int j=i;j<=n;j++){
                //cout<<b[j]<<" ";
                ans[b[j]]++;
            }
            //cout<<endl;
        }
        for(int j=1;j<=m;j++){
            cout<<ans[j]<<" ";
        }
    }
}
