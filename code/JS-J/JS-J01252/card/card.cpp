#include<bits/stdc++.h>
using namespace std;
long long ans[300005],pre[500005],pos[300005];
long long a[500005];
long long n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    for(long long i=1;i<=n;i++){
        long long max_back=-1;
        for(int j=n;j>=i;j--){
            if(pre[j]>=i){
                max_back=max(max_back,pre[j]);
            }
        }
        
        for(long long j=max(max_back+1,i);j<=n;j++){
            ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}