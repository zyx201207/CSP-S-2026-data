#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
};
int nn[100000];
int main()
{
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>nn[i];
        }
        if(n=1)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
    return 0;
}
