#include<bits/stdc++.h>
using namespace std;
long long sum,n,tot=1,c1,c2,w1,w2;
struct node
{
    long long head,tail;
    char had;
};
node a[200005];
void baoli()
{
    string s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i].tail-a[i].head+1;j++)
        {
            s=s+a[i].had;
        }
    }
    for(int i=0,j=s.size()-1;i<=j;i++,j--)
    {
        if(s[i]!=s[j]) sum++;
    }
    cout<<sum;
    return;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        a[i].head=tot;
        tot+=x;
        a[i].tail=tot-1;
        cin>>a[i].had;
    }
    if(tot<=10000000)
    {
        baoli();
        return 0;
    }
    tot-=1;
    c1=0;
    c2=tot+1;
    w2=n;
    //cout<<c1<<" "<<c2<<" "<<tot;
    for(int i=1;i<=n;i++)
    {
        //cout<<c1<<" "<<c2<<endl;
        if(c1>=tot/2)
        {
            cout<<sum;
            return 0;
        }
        c1=c1+a[i].tail-a[i].head+1;
        //cout<<i;
        char f=a[i].had;
        for(int j=w2,vis=1;j>=i&&vis;j--)
        {
            if(tot-c2+1<=c1)
            {
                if(a[j].had!=f)
                {
                    if(c1>=tot-c2+2+a[j].tail-a[j].head)
                    {
                        sum+=c2-a[j].head;
                        //cout<<j<<endl;
                        c2=a[j].head;
                        w2-=1;
                    }
                    else
                    {
                        long long chuli=tot-c2+1;
                        //cout<<j<<endl;
                        sum+=c1-chuli;
                        c2-=c1-chuli;
                        vis=0;
                    }
                }
                else
                {
                   if(c1>=tot-c2+2+a[j].tail-a[j].head)
                    {
                        //cout<<j<<endl;
                        c2=a[j].head;
                        w2-=1;
                    }
                    else
                    {
                        long long chuli=tot-c2+1;
                        //cout<<j<<endl;
                        c2-=c1-chuli;
                        vis=0;
                    }
                }
            }
            else
            {
                    vis=0;
            }
        }
    }
    cout<<sum;
    return 0;
}
