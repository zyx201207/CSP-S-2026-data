#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
    long long k;
    char f;
}G[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,b,c,n,cnt=0,ctt=0,ans=0,n1,n2;
    cin>>n;
    n1=n;
    n2=n;
    for(int i=1;i<=n;i++){
        cin>>G[i].k>>G[i].f;
        cnt+=G[i].k;
    }
    if(cnt%2==0)ctt=cnt/2;
    else{
        ctt=cnt/2+1;
    }
    for(int i=1;i<=n;i++){
        if(n1==0||n1==1)break;
        if(G[i].k>G[n2].k){
            if(G[i].f==G[n2].f){
                G[i].k-=G[n2].k;
                G[n2].k=0;
                n2--;
                n1--;
                i--;
            }
            else{
                G[i].k-=G[n2].k;
                ans+=G[n2].k;
                G[n2].k=0;
                n2--;
                n1--;
                i--;
            }
        }
        else if(G[i].k==G[n2].k){
            if(G[i].f==G[n2].f){
                G[i].k-=G[n2].k;
                G[n2].k=0;
                n2--;
                n1-=2;
            }
            else{
                G[i].k-=G[n2].k;
                ans+=G[n2].k;
                G[n2].k=0;
                n2--;
                n1-=2;
            }
        }
        else{
            if(G[i].f==G[n2].f){
                G[n2].k-=G[i].k;
                G[i].k=0;
                n1--;
            }
            else{
                G[n2].k-=G[i].k;
                ans+=G[i].k;
                G[i].k=0;
                n1--;
            }
        }
    }
    cout<<ans;
    return 0;
}
