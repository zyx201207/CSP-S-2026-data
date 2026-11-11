#include <bits/stdc++.h>
#include <sys/time.h>
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
const int N=2e6+5;
int main()
{
    freopen("migrate.in","w",stdout);
    timeval tm;
    gettimeofday(&tm,0);
    mt19937 rd((int)1e6*tm.tv_sec+tm.tv_usec);
    int lim=5;
    int n=rd()%lim+1,m=rd()%lim+1;
    cout<<"1 1\n";
    cout<<n<<' '<<m<<'\n';
    for(int i=1,s=0;i<=n;i++)
        s+=rd()%m+1,cout<<s<<' ';
    cout<<'\n';
    return 0;
}