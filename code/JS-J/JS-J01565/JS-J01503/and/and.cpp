#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
long long num[int(2e5)+5];
bool used[int(2e5)+5];
int m,k;
void edfs(int pos,int getnum)
{
    if(getnum == k)
    {
        long long ans1 = -1;
        for(int i = 1;i<=pos;i++)
        {
            if(used[i] == 1)
            {
                if(ans1 == -1)
                {
                    ans1 = num[i];
                }
                else
                    ans1 = ans1&num[i];
                if(ans1 == 0)
                    break;
            }
        }
        ans = max(ans,ans1);
        return;
    }
    if(pos>m)
    {
        return;
    }
    used[pos] = 1;
    edfs(pos+1,getnum+1);
    used[pos] = 0;
    edfs(pos+1,getnum);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>k;
    long long maxn = 0;
    memset(used,0,sizeof(used));
    for(int i = 1;i<=m;i++)
    {
        cin>>num[i];
        maxn = max(num[i],maxn);
    }
    if(k == 1)
    {
        cout<<maxn;
        return 0;
    }
    else if(k == m)
    {
        ans = num[1];
        for(int i = 2;i<=m;i++)
        {
            ans = ans&num[i];
            if(ans == 0)
                break;
        }
    }
    else if(k == 2)
    {
        for(int i = 1;i<=m;i++)
        {
            for(int j = i+1;j<=m;j++)
            {
                if(num[i]!=num[j])
                    ans = max(ans,num[i]&num[j]);
            }
        }
    }
    else if(k == m-1)
    {
        long long ans1 = num[2];
        for(int i = 2;i<=m;i++)
        {
            ans1= ans1&num[i];
        }
        ans = max(ans,ans1);
        for(int i = 2;i<=m;i++)
        {
            ans1 = num[1];
            for(int j = 2;j<=m;j++)
            {
                if(i!=j)
                    ans1 = ans1&num[i];
            }
            ans = max(ans,ans1);
        }
    }
    else if(k == 4)
    {
        long long t[10];
        for(int i = 1;i<=m;i++)
        {
            t[num[i]]++;
        }
        if(t[4]>=k)
        {
            cout<<4;
            return 0;
        }
        k-=t[4];
        if(t[3]>=k)
        {
            cout<<3;
        }
        else if(t[2]>=k+t[4])
        {
            cout<<2;
        }
        else if(t[1]>=k)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        return 0;
    }
    else if(m<=2000)
        edfs(1,0);
    else
    {
        sort(num+1,num+1+m);
        if(num[1]<num[2])
        ans = num[m-k+1];
        else
        ans = num[k];
    }
    cout<<ans;
    return 0;
}
