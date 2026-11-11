#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int x,y;
};
bool cmp(Node a1,Node a2)
{
    return a1.y>a2.y;
}
int itoa(int x)
{
    int cnt=0;
    while(x>0)  cnt+=x%2,x/=2;
    return cnt;
}
int and1(int x,int y)
{
    queue<int> Q1,Q2;
    while(x>0)  Q1.push(x%2),x/=2;
    while(y>0)  Q2.push(y%2),y/=2;
    int ans=0,point=1;
    while(!Q1.empty()&&!Q2.empty())
    {
        int x=Q1.front(),y=Q2.front();
        Q1.pop(),Q2.pop();
        if(x==y&&x==1)  ans=ans+point;
        point=point*2;
    }
    return ans;
}
int main()
{
    freopen("and.in","r",stdin);
    int n,m; cin>>n>>m;
    vector<Node> v(n);
    for(int i=0;i<n;i++)    cin>>v[i].x;
    for(int i=0;i<n;i++)    v[i].y=itoa(v[i].x);
    sort(v.begin(),v.end(),cmp);
    int ans=v[0].x;
    for(int i=1;i<m;i++)
        ans=and1(ans,v[i].x);
    freopen("and.out","w",stdout);
    cout<<ans;
    return 0;
}
