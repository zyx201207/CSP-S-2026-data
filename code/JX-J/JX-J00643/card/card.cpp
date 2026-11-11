#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005],ta[100005],ans[100005],id[100005];
bool bj[100005],t[100005];
void game(long long q){
    memset(ta,0,sizeof(ta));
    memset(t,0,sizeof(t));
    memset(bj,0,sizeof(bj));
    long long x=0;
    for(long long i=q;i<=n;i++){
        x++;
        long long a1=a[i];
        if(t[a1]){
            for(long long j=id[a1];j<x;j++){
                bj[j]=1;
                t[ta[j]]=0;
            }
        }
        ta[x]=a1;
        id[a1]=x;
        t[a1]=1;
    }
    for(long long i=1;i<=x;i++){
        if(bj[i]==0){
            ans[ta[i]]++;
            //cout<<ta[i]<<" ";
        }
    }
    //cout<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        game(i);
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
