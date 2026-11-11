#include<bits/stdc++.h>
#define ll long long
#define fo1(x,a,b) for(ll x=a;x<=b;x++)
#define fo2(x,a,b) for(ll x=a;x>=b;x--)
#define fo3(x,a,b) for(ll x=a;x<b;x++)
#define fo4(x,a,b) for(ll x=a;x>b;x--)
#define fo5(x,a) for(auto x:a)
#define pb push_back
#define MAXN 500001
#define INF 10003
#define fi first
#define se second
using namespace std;
ll n,m;
ll a[MAXN];

void check()
{

    cin>>n>>m;
    fo1(i,1,n)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);


    ll cnt=0;
    fo1(i,1,n)
    {
        cnt+=abs(a[n]-a[i]);


    }
    if(cnt<=m)
    {
        cout<<n<<"\n";
        return ;
    }
    ll l=1,r=n;
    ll ans=0;
    while(l<=r)
    {

        ll mid=l+(r-l)/2;
        if(abs(a[mid]-a[l])>abs(a[r]-a[mid]))
        {
            l=mid+1;

        }
        else if(abs(a[mid]-a[l])==abs(a[r]-a[mid]))
        {
            ans=mid;
            break;
        }
        else if(abs(a[mid]-a[l])<abs(a[r]-a[mid]))
        {
            r=mid;
            ans=mid;
       }
    }
    ll sum=0;
    ll sum1=0;
    ll ans1=0;
    ll ans2=0;
    ll cj=0;
    ll b=0;
    ll b2=0;
    bool flag=0;


    fo2(i,ans,1)
    {
        if(i==1)
        {

            flag=1;
        }

        if(sum+abs(a[ans]-a[i])<m)
        {
            sum+=abs(a[ans]-a[i]);
            cj=m-sum;
            ans1++;
        }
        else if(sum+abs(a[ans]-a[i])>=m)
        {
            break;
        }
    }
    fo1(i,ans,n)
    {
        if(flag==1)
        {
            if(cj>abs(a[i]-a[ans])*ans1+sum+abs(a[i]-a[ans])*ans2+abs(a[i]-a[ans])+b2)
            {
                b=abs(a[i]-a[ans])*ans2;
                b2+=abs(a[i]-a[ans]);
                sum1=(abs(a[i]-a[ans])*ans1+sum)+b+b2;
                ans2++;
            }
            else
            {

                break;
            }

        }
        else
        {

            if(abs(a[i]-a[ans])*ans2+b2+abs(a[i]-a[ans])<m)
            {
                b2+=abs(a[i]-a[ans]);
                sum1=abs(a[i]-a[ans])*ans2+b2;

                ans2++;
            }
            else if(abs(a[i]-a[ans])*ans2+b2+abs(a[i]-a[ans])>=m)
            {
                break;
            }
        }

    }




        if(flag==0)
        {
            cout<<max(ans1,ans2)<<"\n";
            return ;
        }
        else
        {
            cout<<ans1+ans2<<"\n";
            return ;
        }
    return ;

    }


int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    check();








    return 0;
}
