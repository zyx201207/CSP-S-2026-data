#include<bits/stdc++.h>
using namespace std;
struct Node
{
    long long x;
    long long id;
    string s;
};
int findse(vector<Node> &v,int i,int s,int e,long long n,long long k)
{
    long long p=n;
    for(int j=v.size()-1;j>=0;j--)
    {
        if(p-k+v[i].x>=p)  e=j;
        if(p-k>=p)  s=j;
    }
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
long long hw(vector<Node> &v,long long n)
{
    long long cnt=1;
    for(int i=1;i<v.size();i++)
        if(v[i].s==v[i-cnt].s)
        {
             v[i-cnt].x=v[i-cnt].x+v[i].x;
             cnt++;
             v[i].x=-1;
        }
    vector<Node> a;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].x==-1)
            continue;
        Node x={v[i].x,0,v[i].s};
        a.push_back(x);
    }
    cnt=0;
    long long point=0;
    for(int i=0;a[i].x<n/2;i++)
    {
        point=point+a[i].x;
        int k=0;
        int s,e; findse(a,i,s,e,n,point);
        for(int j=s;j<=e;j++)
        {
            if(a[j].s==a[i].s)
                continue;
            if(v[j].id-v[j].x<point-v[i].x)
            {
                cnt=cnt+v[j].id-point+v[i].x;
                continue;
            }
            if(v[j].id>point)
            {
                cnt=cnt+v[j].id-point;
                continue;
            }
            cnt=cnt+v[j].x;
        }
    }
    return cnt;
}
int hw1(vector<Node> &v)
{
    string s="";
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].x;j++)
            s=s+v[j].s;
    }
    int cnt=0;
    for(int i=0,j=s.length()-1;i<j;i++,j--)
        if(s[i]!=s[j])
            cnt++;
    return cnt;
}
int main()
{
    freopen("string.in","r",stdin);
    int n; cin>>n;
    vector<Node> v(n);
    long long cnt;
    for(int i=0;i<n;i++)
        cin>>v[i].x>>v[i].s,cnt=cnt+v[i].x,v[i].id=cnt;
    freopen("string.out","w",stdout);
    if(cnt<8000000)
    {
        cout<<hw1(v);
        return 0;
    }
    cout<<hw(v,cnt);
    return 0;
}
