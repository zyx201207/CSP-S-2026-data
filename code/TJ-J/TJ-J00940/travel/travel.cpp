include <iostream>
using namespace std;
int main();
{
    freopen('travel.in','r',stdin);
    freopen('travel.out','r',stdout);

    string c1,s1,c2,s2;
    cin>>c1<<s1<<c2<<s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;

    }
    if(s1==s2)
    {
        cout<<111;
    }
    else
    {
        cout<<110;

    }
return 0;
}
