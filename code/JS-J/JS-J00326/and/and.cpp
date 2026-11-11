#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int num;
    string s="0";
}a[200005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
    }
    for(int i=1;i<=n;i++)
    {
        while(a[i].num!=0)
        {
            a[i].s+=a[i].num%2;
            a[i].num/=2;
        }
    }
    return 0;
}
