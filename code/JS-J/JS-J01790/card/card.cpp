#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[200005],ans[200005],pre[200005];
bool f=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i&&a[i]<a[i-1]) f=0;
    }
    if(f){
        for(int i=0;i<n;i++){
            while(i<n&&a[i]==a[i+1])
                i++;
            cout<<i+1<<' ';
        }
    }
    else{
        for(int l=0;l<n;l++){
            int len=0;
            for(int i=1;i<=m;i++){
                pre[i]=-1;
            }
            for(int i=l;i<n;i++){
                if(pre[a[i]]==-1){
                    b[len++]=a[i];
                    pre[a[i]]=len-1;
                }
                else{
                    for(int j=pre[a[i]]+1;j<len;j++){
                        pre[b[j]]=-1;
                    }
                    len=pre[a[i]]+1;
                }
            }
            for(int i=0;i<len;i++) ans[b[i]]++;
        }
        for(int i=0;i<m;i++){
            cout<<ans[i+1]<<' ';
        }
    }
    return 0;
}
