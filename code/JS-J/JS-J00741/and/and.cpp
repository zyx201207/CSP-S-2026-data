#include<bits/stdc++.h>
using namespace std;
long long n,m,c[209178],r[33],r1,r2,s,s1,s2=33,c2[209178],z1=1,sum,sum2;
int ry(int x,int y)
{

    while(y-1)
    {
        x=x/2;
        y--;
    }
    return x%2;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<n;i++)
    {
        cin >> c[i];
    }
    sort(c,c+n);

    s=c[n-1];
    while(s)
    {

        s=s/2;
        r1++;
    }
    for(int k=r1;k>=1;k--)
    {

        for(int i=k;i>=1;i--)
        {

            sum2=0;
            for(int j=n-1;j>=s1;j--)
            {


                if(!ry(c[j],i)||c2[j]==1)
                {
                    break;
                    c2[j]=1;
                    s1=j;
                }
                sum2++;

            }

            if(sum2>=m)
            {
                sum+=pow(2,i);

                k=i;
                break;

            }

        }
    }

    sum2=0;
    for(int j=n-1;j>=s1;j--)
    {


        if(c2[j]==1)
        {
            break;
            c2[j]=1;
            s1=j;
        }
        if(c[j]%2==1)
            sum2++;

        }

        if(sum2>=m)
        {
            sum+=1;




        }


    cout << sum;
    return 0;
}
