#include<bits/stdc++.h>
using namespace std;
struct ug{
    int val;
    bool b;
    bool b2;
    bool two[32];
}a[200005];
bool ans[29]={false};
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].val;
        a[i].b=true;
        int temp=a[i].val,p=0;
        while(temp)
        {
            a[i].two[p]=temp%2;
            temp/=2;
            p++;
        }
    }
    bool rule=false;
    for(int i=29;i>=0;i--)
    {
        int num=0;
        for(int j=0;j<n;j++)
        {
            if(a[j].b)
            {
                if(a[j].two[i])
                {
                    a[j].b2=true;
                    num++;
                }
            }
        }
        if(num>=m)
        {
            ans[i]=true;
            for(int q=0;q<n;q++)
            {
                if(a[q].b2)
                {
                    a[q].b=true;
                }
                else
                {
                    a[q].b=false;
                }
            }
        }
    }
    int sum=0;
    for(int i=29;i>=0;i--)
    {
        sum*=2;
        if(ans[i])
        {
            sum+=1;
        }
    }
    cout<<sum;
    return 0;
}
