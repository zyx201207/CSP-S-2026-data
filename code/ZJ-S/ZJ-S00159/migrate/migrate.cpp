#include<bits/stdc++.h>
using namespace std;
void main1();
void main2();
void main3();
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        if(c==11||c==12)main2();
        else if(c>=13&&c<=14)main3();
        else main1();
    }
}
constexpr long long MAXN=2e6+10,INF=1e18;
long long a[MAXN];
long long cnt[MAXN];
void main1()
{
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        deque<int>q;
        q.push_back(i);
        int j=i+1;
        long long my_cnt=1;
        cnt[i]=1;
        for(int cen=1;!q.empty();cen++)
        {
            deque<int>q1;
            long long cnt2=0;
            while(j<=n&&a[j]-a[q.back()]<=d)
            {
                q1.push_back(j);
                while(a[j]-a[q.front()]>d)my_cnt-=cnt[q.front()],q.pop_front();
                cnt[j]=my_cnt;
                cnt2+=my_cnt;
                ans+=my_cnt==2;
                j++;
            }
            q.swap(q1);
            swap(cnt2,my_cnt);
        }
    }
    cout<<ans<<'\n';
}
void main2()
{
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    long long ans=0;
    for(int i=1;i<=1;i++)
    {
        deque<int>q;
        q.push_back(i);
        int j=i+1;
        long long my_cnt=1;
        cnt[i]=1;
        for(int cen=1;!q.empty();cen++)
        {
            deque<int>q1;
            long long cnt2=0;
            while(j<=n&&a[j]-a[q.back()]<=d)
            {
                q1.push_back(j);
                while(a[j]-a[q.front()]>d)my_cnt-=cnt[q.front()],q.pop_front();
                cnt[j]=my_cnt;
                cnt2+=my_cnt;
                ans+=my_cnt==2;
                j++;
            }
            q.swap(q1);
            swap(cnt2,my_cnt);
        }
    }
    ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=1ll*(n-i+1)*(cnt[i]==2);
    }
    cout<<ans<<'\n';
}
void main3()
{
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    int cha=(a[n]-a[1])/d+1;
    long long ans=0;
    a[0]=-INF;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(j+1<=n&&a[j+1]<=a[i]+d)j++;
        if(i+1==j)continue;
        else if(i+2==j)
        {
            ans+=lower_bound(a+1,a+n+1,a[j]+d)-a-j-1;
        }
        else 
        {
            ans+=lower_bound(a+1,a+n+1,a[j]+d)-upper_bound(a+1,a+n+1,a[j-2]+d);
        }
    }
    cout<<ans<<'\n';
}