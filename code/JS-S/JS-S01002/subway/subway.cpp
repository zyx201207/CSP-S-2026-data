#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    int C,n,m,d,q;
    cin>>C>>n>>m>>d>>q;
    vector<vector<int>>a(m+1);
    vector<map<int,int>>v(n);
    vector<vector<int>>r(n);
    for(int i=1;i<=m;i++)
    {
        int b;
        cin>>b;
        a[i].push_back(b);
    }
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            map<int,int>p;
            int c,d;
            cin>>c>>d;
            v[i][c]=d;
            r[i].push_back(c);
            a[c].push_back(i);
        }
    }
    while(q--)
    {
        vector<long long>ans;
        int c,d;
        cin>>c>>d;
        queue<pair<int,long long>>q;
        q.push({c,a[c][0]});
        bool f=1;
        while(f)
        {
            int ni=q.size();
            for(int k=0;k<ni;k++)
            {
                pair<int,long long>p=q.front();
                int b=p.first;
                long long sum=p.second;
                q.pop();
                if(b==d)
                {
                    ans.push_back(sum);
                    f=0;
                }
                for(int i=1;i<a[b].size();i++) for(int j=0;j<r[a[b][i]].size();j++) q.push({r[a[b][i]][j],sum+v[a[b][i]][b]+v[a[b][i]][r[a[b][i]][j]]});
            }

        }
        int ni=q.size();
        for(int k=0;k<ni;k++)
        {
            pair<int,long long>p=q.front();
            int b=p.first;
            long long sum=p.second;
            q.pop();
            if(b==d)
            {
                ans.push_back(sum);
                f=0;
            }
            for(int i=1;i<a[b].size();i++) for(int j=0;j<r[a[b][i]].size();j++) q.push({r[a[b][i]][j],sum+v[a[b][i]][b]+v[a[b][i]][r[a[b][i]][j]]});
        }
        cout<<ans[0]+a[d][0]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
