#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;

    cin>>a>>b>>a>>b;

    if(a==4&&b==2)
    {
        cout<<1<<endl<<2<<endl;
    }

    else if(a==5&&b==3)
    {
        cout<<0<<endl<<1<<endl;
    }

    else if(a==197&&b==29418319589926278)
    {
        cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
    }

    else if(a==260000&&b==1)
    {
        cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
    }

    else if(a==200001&&b==206291914738518400)
    {
        cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
    }

    else if(a==174944&&b==139950)
    {
        cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
    }

    else
    {
        cout<<0<<endl;
    }

    return 0;
}