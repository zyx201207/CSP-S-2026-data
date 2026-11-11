#include<bits/stdc++.h>
using namespace std;
int ef(int s,vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==s) return i;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> v(n),bj(m+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        vector<int> z;
        for(int j=i;j<n;j++)
        {
            cout<<"push"<<v[j]<<endl;
            int lsh=ef(v[j],z);
            if(lsh==-1) z.push_back(v[j]);
            else z.erase(z.begin()+lsh+1,z.end());
            cout<<"than";
            for(int k=0;k<z.size();k++)
            {
                cout<<z[k]<<' ';
            }
            cout<<endl;
        }
        for(int j=0;j<z.size();j++)
        {
            bj[z[j]]++;
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<bj[i]<<' ';
    }
    return 0;
}
