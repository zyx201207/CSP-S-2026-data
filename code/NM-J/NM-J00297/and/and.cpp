#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long maxn,minn;
long long sum1,sum2,ans;
long long A[200005];

int szr(long long x)
{
    long long  pw =1;
    sum1 =0;
    while(x>0)
    {
        int s = x%2;
        sum1 += pw*s;
        pw *= 10;
        x = x/2;

    }
    return sum1;
}

int awy(long long y ,long long z)
{

    long long pww=1;
    ans =0;
    int a=0;
    int b =0;
    while(y >0 && z >0)
    {
        a = y%10;
        b = z%10;
        if(a == b && a== 1 && b ==1)
        {
            ans += pww;
        }

        pww *= 10;
        y = y/10;
        z = z/10;
        //cout << a << " ";
        //cout << b << " ";

        //cout << " ";

    }
    //cout << ans;
    return ans;

}

int rzs(long long p)
{
    long long  pw2 =1;
    int s =0;
    sum2 =0;
    while(p>0)
    {
        s = p%10;
        sum2 += pw2*s;
        pw2 *= 2;
        p = p/10;

    }
    return sum2;
}

/*bool cmp(long long c,long long d)
{
    return c>d;
}*/

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;

    if(m ==1)
    {
        for(int i =1;i<=n;i++)
        {
            long long f;
            cin >> f;
            maxn = max(maxn,f);
        }
        cout << maxn;

    }
    else if(m == 2)
    {
        for(int i =1;i<= n;i++)
        {
            cin >> A[i];
        }
        //sort(A+1,A+n+1,cmp);

        for(int i =1;i<n;i++)
        {
            for(int j =i+1;j<=n;j++)
            {
                //cout << A[i] << " ";
                //cout << A[j] << " ";
                long long amaxn = szr(A[i]);
                long long bmaxn = szr(A[j]);
                long long unfinn = awy(amaxn,bmaxn);
                //cout << unfinn << endl;
                maxn = max(unfinn,maxn);
            }
        }



        cout << rzs(maxn);

    }
    else if (m == n)
    {
        for(int i =1;i<= n;i++)
        {
            cin >> A[i];
        }
        //sort(A+1,A+n+1,cmp);

        long long amaxn = szr(A[1]);
        long long bmaxn = szr(A[2]);
        long long unfinn = awy(amaxn,bmaxn);
        for(int i =3;i<=n;i++)
        {
            long long cmaxn = szr(A[i]);
            unfinn = awy(unfinn,cmaxn);

        }
        cout << rzs(unfinn);
    }



    return 0;
}
