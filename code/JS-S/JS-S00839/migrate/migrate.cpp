#include<iostream>

using namespace std;

int c,t,n,d;
long long pos[100070];

int find_route(int s,int e,int dep)
{
    if(s==e)return 1;
    int len=999999999,cnt=1;
    for (int i = s+1; i <= e; i++)
    {
        if(pos[i]-pos[s]<=d)
        {
            int len_1=find_route(i,e,dep+1);
            if(len>len_1)len=len_1;
            else if(len==len_1)cnt++;
        }
    }
    if(dep==0)return cnt;
    else return len;
}

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);
    cin>>c>>t;
    for (int i = 0; i < t; i++)
    {
        int ct=0;
        cin>>n>>d;
        for (int j = 1; j <= n; j++)cin>>pos[j];
        for (int j = 1; j <= n; j++)
        {
            for (int k = j+1; k <= n; k++)
            {
                int rt=find_route(j,k,0);
                if(rt==2)ct++;
            }
        }
        cout<<ct<<endl;
    }
    
    return 0;
}