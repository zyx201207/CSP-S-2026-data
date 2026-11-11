#include<bits/stdc++.h>
using namespace std;
int ar[200005]={0};

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int mx=*max_element(ar,ar+n);
    if(m==1)
    {
        cout<<mx;
    }
    return 0;
}
