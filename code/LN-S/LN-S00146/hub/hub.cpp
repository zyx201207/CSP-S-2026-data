#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    srand(time(NULL));
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int r=rand()%3+1;
        cout<<r<<"\n";
    }
    return 0;
}