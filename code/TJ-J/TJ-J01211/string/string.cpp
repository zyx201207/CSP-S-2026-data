#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int n,sum;
bool flag;
struct str{
    int sizee;
    char x;
}a[N],m;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].sizee;
        cin>>a[i].x;
    }
    int i=1;
    int j=n;
    if(a[i].sizee>=a[j].sizee)
    {
        flag=0;
        if(a[i].x!=a[j].x){
            sum+=min(a[i].sizee,a[j].sizee);
        }
        m.sizee=abs(a[i].sizee-a[j].sizee);
        m.x=a[i].x;
    }
    else
    {
        flag=1;
        if(a[i].x!=a[j].x){
            sum+=min(a[i].sizee,a[j].sizee);
        }
        m.sizee=abs(a[i].sizee-a[j].sizee);
        m.x=a[j].x;
    }
    if(flag)
    {
        j--;
    }
    else{
        i++;
    }
    while(i!=j)
    {
        int s=min(i,j);
        if(m.sizee==0)
        {
            if(m.x!=a[s].x)
            {
                sum+=a[s].sizee;
            }
            flag=1;
        }
        else if(m.sizee>=a[s].sizee)
        {
            flag=0;
            if(a[s].x!=m.x){
                sum+=min(a[s].sizee,m.sizee);
            }
            m.sizee=abs(a[s].sizee-m.sizee);
        }
        else
        {
            flag=1;
            if(a[s].x!=m.x){
                sum+=min(a[s].sizee,m.sizee);
            }
            m.sizee=abs(a[s].sizee-m.sizee);
            m.x=a[s].x;
        }
        if(flag)
        {
            j--;
        }
        else{
            i++;
        }
    }
    cout<<sum;
    return 0;
}
