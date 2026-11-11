

#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;

int n,m;
int sum[N];
int a[N];
int cnt;
int ma;
int t,tt;
bool cmp(int a,int b)
{
    return a<b;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    m++;
    sort(a+1,a+n+1,cmp);

    queue<int> q;
    q.push(a[1]);
    for(int i=2;i<=n;i++)
    {
        cnt+=q.size()*(a[i]-a[i-1]);

        q.push(i);
        while(cnt>m&&q.size())
        {
            //if(cnt==m+1) cout<<111<<' '<<q.size()<<endl;
            int p=q.front();
            cnt-=(a[i]-a[p]);

            q.pop();
        }


        ma=max(ma,(int)q.size());
        //cout<<ma<<endl;

    }
    cout<<ma<<endl;

    return 0;
}


//315275





//old
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;

int n,m;
int sum[N];
int a[N];
int cnt;
int f;
bool cmp(int a,int b)
{
    return a<b;
}
signed main()
{
    freopen("crystal4.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);

    sort(a+1,a+n+1,cmp);

    for(int i=2;i<=n;i++)
    {
        cout<<a[i]<<' ';
        cnt+=(a[i]-a[i-1])*(i-1);
        if(a[i]==a[i-1]&&a[i-1]!=a[i-2]) f++;

        if(cnt>m)
        {
            cout<<cnt<<' '<<n<<endl;
            cout<<f<<endl;
            cout<<i-1<<endl;
            return 0;
        }


    }

    cout<<n<<endl;

    return 0;
}

*/
