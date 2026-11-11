#include<bits/stdc++.h>
using namespace std;
#define int long long
int l[300005];
void mn(vector<int>kk,int m,int n,int fr){
    vector<int>la(m+1,-1);
    vector<int>p(n+1);
    int siz=1;
    for(int i=fr;i<=n;i++){
        int k=kk[i];
        if(la[k]!=-1){
            for(int i=la[k];i<=siz;i++){
                la[p[i]]=-1;
                p[i]=0;
            }
            siz=la[k]-1;
            la[k]=siz;
            siz++;
        }
        else{
            p[siz]=k;
            la[k]=siz;
            siz++;
        }
    }
    for(int i=1;i<=siz;i++){
        l[p[i]]++;
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>pk(n+1);
    for(int i=1;i<=n;i++){
        int zzz;
        cin>>zzz;
        pk[i]=zzz;
    }
    for(int i=1;i<=n;i++){
        mn(pk,m,n,i-1);
    }
    for(int i=1;i<=m;i++){
        cout<<l[i]<<' ';
    }
}