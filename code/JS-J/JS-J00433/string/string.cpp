#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int a;
    char s;
}p[100001];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i].a>>p[i].s;
    if(n==1)cout<<0;
    else
    {
        int l=1,r=n;
        long long ans=0;
        while(l<r)
        {
            if(p[l].s!=p[r].s)
            {
                int re=min(p[l].a,p[r].a);
                ans+=re;
                p[l].a-=re;
                p[r].a-=re;
                if(p[l].a==0)l++;
                if(p[r].a==0)r--;
            }
            else
            {
                int re=min(p[l].a,p[r].a);
                p[l].a-=re;
                p[r].a-=re;
                if(p[l].a==0)l++;
                if(p[r].a==0)r--;
            }
        }
        cout<<ans;
    }
    return 0;
}
