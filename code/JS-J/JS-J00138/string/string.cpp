#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
struct Inter{
    int len;
    char ch;
}a[MAXN],le[MAXN],ri[MAXN];
int n,sum=0,cnt=0,lef=0,rig=0,ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld %c",&a[i].len,&a[i].ch);
        sum+=a[i].len;
    }
    //printf("%lld ",sum);
    int i;
    for(i=1;i<=n;++i){
        if(cnt+a[i].len>=sum/2){
            le[++lef].len=sum/2-cnt;
            le[lef].ch=a[i].ch;
            a[i].len=a[i].len-(sum/2-cnt)-sum%2;
            break;
        }
        le[++lef]=a[i];
        cnt+=a[i].len;
    }
    //for(int j=1;j<=lef;++j)printf("(%lld %c) ",le[j].len,le[j].ch);
    for(i;i<=n;++i){
        ri[++rig]=a[i];
    }
    for(int l=1,r=rig;l<=lef&&r>=1;){
        if(le[l].ch!=ri[r].ch){
            if(le[l].len>ri[r].len)
                ans+=ri[r].len,le[l].len-=ri[r].len,--r;
            else if(le[l].len<ri[r].len)
                ans+=le[l].len,ri[r].len-=le[l].len,++l;
            else 
                ans+=le[l].len,--r,++l;
        }else {
            if(le[l].len>ri[r].len)
                le[l].len-=ri[r].len,--r;
            else if(le[l].len<ri[r].len)
                ri[r].len-=le[l].len,++l;
            else 
                --r,++l;
        }
        if(ri[r].len==0)--r;
        if(le[l].len==0)++l;
    }
    printf("%lld\n",ans);
    return 0;
}