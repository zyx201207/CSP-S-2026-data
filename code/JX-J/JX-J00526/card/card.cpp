#include<bits/stdc++.h>
using namespace std;
int n,m,a[500003],b[300003];
map<int,bool>k;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            auto iter=k.find(a[j]);
            if(iter==k.end())
            {
                k.insert({a[j],true});
            }
            else
            {
                k.erase(iter,k.end());
                k.insert({a[j],true});
            }
        }
        for(auto iter=k.begin();iter!=k.end();++iter)
            ++b[iter->first];
        k.clear();
    }
    for(int i=1;i<=m;++i)
        printf("%d ",b[i]);
    return 0;
}
