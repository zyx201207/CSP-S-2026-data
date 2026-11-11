#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int a2[N][31];
int a3[31];
int ns[31];
bool check(int mid)
{
    int w=1,now=mid;
    memset(a3,0,sizeof(a3));
    while(now)
    {
        int g=now%2;
        a3[w]=g;
        now/=2;
        //ns[w]=g;
        w++;
    }
    long long nmax=1<<30;
    for(int i=30; i>=1; i--)
    {
        nmax/=2;
        
        if(mid>nmax*2)
        {
            if(ns[i]<m)
            {
                //cout<<"Kill!"<<'\n';
                return 0;
            }
            break;
        }
        if(ns[i]>0) break;
    }
    
    int have=0;
    for(int i=1; i<=n; i++)
    {
        bool f=1;
        for(int j=30; j>=1; j--)
        {
            /*
            if(a2[i][j]>a3[j])
            {
                cout<<"SPECIAL"<<'\n';
                break;
            }
            */
            if(a2[i][j]<a3[j])
            {
                //cout<<mid<<"-> "<<a[i]<<"-X"<<'\n';
                f=0;
                break;
            }
        }
        have+=f;
    }
    if(have>=m) return 1;
    else return 0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        //get(i,a[i]);
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1; i<=n; i++)
    {
        int w=1,now=a[i];
        while(now)
        {
            int g=now%2;
            a2[i][w]=g;
            now/=2;
            ns[w]+=g;
            w++;
        }
    }
    //for(int i=1; i<=30; i++) cout<<ns[i]<<" ";
    //cout<<'\n';
    int l=0,r=a[1]+1;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        bool ok=check(mid);
        //cout<<mid<<" - "<<ok<<'\n';
        if(ok) l=mid;
        else r=mid;
    }
    cout<<l<<'\n';
    return 0;
}
/*
g++ and.cpp -std=c++14 -O2 -w -o and
./and
*/

/*
5 3
31 3 1 15 7
*/
/*
check:
1. a[][]
2. freopen("and.in","r",stdin);
3. freopen("and.out","w",stdout);
4. long long
5. shu ju fan wei
6. //Debug
*/