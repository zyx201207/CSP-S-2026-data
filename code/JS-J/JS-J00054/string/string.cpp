#include<bits/stdc++.h>
using namespace std;
struct str666
{
    int ges;
    char zim;
}ing[200006];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>ing[i].ges;
        cin>>ing[i].zim;
    }
    int le=1,ri=n;
    while(le<ri)
    {
        if (ing[le].ges<ing[ri].ges)
        {
            if (ing[le].zim!=ing[ri].zim) ans+=ing[le].ges;
            ing[ri].ges-=ing[le].ges;
            le++;
        }
        else if (ing[le].ges>ing[ri].ges)
        {
            if (ing[le].zim!=ing[ri].zim) ans+=ing[ri].ges;
            ing[le].ges-=ing[ri].ges;
            ri--;
        }
        else
        {
            if (ing[le].zim!=ing[ri].zim) ans+=ing[le].ges;
            le++;
            ri--;
        }
    }
    cout<<ans;
    return 0;
}
