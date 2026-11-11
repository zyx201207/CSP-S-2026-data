#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000004];
long long ans;
long long t[1000004];
void DFS(long long highbit,long long resn){
    if(highbit==-1){
        return ;
    }
    long long pos=0;
    for(int i=1;i<=resn;i++){
        if(a[i]>=(1LL<<highbit)){
            a[i]-=(1LL<<highbit);
            t[++pos]=a[i];
        }
    }
    if(pos<m){
        DFS(highbit-1,resn);
    }else{
        for(int i=1;i<=pos;i++){
            a[i]=t[i];
        }
        ans+=(1LL<<highbit);
        DFS(highbit-1,pos);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    DFS(31,n);
    cout<<ans;
    return 0;
}
