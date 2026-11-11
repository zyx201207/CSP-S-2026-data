#include<bits/stdc++.h>
using namespace std;
int arr[1000000];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<n-i<<endl;
    }
    return 0;
}
