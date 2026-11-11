#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,a[N],cnt,mx;
int c[40];
long long ans;
struct node
{
    int nt0,nt1,ed;
    long long v;
    // int siz;
}t[N*60];
int tot;
/*
void init(int u)
{
    t[u].siz=t[u].ed;
    if(t[u].nt0)init(t[u].nt0);
    if(t[u].nt1)init(t[u].nt1);
    t[u].siz+=t[t[u].nt0].siz+t[t[u].nt1].siz;
}
*/
void dfs(int u,long long nw)
{
    //cout<<u<<' '<<nw<<'\n';
    if(t[u].nt1)
    {
        dfs(t[u].nt1,t[t[u].nt1].v);
    }
    if(cnt>=m)
    {
        return;
    }
    if(t[u].nt0)
    {
        dfs(t[u].nt0,t[t[u].nt0].v);
    }
    if(cnt>=m)
    {
        return;
    }
    if(t[u].ed&&(nw&mx))
    {
        ans&=nw;
        cnt+=t[u].ed;
        //cout<<nw<<"\n";
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    ans=(1<<31)-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int k=0,lk;
        for(int j=30;j>=0;j--)
        {
            //cout<<a[i]<<": "<<j<<"  "<<k<<" "<<t[k].v<<"\n";
            // lk=k;
            if(a[i]&(1<<j))
            {
                c[j]++;
                if(t[k].nt1)
                {
                    k=t[k].nt1;
                }
                else
                {
                    t[k].nt1=++tot;
                    t[t[k].nt1].v=t[k].v+(1<<j);
                    //cout<<t[k].nt1<<" "<<t[t[k].nt1].v<<"\n";
                    k=tot;
                }
            }
            else
            {
                if(t[k].nt0)
                {
                    k=t[k].nt0;
                }
                else
                {
                    t[k].nt0=++tot;
                    t[t[k].nt0].v=t[k].v;
                    //cout<<t[k].nt1<<" "<<t[t[k].nt1].v<<"\n";
                    k=tot;
                }
            }
            //cout<<a[i]<<": "<<j<<"  "<<lk<<" "<<t[lk].v<<"\n";
        }
        t[k].ed++;
    }
    for(int i=31;i>=0;i--)
    {
        if(c[i]>=m)
        {
            mx=(1<<i);
            break;
        }
    }
    dfs(0,ans);
    cout<<ans<<"\n";
    return 0;
}
/*
求你了一定要AC喵
已经无能为力了喵
红紫黑黄的不要喵
芙兰朵露脚香香喵
*/
