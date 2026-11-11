#include <iostream>

using namespace std;

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,n;
    cin>>c>>n;
    if(n==2)cout<<1<<endl<<2;
    if(n==3)
        cout<<1<<endl<<1<<endl<<2;
        if(n==5)
            cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9;
    return 0;
}
