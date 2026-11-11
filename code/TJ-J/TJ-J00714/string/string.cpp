#include<iostream>
using namespace std;
struct u
{
    long long cnt;
    char c;
}a[200005];
long long n,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].cnt>>a[i].c;
    }
    int l=1,r=n;
    while(l<r)
    {
        if(a[l].cnt<a[r].cnt)
        {
            if(a[l].c!=a[r].c)ans+=a[l].cnt;
            a[r].cnt-=a[l].cnt;
            l++;
        }
        else if(a[l].cnt==a[r].cnt)
        {
            if(a[l].c!=a[r].c)ans+=a[l].cnt;
            l++,r--;
        }
        else
        {
            if(a[l].c!=a[r].c)ans+=a[r].cnt;
            a[l].cnt-=a[r].cnt;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
