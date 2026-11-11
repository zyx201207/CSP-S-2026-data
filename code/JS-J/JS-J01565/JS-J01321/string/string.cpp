#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll a[N];
char c[N];
ll S,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>c[i];
        S+=a[i];
    }
    ll l=0,r=S+1;
    ll i=0,j=n+1;//pos - part
    ll is=0,js=0;//sheng yu
    char ni,nj;
    while(l+S%2+1<r)
    {
        if(is==0) i++,is=a[i],ni=c[i];
        if(js==0) j--,js=a[j],nj=c[j];
        ll sol=min(is,js);
        l+=sol;
        r-=sol;
        if(ni!=nj)
        {
            //cout<<l-sol<<" ~ "<<l+sol<<"  </>  "<<r+sol<<" ~ "<<r-sol<<" +"<<sol<<'\n';
            ans+=sol;
        }
        is-=sol;
        js-=sol;
    }
    cout<<ans;
    return 0;
}
/*
g++ string.cpp -std=c++14 -O2 -w -o string
./string
*/


/*
check:
1. a[][]
2. freopen("string.in","r",stdin);
3. freopen("string.out","w",stdout);
4. long long
5. shu ju fan wei
6. //Debug
*/