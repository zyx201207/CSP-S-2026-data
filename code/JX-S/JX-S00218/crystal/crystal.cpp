#include<bits/stdc++.h>
using namespace std;
long long  n,m,a[500010],ans=0,add=0,L=1,R,top,t,las=1,h[50010]={0},ss[50010]={0};
//map<long long,long long> num;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    //cin>>n>>m;
    h[0]=0;ss[0]=0;
    for(int i=1;i<=n;i++){
            //cin>>a[i];
        scanf("%lld",&a[i]);
        //num[a[i]]++;
    }
    sort(a+1,a+1+n);
    //t=unique(a+1,a+1+n)-a;
    for(int i=1;i<=n;i++){
        h[i]=h[i-1]+a[i];//*1LL*num[a[i]];
        ss[i]=ss[i-1]+1;//num[a[i]];
    }

    R=t;
    while(L<R&&add!=m){
        long long i=L,lmid=las+(L*1LL-las)/2,mmid=L+(R-L)/2ll,rmid=R+(t-R)/2ll;//,s=0;
        top=a[R];
       // while(add<=m&&i<=R){
        //    add+=(top-a[i])*num[a[i]];
       //     i++;
        //}
        //for(int j=L;j<=R;j++)s+=num[a[j]];
        add=(ss[R]*1LL-ss[L-1])*top-(h[R]*1LL-h[L-1]);
        //add=(s[1]-s[1])*top-(h[1]*1LL-h[1]);
        if(add<m){
            long long radd=(ss[rmid]-ss[L-1])*1LL*a[rmid]-(h[rmid]-h[L-1]);
            long long ladd=(ss[R]-ss[lmid-1])*1LL*a[R]-(h[R]-h[lmid-1]);;
            if(radd>ladd)las=L,L=lmid;
            else if(radd<ladd)t=R,R=rmid;
            else if(radd==ladd){
                if((ss[rmid]-ss[L-1])>(ss[R]-ss[lmid-1]))t=R,R=rmid;
                else las=L,L=lmid;
            }
        }
        else if(add>m){
            long long radd=(ss[R]-ss[mmid])*1LL*a[R]-(h[R]-h[mmid]);
            long long ladd=(ss[mmid]-ss[L-1])*1LL*a[mmid]-(h[mmid]-h[L-1]);;
            if(radd>ladd)t=R,R=mmid;
            else if(radd<ladd)las=L,L=mmid;
            else if(radd==ladd){
                if((ss[R]-ss[mmid-1])>(ss[mmid]-ss[L-1]))las=L,L=mmid;
                else t=R,R=mmid;
            }
        }
        else ans=max(ans,ss[R]-ss[L]);
    }
    printf("%lld",ans);
    return 0;
}
