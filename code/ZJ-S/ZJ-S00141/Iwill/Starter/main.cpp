#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iny signed long long
constexpr int maxn=2e6+13;
constexpr int maxm=2e3+13;

int c,t;
int n;
ll d;
ll x[maxn];
int R[maxn],L[maxn];
void build()
{
    for(int i=1,j=1; i<=n; ++i)
    {
        while(j+1<=n&&x[j+1]-x[i]<=d)
        {
            ++j;
        }
        R[i]=j;
    }
    for(int i=n,j=n; i>=1; --i)
    {
        while(j-1>=1&&x[i]-x[j-1]<=d)
        {
            --j;
        }
        L[i]=j;
    }
}
int to[maxn];
int dis[maxn];
int cnt[maxn];
void sol_small()
{
    ll ans=0;
    for(int st=1; st<=n; ++st)
    {
        for(int i=st; i<=n; ++i)
        {
            dis[i]=1e9;
        }
        dis[st]=0;
        cnt[st]=1;
        for(int i=st; i<=n; ++i)
        {
            for(int j=i+1; j<=R[i]; ++j)
            {
                if(dis[j]>dis[i]+1)
                {
                    dis[j]=dis[i]+1;
                    cnt[j]=cnt[i];
                }
                else if(dis[j]==dis[i]+1)
                {
                    cnt[j]+=cnt[i];
                    if(cnt[j]>2)
                    {
                        cnt[j]=3;
                    }
                }
            }
        }
        for(int i=st; i<=n; ++i)
        {
            if(cnt[i]==2)
            {
                ++ans;
            }
            //printf("%d ",cnt[i]);
        }
        //printf("\n");
    }
    printf("%lld\n",ans);
}
void sol_A()
{
    for(int i=1; i<=n; ++i)
    {
        to[i]=0;
        cnt[i]=0;
    }
    ll ans=0;
    to[1]=1;
    {
        int nowR=1;
        while(1)
        {
            int nxt=R[nowR];
            if(nxt==nowR)
            {
                break;
            }
            for(int i=nowR+1; i<=nxt; ++i)
            {
                to[i]=nxt;
            }
            nowR=nxt;
        }
    }
    int len=R[1]-1;
    cnt[len]=1;

    for(int i=2; i<=n; i=to[i]+1)
    {
        for(int j=len; j>=1; --j)
        {
            cnt[j]=cnt[j+1]+cnt[j];
            if(cnt[j]>2)
            {
                cnt[j]=3;
            }
        }
        for(int j=i; to[j]&&to[j]==to[i]&&j<=n; ++j)
        {
            if(cnt[j-i+1]==2)
            {
                ans+=n-j+1;
            }
        }
        if(!to[i])
        {
            break;
        }
    }
    printf("%lld\n",ans);

}
void sol_B()
{
    ll ans=0;
    for(int st=1; st<=n; ++st)
    {
        int to=R[st];
        if(to==n)
        {
            continue;
        }
        int L_=to+1,R_=0;
        if(to-1>st)
        {
            R_=R[to-1];
        }
        if(to-2>st)
        {
            L_=max(L_,R[to-2]+1);
        }
        ans+=max(0,R_-L_+1);
    }
    printf("%lld\n",ans);
}
void sol_C()
{
    ll ans=0;
    for(int l_=1; l_<=n;)
    {
        int r_=l_+1;
        while(r_<=n&&x[r_]-x[r_-1]<=d)
        {
            ++r_;
        }
        for(int st=l_; st<r_; ++st)
        {
            int nowR=st;
            int cnt1=1,cnt2=0,cnt3=0;//倒数第几个的cnt
            while(nowR!=r_-1)
            {
                if(cnt1>2)
                {
                    break;
                }
                int tmp1=0,tmp2=0,tmp3=0;
                //cnt1
                if(nowR>1)
                {
                    int R_=R[nowR],L_=max(nowR+1,R[nowR-1]+1);
                    if(cnt1==2)
                    {
                        ans+=max(0,R_-L_+1);
                    }
                }
                //cnt1+cnt2
                if(nowR>2)
                {
                    int R_=R[nowR-1],L_=max(nowR+1,R[nowR-2]+1);
                    if(cnt1+cnt2==2)
                    {
                        ans+=max(0,R_-L_+1);
                    }
                }
                //cnt1+cnt2+cnt3
                if(nowR>3)
                {
                    int R_=R[nowR-2],L_=nowR+1;
                    if(cnt1+cnt2+cnt3==2)
                    {
                        ans+=max(0,R_-L_+1);
                    }
                }
                int to=R[nowR];
                //cnt1
                {
                    int RR=R[nowR];
                    if(to>nowR&&to<=RR)
                    {
                        tmp1+=cnt1;
                    }
                    if(to-1>nowR&&to-1<=RR)
                    {
                        tmp2+=cnt1;
                    }
                    if(to-2>nowR&&to-2<=RR)
                    {
                        tmp3+=cnt1;
                    }
                }
                //cnt2
                if(nowR>1)
                {
                    int RR=R[nowR-1];
                    if(to>nowR&&to<=RR)
                    {
                        tmp1+=cnt2;
                    }
                    if(to-1>nowR&&to-1<=RR)
                    {
                        tmp2+=cnt2;
                    }
                    if(to-2>nowR&&to-2<=RR)
                    {
                        tmp3+=cnt2;
                    }
                }
                //cnt3
                if(nowR>2)
                {
                    int RR=R[nowR-2];
                    if(to>nowR&&to<=RR)
                    {
                        tmp1+=cnt3;
                    }
                    if(to-1>nowR&&to-1<=RR)
                    {
                        tmp2+=cnt3;
                    }
                    if(to-2>nowR&&to-2<=RR)
                    {
                        tmp3+=cnt3;
                    }
                }
                nowR=to;
                cnt1=min(tmp1,3),cnt2=min(tmp2,3),cnt3=min(tmp3,3);

            }
        }
        l_=r_;
    }
    printf("%lld\n",ans);
}
int jump[maxn];
void sol_D()
{
    jump[n]=n;
    for(int i=n-1; i>=1; --i)
    {
        jump[i]=i;
        if(R[i]==i+1)
        {
            jump[i]=jump[i+1];
        }
    }
    ll ans=0;
    for(int l_=1; l_<=n;)
    {
        int r_=l_+1;
        while(r_<=n&&x[r_]-x[r_-1]<=d)
        {
            ++r_;
        }
        for(int st=l_; st<r_; ++st)
        {
            int nowR=st;
            int cnt1=1,cnt2=0,cnt3=0;//倒数第几个的cnt
            while(nowR!=r_-1)
            {
                if(cnt1>2)
                {
                    break;
                }
                if(jump[nowR]!=nowR)
                {
                    int to=R[nowR];
                    int tmp1=0;
                    {
                        int RR=R[nowR];
                        if(to>nowR&&to<=RR)
                        {
                            tmp1+=cnt1;
                        }
                    }
                    //cnt2
                    if(nowR>1)
                    {
                        int RR=R[nowR-1];
                        if(to>nowR&&to<=RR)
                        {
                            tmp1+=cnt2;
                        }
                    }
                    //cnt3
                    if(nowR>2)
                    {
                        int RR=R[nowR-2];
                        if(to>nowR&&to<=RR)
                        {
                            tmp1+=cnt3;
                        }
                    }
                    if(tmp1>2)
                    {
                        tmp1=3;
                    }
                    if(tmp1==2)
                    {
                        ans+=jump[nowR]-nowR;
                    }

                    cnt1=tmp1,cnt2=0,cnt3=0;
                    nowR=jump[nowR];
                }
                if(cnt1>2)
                {
                    break;
                }
                int tmp1=0,tmp2=0,tmp3=0;
                //cnt1
                if(nowR>1)
                {
                    int R_=R[nowR],L_=max(nowR+1,R[nowR-1]+1);
                    if(cnt1==2)
                    {
                        ans+=max(0,R_-L_+1);
                    }
                }
                //cnt1+cnt2
                if(nowR>2)
                {
                    int R_=R[nowR-1],L_=max(nowR+1,R[nowR-2]+1);
                    if(cnt1+cnt2==2)
                    {
                        ans+=max(0,R_-L_+1);
                    }
                }
                //cnt1+cnt2+cnt3
                if(nowR>3)
                {
                    int R_=R[nowR-2],L_=nowR+1;
                    if(cnt1+cnt2+cnt3==2)
                    {
                        ans+=max(0,R_-L_+1);
                    }
                }
                int to=R[nowR];
                //cnt1
                {
                    int RR=R[nowR];
                    if(to>nowR&&to<=RR)
                    {
                        tmp1+=cnt1;
                    }
                    if(to-1>nowR&&to-1<=RR)
                    {
                        tmp2+=cnt1;
                    }
                    if(to-2>nowR&&to-2<=RR)
                    {
                        tmp3+=cnt1;
                    }
                }
                //cnt2
                if(nowR>1)
                {
                    int RR=R[nowR-1];
                    if(to>nowR&&to<=RR)
                    {
                        tmp1+=cnt2;
                    }
                    if(to-1>nowR&&to-1<=RR)
                    {
                        tmp2+=cnt2;
                    }
                    if(to-2>nowR&&to-2<=RR)
                    {
                        tmp3+=cnt2;
                    }
                }
                //cnt3
                if(nowR>2)
                {
                    int RR=R[nowR-2];
                    if(to>nowR&&to<=RR)
                    {
                        tmp1+=cnt3;
                    }
                    if(to-1>nowR&&to-1<=RR)
                    {
                        tmp2+=cnt3;
                    }
                    if(to-2>nowR&&to-2<=RR)
                    {
                        tmp3+=cnt3;
                    }
                }
                nowR=to;
                cnt1=min(tmp1,3),cnt2=min(tmp2,3),cnt3=min(tmp3,3);

            }
        }
        l_=r_;
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%lld",&n,&d);
        for(int i=1; i<=n; ++i)
        {
            scanf("%lld",&x[i]);
        }
        if(n<=2)
        {
            printf("0\n");
            continue;
        }
        //注意x[i]-x[i-1]>d的情况
        //首先可以双指针预处理飞到最远的岛
        //结合倍增求出m。但是很没有未来
        //假如只有两条，必然是其中一个变化但其他不变
        build();
        //好吧我假掉了
        //这样的问题在于不合法的情况可以是变化多次
        //直接最短路记数当暴力
        if(n<=5000)
        {
            sol_small();
            continue;
        }
        //不同开头就是某个前缀状态
        if(c==11||c==12)
        {
            sol_A();
            continue;
        }
        //dis<=2
        //只用判倒数三个dis=1
        if(c==13||c==14)
        {
            sol_B();
            continue;
        }
        //不可达或dis<=10
        //考虑像b一样按距离分层
        //每层只有最后三个是有用的，处理它们的cnt
        if(c>=15&&c<=18)
        {
            sol_C();
            continue;
        }
        //还是太菜了72跑路了
        //救命特殊性质全WA了
        //40跑路了

        //20分钟我回来了 C
        //哦不用调我忘记输出了
        sol_D();
    }

    return 0;
}
