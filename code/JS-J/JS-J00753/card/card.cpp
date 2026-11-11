#include<iostream>
#include<vector>
using namespace std;
void output(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
void T(vector<int> &a,vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==-1)    continue;
        a[v[i]-1]++;
    }
}
void f(vector<int> &v,vector<int> &v1,int s,vector<int> &a)
{
    for(int i=s;i<v.size();i++)
    {
        bool ok=true;
        for(int j=0;j<v1.size();j++)
        {
            if(ok==false)   v[j]==-1;
            if(v1[j]==v[i])
            {
                v1[j]=-1;
                ok=false;
            }
        }
        v1.push_back(v1[i]);
    }
    T(a,v1);
}
int main()
{
    freopen("card.in","r",stdin);
    int n,m; cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    vector<int> a(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int> Q;
        f(v,Q,i,a);
    }
    freopen("card.out","w",stdout);
    output(a);
    return 0;
}
