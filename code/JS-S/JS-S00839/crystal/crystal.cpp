#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN=500070;
int n,best=0;
long long m;
long long enr[MAXN];
long long sub[MAXN];

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)cin>>enr[i];
    sort(enr+1,enr+n+1);

    for (int i = 1; i <= n; i++)sub[i]=enr[i]-enr[i-1]; 
    
    long long c_cst=0;
    for (int i = 1, j = 1; i <= n;)
    {
        /*
        int tmp=m,cnt=0;
        while (tmp>=0&&i-cnt>=1)
        {
            cnt++;
            tmp-=enr[i]-enr[i-cnt];
        }
        if(cnt>best)best=cnt;
        */
        while (c_cst<=m&&i<=n)
        {
            i++;
            c_cst+=(i-j)*sub[i];
        }
        if(i-j>best)best=i-j;
        while (c_cst>m)
        {
            c_cst-=enr[i]-enr[j];
            j++;
        }
    }

    cout<<best;

    return 0;
}