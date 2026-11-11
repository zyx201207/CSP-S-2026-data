#include<bits/stdc++.h>
using namespace std;
long long ans;
struct node
{
    int l;
    char c;
}
a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l;
        getchar();
        cin>>a[i].c;
        getchar();
    }
    for(int i=1,j=n;i<j;)
    {
        if(a[i].c==a[j].c)
        {
            if(a[i].l>a[j].l)
            {
                a[i].l-=a[j].l;
                j--;
            }
            else if(a[i].l<a[j].l)
            {
                a[j].l-=a[i].l;
                i++;
            }
            else
            {
                i++;
                j--;
            }
        }
        else
        {
            if(a[i].l>a[j].l)
            {
                ans+=a[j].l;
                a[i].l-=a[j].l;
                j--;
            }
            else if(a[i].l<a[j].l)
            {
                ans+=a[i].l;
                a[j].l-=a[i].l;
                i++;
            }
            else
            {
                ans+=a[i].l;
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
