#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
vector<int>arr(N,0);
bool cnt(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    long long maxx=-1;
    long long n=11111111111111;
    for(int i=0;i<a;i++)
    {

        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),cnt);
    for(int i=0;i<a;i++)
    {

        for(int j=i+b-1;j<a;j++)
        {
            if(j-i+1==b)
            {
                for(int k=i;k<j;k++)
                {
                    n&=arr[k];
                }
            }
            maxx=max(maxx,n);
        }
    }
    cout<<maxx;
    return 0;
}
