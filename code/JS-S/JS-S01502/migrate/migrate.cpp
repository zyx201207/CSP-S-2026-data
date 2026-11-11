#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,x[2000005],rec1[5005],rec2[5005],t[2000005],s[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",x+i);
        int ttt=n;
        for(int i=n;i>=1;i--){
            while(x[ttt]-x[i]>d)
                ttt--;
            t[i]=ttt;
        }
        ttt=1;
        for(int i=1;i<=n;i++){
            while(x[i]-x[ttt]>d)
                ttt++;
            s[i]=ttt;
        }
        if(c==11||c==12){
            long long tmp=x[2]-x[1];
            if(tmp*2<=d&&tmp*3>d)
                printf("%lld\n",n-3);
            else
                puts("0");
        }else if(c==13||c==14){
            for(int i=1;i<=n;i++)
                if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
                    int r=n-t[i-1],l=s[i+2]-s[i+1];
                    long long ans=1ll*l*r;
                    r=t[i-1]-t[i-2],l=s[i+1]-1;
                    ans+=1ll*l*r;
                    printf("%lld\n",ans);
                }
        }else if(c<=6){
            long long ans=0;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    int pos=i,len=0,tmp=0,cnt=0;
                    rec1[++tmp]=i;
                    while(pos<j){
                        if(pos==t[pos])
                            break;
                        pos=t[pos];
                        rec1[++tmp]=pos;
                    }
                    if(pos==t[pos]&&pos<j)
                        continue;
                    len=tmp;
                    rec1[len]=j;
                    pos=j;
                    rec2[tmp--]=j;
                    while(pos>i){
                        pos=s[pos];
                        rec2[tmp--]=pos;
                    }
                    rec2[1]=i;
                    for(int k=1;k<=len;k++)
                        cnt+=abs(rec1[k]-rec2[k]);
                    if(cnt==1)
                        ans++;
                }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
//2h43min 40pts?
