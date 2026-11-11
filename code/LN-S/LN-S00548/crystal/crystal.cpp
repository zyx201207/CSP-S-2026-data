#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,qsize=0,qsum=0,maxm=0,a[500001];
queue<int> q;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(i!=0)
        {
            qsum+=qsize*(a[i]-q.back());
        }
        qsize++;
        q.push(a[i]);
        while(qsum>m)
        {
            q.pop();
            qsum-=(q.back()-q.front());
            qsize--;
        }
        maxm=max(maxm,qsize);
    }
    cout<<maxm;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
