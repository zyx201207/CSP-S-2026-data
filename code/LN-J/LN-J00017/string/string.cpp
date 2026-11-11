#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
ll ls[N],rs[N];
char c[N];
ll spl[2*N][3],spr[2*N][3];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;scanf("%d",&n);
    ll L=0;
    ls[1]=1;
    for(int i=1;i<=n;i++){
        scanf(" %d %c",&a[i],&c[i]);
        L+=a[i];
        rs[i]=L,ls[i+1]=L+1;
    }
    int lp=1,rp=1;
    spl[lp][0]=ls[1];spl[lp][1]=rs[1];
    spr[rp][0]=ls[n];spr[rp][1]=rs[n];
    spl[lp][2]=1;spr[rp][2]=n;
    while(spl[lp][2]<spr[rp][2]){
        if(spl[lp][1]>L-spr[rp][0]+1){
            spl[lp+1][0]=(L-spr[rp][0]+1)+1;
            spl[lp+1][1]=spl[lp][1];
            spl[lp+1][2]=spl[lp][2];
            spl[lp][1]=(L-spr[rp][0]+1);
            lp++;
            spr[rp+1][0]=ls[spr[rp][2]-1];
            spr[rp+1][1]=rs[spr[rp][2]-1];
            spr[rp+1][2]=spr[rp][2]-1;
            rp++;
        }else if(spl[lp][1]<L-spr[rp][0]+1){
            spr[rp+1][0]=spr[rp][0];
            spr[rp+1][1]=(L-spl[lp][1]+1)-1;
            spr[rp+1][2]=spr[rp][2];
            spr[rp][0]=(L-spl[lp][1]+1);
            rp++;
            spl[lp+1][0]=ls[spl[lp][2]+1];
            spl[lp+1][1]=rs[spl[lp][2]+1];
            spl[lp+1][2]=spl[lp][2]+1;
            lp++;
        }else{
            spl[lp+1][0]=ls[spl[lp][2]+1];
            spl[lp+1][1]=rs[spl[lp][2]+1];
            spl[lp+1][2]=spl[lp][2]+1;
            lp++;
            spr[rp+1][0]=ls[spr[rp][2]-1];
            spr[rp+1][1]=rs[spr[rp][2]-1];
            spr[rp+1][2]=spr[rp][2]-1;
            rp++;
        }
    }
    ll ans=0;
    for(int i=1;i<lp&&i<rp;i++){
        if(c[spl[i][2]]!=c[spr[i][2]]){
            ans+=(spl[i][1]-spl[i][0]+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
