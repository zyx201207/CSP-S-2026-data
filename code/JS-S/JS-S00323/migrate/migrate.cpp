#include <iostream>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,T,n,L[N],R[N],A[N],B[N],C[N];ll d,x[N],ans;
int calc(int r1,int r2,int r3){
    if(r1==r2 && r2==r3)return 0;
    if(r1-r2>=2)return A[r1]+r2-r3;
    if(r1-r2==1)return B[r1]+r2-r3;
    return C[r2]+r2-r3;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T),L[1]=R[1]=1;
    while(T--){
        scanf("%d%lld",&n,&d),ans=0;
        for(int i=1;i<=n;++i)scanf("%lld",&x[i]);
        for(int i=1;i<=n;++i){
            i!=1?L[i]=L[i-1],R[i]=R[i-1]:L[i]=R[i]=i;
            while(x[i]-x[L[i]]>d)++L[i];
            while(R[i]<n && x[R[i]+1]-x[i]<=d)++R[i];
        }
        for(int i=n;i;--i){
            if(R[i]==i){A[i]=B[i]=C[i]=0;continue;}
            C[i]=calc(R[i],R[i],max(i,R[i-1]));
            B[i]=calc(R[i],max(i,R[i-1]),max(i,R[i-1]));
            A[i]=calc(R[i],max(i,R[i-1]),max(i,R[i-2]));
        }
        for(int i=1,r1,r2,r3;i<=n;++i)ans+=calc(R[i],L[i]-1,L[i]-1);
        printf("%lld\n",ans);
    }
    return 0;
}
/*baoli
int ans=0;
r1=R[i],r2=r3=L[i]-1;
while(true){
    if(r1==r2 && r2==r3)break;
    ans+=r2-r3;
    if(r1-r2>=2){r3=max(r1,R[r1-2]),r2=max(r1,R[r1-1]),r1=R[r1];continue;}
    if(r1-r2==1){r3=r2=max(r1,R[r1-1]),r1=R[r1];continue;}
    r3=max(r2,R[r2-1]),r1=r2=R[r2];
}
return ans;

I'm not sure if it covers all conditions,but it has passed all the examples;
*/