#include<bits/stdc++.h>
using namespace std;
int n,m,t[2000002];
string a[2000002],p;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(p<a[i]) p=a[i];

    }
    cout<<p;
    //for(int i=0;i<n;i++)

	return 0;

}
