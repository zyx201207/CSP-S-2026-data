#include<bits/stdc++.h>
using namespace std;
const int aa=20001;
int c,n,m,d,q;
int c1,c2;
int w[20001];
vector<vector<pair<int,int> > > t;
int k;
pair<int,int> r[2001];
long long shh[20502];
priority_queue<vector<pair<long long,long long> >,greater<pair<long long,long long> >,pair<long long,long long> > sho;
map<pair<int,int>,long long> ss;
pair<long long,long long> pat1[20001][21];
vector<vector<pair<int,int> > > pat2;
int main()
{
    t.resize(501);
    pat2.resize(501);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<20502;i++)
    {
        shh[i]=0x3f3f3f3f3f3f;
    }
    for(int i=0;i<20001;i++)
    {
        for(int j=0;j<20;j++)
        {
            pat1[i][j].second=0x3f3f3f3f3f3f;
        }
        pat1[i][20].first=0;
    }
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>c1;
        w[i]=c1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>k;
        for(int j=0;j<k;j++)
        {
            cin>>c1>>c2;
            pat1[c1][pat1[c1][20].first].first=i;
            pat1[c1][pat1[c1][20].first].second=c2;
            pat2[i].push_back(make_pair(c1,pat1[c1][20].first));
            pat1[c1][20].first++;
            //t[i].push_back(make_pair(c1,c2));
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>c1>>c2;
        r[i].first=c1;
        r[i].second=c2;
    }
    for(int i=0;i<q;i++)
    {
        shh[r[i].first]=0;
        for(int j=0;j<20;j++)
        {
            shh[20000+pat1[r[i].first][j].first]=pat1[r[i].first][j].second;
            sho.push_back(make_pair(pat1[r[i].first][j].second,20000+pat1[r[i].first][j].first));
        }
        while(!sho.empty())
        {
            if(sho.top().second>=20000)
            {
                for(int j=0;j<(int)pat2[sho.top().second-20000].size();j++)
                {
                    if(sho.top().first+pat1[pat2[sho.top().second-20000][j].first][pat2[sho.top().second-20000][j].second].second<shh[pat2[sho.top().second-20000][j].first])
                    {
                        shh[pat2[sho.top().second-20000][j].first]=sho.top().first+pat1[pat2[sho.top().second-20000][j].first][pat2[sho.top().second-20000][j].second].second;
                        sho.push_back(make_pair(sho.top().first+pat1[pat2[sho.top().second-20000][j].first][pat2[sho.top().second-20000][j].second].second,pat2[sho.top().second-20000][j].first));
                    }
                }
                sho.pop();
            }
            else
            {
                for(int j=0;j<20;j++)
                {
                    if(sho.top().first+pat1[sho.top().second][j].second<shh[pat1[sho.top().second][j].first+20000])
                    {
                        shh[pat1[sho.top().second][j].first+20000]=sho.top().first+pat1[sho.top().second][j].second;
                        sho.push_back(make_pair(sho.top().first+pat1[sho.top().second][j].second,pat1[sho.top().second][j].first+20000));
                    }
                }
            }
        }
        cout<<shh[r[i].second]+w[r[i].first]+w[r[i].second]<<"\n";
    }
}