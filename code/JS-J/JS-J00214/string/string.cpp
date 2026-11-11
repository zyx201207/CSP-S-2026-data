#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
struct info{
    long long a;
    char c;
}d[200005];
int frontn=1,rear;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i].a>>d[i].c;
    }rear=n;
    while(frontn<rear){
        long long u=min(d[frontn].a,d[rear].a);
        if(d[frontn].c!=d[rear].c)cnt+=u;
        d[frontn].a-=u,d[rear].a-=u;
        if(d[frontn].a==0)frontn++;
        if(d[rear].a==0)rear--;
    }cout<<cnt;
    return 0;
}
