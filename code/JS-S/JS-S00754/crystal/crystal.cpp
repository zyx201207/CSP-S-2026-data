/*
freopen!
freopen!
freopen!

long long!
long long!
long long!

pianfen!
*/

// D-VI-HT-VK3601(H)
// D-VII-HT-TigerI
// D-VIII-HT-Pz.55
// D-IX-HT-VPz.57
// D-X-HT-Project.67
// D-XI-HT-Pz.70.120

// D-VI-HT-VK3601(H)
// D-VII-HT-TigerI
// D-VIII-HT-KingTiger
// D-IX-HT-E-75
// D-X-HT-E-100

//crystal.cpp

#include <bits/stdc++.h>

#define MAX_N 500050
#define INF 2000000005

using namespace std;

unsigned long long n, m;
long long a[MAX_N];
unsigned long long d[MAX_N];
unsigned long long ans = 1;

bool CheckA()// Special A (a[i] = i)
{
    unsigned long long i;

    for(i=1;i<=n;++i)
    {
        if(a[i] != i)
            return false;
    }
    return true;
}

bool CheckB()// Special B (a[i]-a[i-1] = a[i-1]-a[i-2])
{
    unsigned long long i;

    for(i=3;i<=n;++i)
    {
        if(a[i]-a[i-1] != a[i-1]-a[i-2])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long i, j;
    unsigned long long sum;

    cin>>n>>m;

    for(i=1;i<=n;++i)
    {
        cin>>a[i];
        d[i] = a[i]-a[i-1];
    }

    sort(a+1, a+1+n);

    if(CheckA() == true)
    {
        for(i=n;i>1;--i)
        {
            unsigned long long t = (a[1]+a[i])*i/2;
            if(t<=m)
            {
                ans = i;
                break;
            }
        }
    }
    else if(CheckB() == true)
    {
        unsigned long long delta = a[2]-a[1];
        for(i=n;i>1;--i)
        {
            unsigned long long t = (1+i)*i/2*delta;
            if(t <= m)
            {
                ans = i;
                break;
            }
        }
    }
    else
    {
        for(i=n;i>1;--i)
        {
            sum = 0;
            for(j=i;j>=1;--j)
            {
                sum += (a[i]-a[j]);
            }
            if(sum <= m)
            {
                ans = i;
                break;
            }
        }
    }

    cout<<ans<<'\n';

    return 0;
}
/*
5 5 
1 2 4 8 9
*/

/*
5 8
-3 -1 2 2 7
*/