/*#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define fi first
#define se second
const int N=1e5+5;
int a[N];//zhang guan fan wei
pair<pii,char> z[N];//shuzhou
pair<pii,char> l[N];//left -
int lk=1;
pair<pii,char> r[N];//right +
int rk=1;

char c[N];//zimu
int ans;
int main()
{
//    freopen("string.in","r",stdin);
//    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    long long sm=a[1];
    long long presm=1;
    for(int i=1;i<=n;i++)
    {
        z[i]=mp(mp(presm,sm),c[i]);
        presm=sm+1;
        sm+=a[i+1];
    }
    //odd
    if(sum&1)
    {
        long long mid=(sum>>2)+1;
        for(int i=1;i<=n;i++)
        {
            int x=z[i].fi.fi-mid;
            int y=z[i].fi.se-mid;
            if(x<=0&&y<=0) l[lk++]=mp(mp(x,y),c[i]);
            if(x>=0&&y>=0) r[rk++]=mp(mp(x,y),c[i]);
            else
            {
                l[lk++]=mp(mp(1,abs(x)),c[i]);
                r[rk++]=mp(mp(1,y),c[i]);
            }
        }
        reverse(l+1,l+n+1);
        for(int i=1,j=1;i<=mid&&j<=mid;)
        {
            if(l[i].fi.se>r[j].fi.se)
            {
                if(l[i].se==r[j].se) ans+=min(l[i].fi.se,r[i].fi.se);
                j++;
            }
        }
    }




    return 0;
}

3
2 a
2 b
1 c

*/
#include<bits/stdc++.h>
using namespace std;
int a[100005];
char c[100005];
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);




    int n;
    cin>>n;
    while(n--)
    {
        cin>>a[i]>>c[i];
    }
    cout<<0;





    return 0;
}
