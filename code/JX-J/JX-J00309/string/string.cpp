#include<bits/stdc++.h>
using namespace std;
struct node
{
    int sl;
    char zf;
}a[200005];
bool cmp(node x,node y)
{
    if(x.zf!=y.zf)
        return x.zf<y.zf;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
    {
        cin>>a[i].sl>>a[i].zf;
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    bool bj=0;
    int js=1,he=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].zf!=a[n-i+1].zf)
        {
            bj=1;
            break;
        }
        if(a[i].zf==a[i-1].zf)
            js++;
    }
    if(js==n)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        cout<<min(a[1].sl,a[2].sl);
        return 0;
    }
    if(bj==1)
    {
        if(n==3)
        {
            cout<<max(a[1].sl,a[3].sl);
            return 0;
        }
    }
    if(bj==0)
    {
        if(n==3)
        {
            cout<<min(a[2].sl,abs(a[3].sl-a[1].sl));
            return 0;
        }
    }
    sort(a+1,a+n+1,cmp);
    bool bj2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].zf==a[i+1].zf)
        {
            bj2=1;
            break;
        }
    }
    if(bj2==0)
    {
        cout<<n-1;
        return 0;
    }
    return 0;
}
