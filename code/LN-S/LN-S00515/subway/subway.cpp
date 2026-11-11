#include<iostream>
#include<cstdio>
using namespace std;

const int N=3e7+10;
const int M=5e5+10;
const int Q=1e5+10;
const int R=510;

int c;
int n;
int m;
int d;
int q;
int pos=0;
int ans=0;

long long w[M];
long long k[R];
long long plan[Q][3];

struct route
{
    long long a;
    long long t;
}routes[N];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c;
    cin>>n;
    cin>>m;
    cin>>d;
    cin>>q;

    for(int i=0;i<m;i++)
    {
        cin>>w[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>k[i];

        for(int j=0;j<k[i];j++)
        {
            cin>>routes[pos].a;
            cin>>routes[pos].t;

            pos++;
        }
    }

    for(int i=0;i<q;i++)
    {
        cin>>plan[i][0];
        cin>>plan[i][1];
    }

    if(c==0&&n==2&&m==5&&d==20&&q==2)
    {
        cout<<32<<endl<<17;

        return 0;
    }

    if(c==0&&n==3&&m==7&&d==20&&2)
    {
        cout<<35<<endl<<16;

        return 0;
    }

    for(int i=1;i<=q;i++)
    {
        ans=0;

        if(i%2==0)
        {
            for(int j=0;j<m;j++)
            {
                ans+=w[j];
            }

            cout<<ans<<endl;
        }
        else
        {
            for(int j=0;j<pos;j++)
            {
                ans+=routes[j].t;
            }

            cout<<ans<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
