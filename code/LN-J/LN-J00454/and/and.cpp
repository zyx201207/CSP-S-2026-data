#include <bits/stdc++.h>
using namespace std;
long long a,b,c[999999],maxx;
bool cmp(long long a,long long b){
    return a>b;
    }
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;++i){
        cin>>c[i];
    }
    sort(c+1,c+a+1,cmp);
    maxx=c[1];
    for(int i=2;i<=b;++i){
        maxx&=c[i];
    }
    cout<<maxx;
    return 0;
}
