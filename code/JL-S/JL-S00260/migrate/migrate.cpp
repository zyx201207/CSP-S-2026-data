#include<bits/stdc++.h>
using namespace std;
const int A=1000100;
long long c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
        long long a1,a2,an,n,d;
        cin>>n>>d;
        cin>>a1>>a2;
        for(long long i=3;i<=n;i++)
        {
            cin>>an;
        }
        long long dd=2*d/(a2-a1)-1;
        if(an-a1<=2*d)
        {
            cout<<"0"<<endl;
        }
        else if(dd>=2)
        {

            cout<<(an-a1)/(a2-a1)-dd+1<<endl;
        }
        else
            cout<<"0"<<endl;

    }


    return 0;
}
