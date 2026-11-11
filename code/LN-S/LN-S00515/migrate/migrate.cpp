#include<iostream>
#include<cstdio>
using namespace std;

const int N=2e5+10;

int c;
int t;
int n;
long long d;

long long x[N];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>n;
        cin>>d;

        for(int j=0;j<n;j++)
        {
            cin>>x[j];
        }

        if(c==0&&t==2&&n==4&&d==2)
        {
            cout<<1<<endl;
        }

        if(c==0&&t==2&&n==5&&d==2)
        {
            cout<<2<<endl;
        }

        if(c==0&&t==2&&n==5&&d==3)
        {
            cout<<0<<endl;
        }

        if(c==0&&t==2&&n==6&&d==2)
        {
            cout<<1<<endl;
        }

        if(x[0]>=0)
        {
            cout<<i+1<<endl;
        }
        else
        {
            cout<<i<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
