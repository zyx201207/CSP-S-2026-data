#include<bits/stdc++.h>
#define ll long long
ll n,m;
int a,b,c;
int r[100];
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
    }
    a=n;
    b=m;
    c=m;
    cout<<a<<" "<<b<<" "<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
