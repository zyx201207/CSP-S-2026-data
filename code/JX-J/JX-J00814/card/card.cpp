#include<iostream>
#include<cstring>
using namespace std;
int n,len,m;
int jl[300005],que[500005],arr[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    memset(jl,-1,sizeof(jl));
    for (int i=0;i<n;i++) cin>>arr[i];
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if (jl[arr[j]]==-1){
                jl[arr[j]]=len;
                que[len]=arr[j];
                len++;
            }
            else{
                for (int k=1+jl[arr[j]];k<len;k++){
                    jl[que[k]]=-1;
                    que[k]=0;
                }
                len=jl[arr[j]]+1;
            }
        }
        for (int j=1;j<=m;j++){
            ans[j]+=(jl[j]!=-1);
        }
        for (int j=0;j<=len;j++) que[j]=0;
        for (int j=0;j<=m;j++) jl[j]=-1;
        len=0;
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
