# include <bits/stdc++.h>
using namespace std;
int n,cnt,a[200005];
char c[200005];
long long sum;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];

    }
    int posl=1,posr=n;
    while(posl<posr)
    {
        int minn=min(a[posl],a[posr]);
        a[posl]-=minn;
        a[posr]-=minn;
        if(c[posl]!=c[posr])sum+=minn;
        if(a[posl]==0)posl++;
        if(a[posr]==0)posr--;

    }
    cout<<sum;

    return 0;
}
