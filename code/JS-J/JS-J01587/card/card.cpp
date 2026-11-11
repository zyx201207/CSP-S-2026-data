#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+5,M=3e5+5;
int c[N],A[N],At[M],LA[M],n,m=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(LA,0,M);
    memset(At,0,M);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        A[i]=i;
        At[c[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(At[c[i]]==1){
            continue;
        }At[c[i]]-=1;
        for(int j=i+1;c[j]!=c[i];j++){
            A[j]-=A[i];
        }A[i]=0;
    }
    for(int i=1;i<=n;i++){
        LA[c[i]]=max(A[i],LA[c[i]]);
    }for(int i=1;i<=m;i++){
        cout<<LA[i]<<" ";
    }return 0;
}
