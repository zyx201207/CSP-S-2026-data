#include<bits/stdc++.h>
using namespace std;
struct str
{
    long long a;
    char c;
};
str b[200001],p[200001];
int tot=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i].a>>b[i].c;
        if(i!=1&&b[i].c==b[i-1].c)
            p[tot].a+=b[i].a;
        else
        {
            p[++tot].a=b[i].a;
            p[tot].c=b[i].c;
        }
    }
    long long ans=0;
    for(int j=1,k=tot;j<k;)
    {
        int temp=min(p[j].a,p[k].a);
        if(p[j].c!=p[k].c)
        {
            ans+=temp;
            p[j].a-=temp;
            p[k].a-=temp;
            if(!p[j].a) j++;
            if(!p[k].a) k--;
        }
        else
        {
            p[j].a-=temp;
            p[k].a-=temp;
            if(!p[j].a) j++;
            if(!p[k].a) k--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
