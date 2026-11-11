#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    vector<pair<int,char> >v;
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a>>b;
        v.push_back({sum,b});
        sum+=a;
    }
    int bad=0;
    int l=0,r=v.size()-1;
    for(int i=0;i<sum/2;i++)
    {
        if(i==v[l+1].first)l++;
        if((n-i+1)==v[r-1].first)r--;
        if(v[l].second!=v[r].second)bad++;
    }
    cout<<bad;
    return 0;
}
